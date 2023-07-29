/*
 * Description: LGMD-Plus
 * File: coliasSence_LGMD.c
 * Author: Qinbing Fu
 * Date: 2019 Aug
*/


#include "coliasSense_LGMD.h"
#include "coliasSense_board.h"
#include "delay.h"
#include <math.h>
#include <arm_math.h>
#include <stdlib.h>


uint16_t Image[3][Image_Height][Image_Width];
int8_t Diff_Image[2][Image_Height][Image_Width];
LGMD_pControlTypedef hLGMD;


uint8_t LGMD_Param_Init(LGMD_pControlTypedef* hLGMD)
{
	float init_on_tau=10;	//ms
	float init_off_tau=10;	//ms
	float interval;
	LGMDstruct_Params *Params=&hLGMD->Model->Params;
	//LGMDstruct_Result *Results=&hLGMD->Model->Results;
	
	Params->Kspi=10;
	Params->Cw=4;
	Params->CdeTde=30;
	Params->Tffi=20;
	Params->Tspi=50;
	Params->clip=0;
	Params->W_on=1;
	Params->W_off=1;
	Params->W_base=0.55;
	Params->Tsp=0.68;
	Params->Tsfa=0.001;
	Params->Bias_on=0.5;
	Params->Bias_off=0.5;
	Params->Ksig=0.6;
	Params->DeltaC=0.01;
	Params->hp_tau=500;	//ms
	Params->lp_ffi=10;	//ms
	Params->lp_on_cent_tau=init_on_tau;	//ms
	Params->lp_off_cent_tau=init_off_tau;	//ms
	Params->lp_on_near_tau=2*init_on_tau;	//ms
	Params->lp_off_near_tau=2*init_off_tau;	//ms
	Params->lp_on_diag_tau=3*init_on_tau;	//ms
	Params->lp_off_diag_tau=3*init_off_tau;	//ms
	
	hLGMD->currentDiffImage=0;
	hLGMD->currentImage=1;
	hLGMD->Enable=1;
	hLGMD->Model=&LGMD;
	hLGMD->processCount=1;
	hLGMD->processCountLast=1;
	hLGMD->status=0;
	hLGMD->processRate=30;
	hLGMD->AGC_enable_period=0;
	
	interval=1000/hLGMD->processRate;
	Params->delay_sfa=Params->hp_tau/(Params->hp_tau+interval);
	Params->delay_ffi=interval/(interval+Params->lp_ffi);
	Params->delay_on_cent=interval/(interval+Params->lp_on_cent_tau);
	Params->delay_on_near=interval/(interval+Params->lp_on_near_tau);
	Params->delay_on_diag=interval/(interval+Params->lp_on_diag_tau);
	Params->delay_off_cent=interval/(interval+Params->lp_off_cent_tau);
	Params->delay_off_near=interval/(interval+Params->lp_off_near_tau);
	Params->delay_off_diag=interval/(interval+Params->lp_off_diag_tau);
	
	printf("LGMD-Plus Params Init Completed......\r\n");
	
	return 0;
}

uint8_t Calc_LGMDs_OutOfChannel(LGMD_pControlTypedef* hLGMD)
{
	uint8_t If_m[3]={2,0,1};
	uint8_t If1_m[3]={1,2,0};
	float sum_ffi=0;
	uint8_t If,If1,i,j;
	int8_t *tmpPixel;
	uint16_t *image_cusorf;	//point to current image
	uint16_t *image_cusorf1;	//point to previous image
	uint16_t run_size,n;
	int16_t tmprst;
	uint8_t fa,fa1;
	uint8_t tffi;
	float dffi;
	float *pre_ffi,*cur_ffi,*Boff,*Bon,*Wb;
	tffi=hLGMD->Model->Params.Tffi;
	run_size=Layer_Width*Layer_Height;
	hLGMD->currentDiffImage=!hLGMD->currentDiffImage;
	pre_ffi=&hLGMD->Model->Results.FFI_out[!hLGMD->currentDiffImage];
	cur_ffi=&hLGMD->Model->Results.FFI_out[hLGMD->currentDiffImage];
	dffi=hLGMD->Model->Params.delay_ffi;
	Boff=&hLGMD->Model->Params.Bias_off;
	Bon=&hLGMD->Model->Params.Bias_on;
	Wb=&hLGMD->Model->Params.W_base;
	image_cusorf=(uint16_t*)(((uint8_t*)&Image[If_m[(*(hLGMD->hFrameCount))%3]][0][0])+1);
	image_cusorf1=(uint16_t*)(((uint8_t*)&Image[If1_m[(*(hLGMD->hFrameCount))%3]][0][0])+1);
	//image_cusorf=&Image[If_m[(*(hLGMD->hFrameCount))%3]][0][0];
	//image_cusorf1=&Image[If1_m[(*(hLGMD->hFrameCount))%3]][0][0];
	tmpPixel =&Diff_Image[hLGMD->currentDiffImage][0][0];
	for (n=0;n<run_size;n++)
	{
		/*******************************************************/
		tmprst=(*image_cusorf-*image_cusorf1)>>9;	//high-pass in photoreceptors
		//tmprst=(*image_cusorf-*image_cusorf1)>>1;
		if(tmprst>127)
			tmprst=127;
		if(tmprst<-127)
			tmprst=-127;
		sum_ffi+=abs(tmprst);
		/*******************************************************/
		*tmpPixel=tmprst;
		tmpPixel++;
		image_cusorf++;
		image_cusorf1++;
	}
	*cur_ffi=sum_ffi/run_size;
	//lowpass filtering
	*cur_ffi=dffi*(*cur_ffi)+(1-dffi)*(*pre_ffi);
	//update bias in OFF channels using FFI
	*Boff=*cur_ffi/tffi;
	*Bon=*cur_ffi/tffi;
	if(*Boff<=*Wb)
		*Boff=*Wb;
	if(*Bon<=*Wb)
		*Bon=*Wb;
	
	//normally about 2 ms to process
	return 0;
}

