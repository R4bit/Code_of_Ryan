/**
  ******************************************************************************
  * File Name          : mxconstants.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MXCONSTANT_H
#define __MXCONSTANT_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define IDLE 0
#define BUSY 1

#define SCCB_SDA_Pin GPIO_PIN_2
#define SCCB_SDA_GPIO_Port GPIOE
#define SCCB_SCL_Pin GPIO_PIN_3
#define SCCB_SCL_GPIO_Port GPIOE
#define FLASH_CS_Pin GPIO_PIN_13
#define FLASH_CS_GPIO_Port GPIOC
#define FLASH_D2_Pin GPIO_PIN_14
#define FLASH_D2_GPIO_Port GPIOC
#define FLASH_D3_Pin GPIO_PIN_15
#define FLASH_D3_GPIO_Port GPIOC
#define eSPI_P2_Pin GPIO_PIN_0
#define eSPI_P2_GPIO_Port GPIOC
#define eSPI_P3_Pin GPIO_PIN_1
#define eSPI_P3_GPIO_Port GPIOC
#define ACC_INT_Pin GPIO_PIN_2
#define ACC_INT_GPIO_Port GPIOC
#define eSPI_MOSI_Pin GPIO_PIN_3
#define eSPI_MOSI_GPIO_Port GPIOC
#define S1_Pin GPIO_PIN_0
#define S1_GPIO_Port GPIOA
#define S2_Pin GPIO_PIN_1
#define S2_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOA
#define GP2_Pin GPIO_PIN_4
#define GP2_GPIO_Port GPIOC
#define LED4_Pin GPIO_PIN_9
#define LED4_GPIO_Port GPIOE
#define LED5_Pin GPIO_PIN_11
#define LED5_GPIO_Port GPIOE
#define LED6_Pin GPIO_PIN_13
#define LED6_GPIO_Port GPIOE
#define ACC_AD0_Pin GPIO_PIN_15
#define ACC_AD0_GPIO_Port GPIOE
#define sI2C_SDA_Pin GPIO_PIN_11
#define sI2C_SDA_GPIO_Port GPIOB
#define eSPI_P1_Pin GPIO_PIN_12
#define eSPI_P1_GPIO_Port GPIOB
#define eSPI_SCK_Pin GPIO_PIN_13
#define eSPI_SCK_GPIO_Port GPIOB
#define eSPI_MISO_Pin GPIO_PIN_14
#define eSPI_MISO_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_13
#define LED3_GPIO_Port GPIOD
#define ACC_nCS_Pin GPIO_PIN_8
#define ACC_nCS_GPIO_Port GPIOC
#define MCO_CAM_Pin GPIO_PIN_8
#define MCO_CAM_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define GP1_Pin GPIO_PIN_15
#define GP1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_12
#define LED2_GPIO_Port GPIOC
#define sI2C_SCL_Pin GPIO_PIN_8
#define sI2C_SCL_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MXCONSTANT_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
