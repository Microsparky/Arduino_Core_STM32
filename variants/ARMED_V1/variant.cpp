/*
 *******************************************************************************
 * Copyright (c) 2017, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
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
 *******************************************************************************
*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
  PA_0,  //D0
  PA_1,  //D1
  PA_2,  //D2
  PA_3,  //D3
  PA_4,  //D4
  PA_5,  //D5
  PA_6,  //D6
  PA_7,  //D7
  PA_8,  //D8
  PA_9,  //D9
  PA_10, //D10
  PA_11, //D11
  PA_12, //D12
  PA_13, //D13
  PA_14, //D14
  PA_15, //D15
  PB_0,  //D16
  PB_1,  //D17
  PB_2,  //D18
  PB_3,  //D19
  PB_4,  //D20
  PB_5,  //D21
  PB_6,  //D22
  PB_7,  //D23
  PB_8,  //D24
  PB_9,  //D25
  PB_10, //D26
  PB_11, //D27
  PB_12, //D28
  PB_13, //D29
  PB_14, //D30
  PB_15, //D31
  PC_0,  //D32/A0
  PC_1,  //D33/A1
  PC_2,  //D34/A2
  PC_3,  //D35
  PC_4,  //D36
  PC_5,  //D37
  PC_6,  //D38
  PC_7,  //D39
  PC_8,  //D40
  PC_9,  //D41
  PC_10, //D42
  PC_11, //D43
  PC_12, //D44
  PC_13, //D45
  PC_14, //D46
  PC_15, //D47
  PD_0,  //D48
  PD_1,  //D49
  PD_2,  //D50
  PD_3,  //D51
  PD_4,  //D52
  PD_5,  //D53
  PD_6,  //D54
  PD_7,  //D55
  PD_8,  //D56
  PD_9,  //D57
  PD_10, //D58
  PD_11, //D59
  PD_12, //D60
  PD_13, //D61
  PD_14, //D62
  PD_15, //D63
  PE_0,  //D64
  PE_1,  //D65
  PE_2,  //D66
  PE_3,  //D67
  PE_4,  //D68
  PE_5,  //D69
  PE_6,  //D70
  PE_7,  //D71
  PE_8,  //D72
  PE_9,  //D73
  PE_10, //D74
  PE_11, //D75
  PE_12, //D76
  PE_13, //D77
  PE_14, //D78
  PE_15  //D79
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief  System Clock Configuration
*         The system Clock is configured as follow :
*            System Clock source            = PLL (HSE)
*            SYSCLK(Hz)                     = 168000000
*            HCLK(Hz)                       = 168000000
*            AHB Prescaler                  = 1
*            APB1 Prescaler                 = 4
*            APB2 Prescaler                 = 2
*            HSE Frequency(Hz)              = 8000000
*            PLL_M                          = 8
*            PLL_N                          = 336
*            PLL_P                          = 2
*            PLL_Q                          = 7
*            VDD(V)                         = 3.3
*            Main regulator output voltage  = Scale1 mode
*            Flash Latency(WS)              = 5
* @param  None
* @retval None
*/
WEAK void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /**Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
   clocked below the maximum system frequency, to update the voltage scaling value
   regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    _Error_Handler(__FILE__, __LINE__);
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
   clocks dividers */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
    _Error_Handler(__FILE__, __LINE__);
  }

  /* Ensure CCM RAM clock is enabled */
  __HAL_RCC_CCMDATARAMEN_CLK_ENABLE();
}

#ifdef __cplusplus
}
#endif