uint8_t Fast_LGMD(LGMD_pControlTypedef* hLGMD)
{
	//Params & Layers & Pointers Init
	uint8_t tmp_max=0;
	//uint32_t tmp_g=0;
	LGMDstruct_Layer *Layers=&hLGMD->Model->Layers;
	LGMDstruct_Params *Params=&hLGMD->Model->Params;
	LGMDstruct_Result *Results=&hLGMD->Model->Results;
	uint8_t Tg,Kspi,*spike,width,height,cur_image,*pre_on,*pre_off,*cur_on,*cur_off,Cw;
	/*******************************************************************/
	uint8_t *layS,*layG;
	/*******************************************************************/
	uint16_t Ncell,n,on_di,off_di;
	uint16_t cent,near,diag,preCent,preNear,preDiag;
	uint16_t tmpg;
	int8_t *diff,i,j;
	int8_t clip;
	float W_on,W_off,Tsp,Tsf,W_bias_on,W_bias_off,dc,Ksig,diff_smp;
	float s_on,s_off,*mp,*spiF,scale,deltaC;
	float delay_sfa,delay_on_cent,delay_on_near,delay_on_diag,delay_off_cent,delay_off_near,delay_off_diag;
	float *cur_smp,*pre_smp,*cur_lgmd_out,*pre_lgmd_out;
	/*******************************************************************/
	Tg=Params->CdeTde;
	Cw=Params->Cw;
	Kspi=Params->Kspi;
	spike=&Results->SPIKE[0];
	width=Layer_Width;
	height=Layer_Height;
	cur_image=hLGMD->currentDiffImage;
	Ncell=width*height;
	W_on=Params->W_on;
	W_off=Params->W_off;
	clip=Params->clip;
	Tsp=Params->Tsp;
	Tsf=Params->Tsfa;
	W_bias_on=Params->Bias_on;
	W_bias_off=Params->Bias_off;
	Ksig=Params->Ksig;
	delay_sfa=Params->delay_sfa;
	delay_on_cent=Params->delay_on_cent;
	delay_on_near=Params->delay_on_near;
	delay_on_diag=Params->delay_on_diag;
	delay_off_cent=Params->delay_off_cent;
	delay_off_near=Params->delay_off_near;
	delay_off_diag=Params->delay_off_diag;
	cur_smp=&Results->SMP[cur_image];
	pre_smp=&Results->SMP[!cur_image];
	cur_lgmd_out=&Results->LGMD_out[cur_image];
	pre_lgmd_out=&Results->LGMD_out[!cur_image];
	pre_on=&Layers->ON[!cur_image][0][0];
	cur_on=&Layers->ON[cur_image][0][0];
	pre_off=&Layers->OFF[!cur_image][0][0];
	cur_off=&Layers->OFF[cur_image][0][0];
	diff=&Diff_Image[cur_image][0][0];
	layS=&Layers->S[0][0];
	layG=&Layers->G[0][0];
	deltaC=Params->DeltaC;
	mp=&Results->MP;
	spiF=&Results->spiFrequency;
	*mp=0;
	*spiF=0;
	uint8_t curf=(*(hLGMD->hFrameCount))%10;
	/******************************************************************/
	//----------------------------------------------------------------------------------------
	//Visual Neural Network Processing
	for(n=0;n<Ncell;n++)
	{
		if(*diff>=clip)	//ON mechanism
		{
			*cur_on=abs(*diff);
			*cur_off=0;
		}
		else	//OFF mechanism
		{
			*cur_off=abs(*diff);
			*cur_on=0;
		}
		diff++;
		cur_on++;
		cur_off++;
	}
	//Spatiotemporal processing in E, I, S layers
	for(i=1;i<height-1;i++)
	{
		cur_on=&Layers->ON[cur_image][i][0];
		cur_off=&Layers->OFF[cur_image][i][0];
		pre_on=&Layers->ON[!cur_image][i][0];
		pre_off=&Layers->OFF[!cur_image][i][0];
		layS=&Layers->S[i][0];
		for(j=1;j<width-1;j++)
		{
			//convolving delayed excitation in ON channels to form ON inhibition
			cent=*(cur_on+j);
			near=(*(cur_on+j-1)>>2)+(*(cur_on+j+1)>>2)+(*(cur_on+j-width)>>2)+(*(cur_on+j+width)>>2);
			diag=(*(cur_on+j-1-width)>>3)+(*(cur_on+j-1+width)>>3)+(*(cur_on+j+1-width)>>3)+(*(cur_on+j+1+width)>>3);
			preCent=*(pre_on+j);
			preNear=(*(pre_on+j-1)>>2)+(*(pre_on+j+1)>>2)+(*(pre_on+j-width)>>2)+(*(pre_on+j+width)>>2);
			preDiag=(*(pre_on+j-1-width)>>3)+(*(pre_on+j-1+width)>>3)+(*(pre_on+j+1-width)>>3)+(*(pre_on+j+1+width)>>3);
			on_di=(uint16_t)(delay_on_cent*cent+(1-delay_on_cent)*preCent+delay_on_near*near+(1-delay_on_near)*preNear+delay_on_diag*diag+(1-delay_on_diag)*preDiag);
			//convolving delayed excitation in OFF channels to form OFF inhibition
			cent=*(cur_off+j);
			near=(*(cur_off+j-1)>>2)+(*(cur_off+j+1)>>2)+(*(cur_off+j-width)>>2)+(*(cur_off+j+width)>>2);
			diag=(*(cur_off+j-1-width)>>3)+(*(cur_off+j-1+width)>>3)+(*(cur_off+j+1-width)>>3)+(*(cur_off+j+1+width)>>3);
			preCent=*(pre_off+j);
			preNear=(*(pre_off+j-1)>>2)+(*(pre_off+j+1)>>2)+(*(pre_off+j-width)>>2)+(*(pre_off+j+width)>>2);
			preDiag=(*(pre_off+j-1-width)>>3)+(*(pre_off+j-1+width)>>3)+(*(pre_off+j+1-width)>>3)+(*(pre_off+j+1+width)>>3);
			off_di=(uint16_t)(delay_off_cent*cent+(1-delay_off_cent)*preCent+delay_off_near*near+(1-delay_off_near)*preNear+delay_off_diag*diag+(1-delay_off_diag)*preDiag);
			//local excitation
			s_on=*(cur_on+j)-W_bias_on*on_di;
			if(s_on<0)
				s_on=0;
			s_off=*(cur_off+j)-W_bias_off*off_di;
			if(s_off<0)
				s_off=0;
			//supralinear summation
			*(layS+j)=(uint8_t)(W_on*s_on+W_off*s_off);
			//if(*(layS+j)<=Tg)
			//	*(layS+j)=0;
		}
	}
	//Spatial processing in G layer
	/*
	for(i=1;i<Layer_Height-1;i++)
	{
		layS=&Layers->S[i][0];
		for(j=1;j<Layer_Width-1;j++)
		{
			tmp_g+=(*(layS+j-1-Layer_Width) +	*(layS+j-Layer_Width) +	*(layS+j+1-Layer_Width)+\
						*(layS+j-1) 						 +	*(layS+j) +							*(layS+j+1)+\
						*(layS+j-1+Layer_Width)  +	*(layS+j+Layer_Width) +	*(layS+j+1+Layer_Width));
		}
	}
	*mp=tmp_g/9;
	*/
	
	for(i=1;i<height-1;i++)
	{
		layS=&Layers->S[i][0];
		layG=&Layers->G[i][0];
		for(j=1;j<width-1;j++)
		{
			tmpg=	*(layS+j-1-width) +	*(layS+j-width) +	*(layS+j+1-width)+\
						*(layS+j-1)       +	*(layS+j)       +	*(layS+j+1)+\
						*(layS+j-1+width) +	*(layS+j+width) +	*(layS+j+1+width);
			*(layG+j)=(uint8_t)(tmpg/9);
			if(tmp_max<(*(layG+j)))
				tmp_max=*(layG+j);
		}
	}
	scale=deltaC+(tmp_max/Cw);
	for(i=1;i<height-1;i++)
	{
		layS=&Layers->S[i][0];
		layG=&Layers->G[i][0];
		for(j=1;j<width-1;j++)
		{
			*(layG+j)=(uint8_t)((1/scale)*(*(layS+j))*(*(layG+j)));
			if(*(layG+j)<=Tg)
				*(layG+j)=0;
			*mp+=*(layG+j);
		}
	}
	
	/***********************************************************/
	//Neural Network Outputs
	//SMP
	*cur_smp=1/(1+exp(-(*mp)*(1/(Ncell*Ksig))));
	//SFA
	diff_smp=(*cur_smp)-(*pre_smp);
	if(diff_smp<=Tsf)
		*cur_lgmd_out=delay_sfa*(*pre_lgmd_out+diff_smp);
	else
		*cur_lgmd_out=delay_sfa*(*cur_smp);
	if(*cur_lgmd_out<0.5)
			*cur_lgmd_out=0.5;
	//Spiking mechanism
	*(spike+curf)=floor(exp(Kspi*(*cur_lgmd_out-Tsp)));
	//spike frequency computation
	for(i=0;i<10;i++)
	{
		(*spiF)+=(*(spike+i));
	}
	*spiF=(*spiF)*100/(1000/hLGMD->processRate);
	
	//whole process takes about 20ms
	return 0;
}

