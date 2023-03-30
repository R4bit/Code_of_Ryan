/*
 * Description: LGMD-Plus
 * Filename: LGMD_model.h
 * Author: Qinbing Fu
 * Date: 2019 Aug
*/

#ifndef __LGMD_PC_H
#define __LGMD_PC_H


#include <stdint.h>


#define Layer_Width 99
#define Layer_Height 72


typedef struct
{
	uint8_t ON[2][Layer_Height][Layer_Width];	//ON Cells
	uint8_t OFF[2][Layer_Height][Layer_Width];	//OFF Cells
	uint8_t S[Layer_Height][Layer_Width];	//Summation Layer
	uint8_t G[Layer_Height][Layer_Width];	//Grouping Layer
}LGMDstruct_Layer;

typedef struct
{
	uint8_t Kspi;	//scale parameter in spiking mechanism
	uint8_t Cw;	//constant to compute the scale in G layer
	uint8_t CdeTde;	//threshold gate in G layer
	uint8_t Tffi;	//FFI threshold
	uint8_t Tspi;	//threshold for spiking frequency inidicating danger
	int8_t clip;	//clip point in ON and OFF mechanisms
	float W_on;	//weight on ON channel excitation
	float W_off;	//weight on OFF channel excitation
	float W_base;	//baseline of local bias
	float Tsp;	//threshold for spiking
	float Tsfa;	//threshold for SFA
	float Bias_on;	//inhibitory bias in ON channels
	float Bias_off;	//inhibitory bias in OFF channels
	float Ksig;	//coefficient in sigmoid function
	float DeltaC;	//small real number to compute the scale in G layer
	float hp_tau;	//latency in SFA
	float lp_ffi;	//latency in FFI-M
	float lp_on_cent_tau;	//latency in centre cells in ON channels
	float lp_on_near_tau;	//latency in nearest cells in ON channels
	float lp_on_diag_tau;	//latency in diagonal cells in ON channels
	float lp_off_cent_tau;	//latency in centre cells in OFF channels
	float lp_off_near_tau;	//latency in nearest cells in OFF channels
	float lp_off_diag_tau;	//latency in diagonal cells in OFF channels
	float delay_sfa;	//delay coefficient in SFA
	float delay_ffi;	//delay coefficient in FFI
	float delay_on_cent;	//delay coefficient in centre cells in ON channels
	float delay_on_near;	//delay coefficient in nearest cells in ON channels
	float delay_on_diag;	//delay coefficient in diagonal cells in ON channels
	float delay_off_cent;	//delay coefficient in centre cells in OFF channels
	float delay_off_near;	//delay coefficient in nearest cells in OFF channels
	float delay_off_diag;	//delay coefficient in diagonal cells in OFF channels
}LGMDstruct_Params;


typedef struct
{
	uint8_t SPIKE[10];	//spikes
	float MP;	//membrane potential
	float FFI_out[2];	//FFI output
	float SMP[2];	//sigmoid membrane potential
	float LGMD_out[2];	//LGMDs output
	float spiFrequency;	//spiking frequency
}LGMDstruct_Result;

typedef struct
{
	LGMDstruct_Layer Layers;
	LGMDstruct_Params Params;
	LGMDstruct_Result Results;
	int16_t* pImg;
	int8_t* pDiffImg;
}LGMDType;


#endif

