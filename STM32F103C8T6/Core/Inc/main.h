/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define keypad_in1_Pin GPIO_PIN_0
#define keypad_in1_GPIO_Port GPIOA
#define keypad_in2_Pin GPIO_PIN_1
#define keypad_in2_GPIO_Port GPIOA
#define keypad_in3_Pin GPIO_PIN_2
#define keypad_in3_GPIO_Port GPIOA
#define keypad_in4_Pin GPIO_PIN_3
#define keypad_in4_GPIO_Port GPIOA
#define SSCS_RFID_Pin GPIO_PIN_4
#define SSCS_RFID_GPIO_Port GPIOA
#define SCLK_RFID_Pin GPIO_PIN_5
#define SCLK_RFID_GPIO_Port GPIOA
#define MISO_RFID_Pin GPIO_PIN_6
#define MISO_RFID_GPIO_Port GPIOA
#define MOSI_RFID_Pin GPIO_PIN_7
#define MOSI_RFID_GPIO_Port GPIOA
#define keypad_out1_Pin GPIO_PIN_0
#define keypad_out1_GPIO_Port GPIOB
#define keypad_out2_Pin GPIO_PIN_1
#define keypad_out2_GPIO_Port GPIOB
#define keypad_out3_Pin GPIO_PIN_2
#define keypad_out3_GPIO_Port GPIOB
#define keypad_out4_Pin GPIO_PIN_10
#define keypad_out4_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_11
#define BUZZER_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_8
#define LED_R_GPIO_Port GPIOA
#define LED_G_Pin GPIO_PIN_9
#define LED_G_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_10
#define LED_B_GPIO_Port GPIOA
#define TX_WIFI_Pin GPIO_PIN_6
#define TX_WIFI_GPIO_Port GPIOB
#define RX_WIFI_Pin GPIO_PIN_7
#define RX_WIFI_GPIO_Port GPIOB
#define SCL_LCD_Pin GPIO_PIN_8
#define SCL_LCD_GPIO_Port GPIOB
#define SDA_LCD_Pin GPIO_PIN_9
#define SDA_LCD_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