uint8_t Decision_making(LGMD_pControlTypedef* hLGMD,uint8_t allow_motion)
{
	//static uint8_t IMU_Count=0;
	uint8_t command =0;
	//uint8_t offset = 1;
	uint8_t tspi=hLGMD->Model->Params.Tspi;
	float spiF=hLGMD->Model->Results.spiFrequency;
	uint8_t fCount=*hLGMD->hFrameCount%3;
	//attention for tilt detection
	/*if (TiltSense.OT_count>TiltSense.OT_threshold)	//9-DOF IMU (normally when getting stuck)
	{
		IMU_Count++;
		if (IMU_Count>=1)
		{
			*nsp=0;
			command='A';
			IMU_Count=0;
		}
	}*/
	if (spiF>=tspi)	//Collision recognition
	{
		LED2_Toggle;
		if(fCount==0)
		{
			command='L';		//long right
			//command='O';
			//reset Nsp
			//*nsp=0;
		}
		else
		{
			command='R';		//long left
			//command='O';
			//reset Nsp
			//*nsp=0;
		}
	}
	if(allow_motion)
	{
		/************* Pay Attention! ******************/
		//if motion sequence is not empty, do not push motions
		uint8_t readMotionQueueStatus[10]={0};
		ReadBytesWithACKFromColiasBasic(hCoS->hHCos_Motion->Instance->hHUART,0x97,readMotionQueueStatus,1);
		if((readMotionQueueStatus[1]&0x0f)==0x09)
		{
			fast_motion_control(hCoS->hHCos_Motion->Instance,command,0);	
		}
	}
	
	return 0;
}

uint8_t LGMD_demo(LGMD_pControlTypedef* hLGMD)
{
	uint8_t tmpOT;
	if(hLGMD->Enable==0)
		return 0;
	while (*(hLGMD ->hFrameCount) == hLGMD->processCountLast)
		hLGMD->status=0;	//wait until next frame if processing duration is less than one frame
	/*
	if (hLGMD->processRate)
		while ((*(hLGMD->hFrameCount))*(hLGMD->processRate) < (hLGMD->processCount)*OV7670_FPS)	//wait until expected processing rate	
			hLGMD->status=0;	//wait until next frame if processing duration is less than one frame
	*/
	hLGMD->status=1;
	TICin2; //start clocking,reset timer to 0
	hCoS->hHBIO->Instance->timerlog[0]=TOCin2; //save timer tick
	Calc_LGMDs_OutOfChannel(hLGMD);
	hCoS->hHBIO->Instance->timerlog[1]=TOCin2; //save timer tick
	Fast_LGMD(hLGMD);
	hCoS->hHBIO->Instance->timerlog[2]=TOCin2; //save timer tick
	//delay_ms(10);
	
	//print elapsed time
	//printf("%d \r\n",hCoS->hHBIO->Instance->timerlog[2]-hCoS->hHBIO->Instance->timerlog[0]);
	
	hLGMD->processCountLast = *(hLGMD ->hFrameCount);
	(hLGMD->processCount)++;
	//hCoS->hHBIO->Instance->timerlog[2]=TOCin2; //save timer tick
	tmpOT=256*((hLGMD->Model->Results.LGMD_out[hLGMD->currentDiffImage])-0.5);
	
	/*
	For Qinbing Attention
	the code below is to set the LEDs on the extend board,
	which is the last 8 bits of GPIOD->ODR register.
	LED is on when bit state is reset
	*/
	GPIOD->ODR=(GPIOD->ODR&0xffffff00)+(~tmpOT);
	
	return 0;
}