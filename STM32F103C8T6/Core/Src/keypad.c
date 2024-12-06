/*
 * keypad.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "keypad.h"

TIM_HandleTypeDef htim1;
unsigned char check_clm(unsigned char pin_var){
	unsigned char clm;
	HAL_GPIO_WritePin(R1_GPIO_Port,R1_Pin,RESET);
	HAL_GPIO_WritePin(R2_GPIO_Port,R2_Pin,RESET);
	HAL_GPIO_WritePin(R3_GPIO_Port,R3_Pin,RESET);
	HAL_GPIO_WritePin(R4_GPIO_Port,R4_Pin,RESET);

	HAL_GPIO_WritePin(R1_GPIO_Port,R1_Pin,SET);
	if(HAL_GPIO_ReadPin(GPIOA, pin_var) == 0){
		clm = 1;
	}
	HAL_GPIO_WritePin(R1_GPIO_Port,R1_Pin,RESET);

	HAL_GPIO_WritePin(R2_GPIO_Port,R2_Pin,SET);
	if(HAL_GPIO_ReadPin(GPIOA, pin_var) == 0){
		clm = 2;
	}
	HAL_GPIO_WritePin(R2_GPIO_Port,R2_Pin,RESET);

	HAL_GPIO_WritePin(R3_GPIO_Port,R3_Pin,SET);
	if(HAL_GPIO_ReadPin(GPIOA, pin_var) == 0){
		clm = 3;
	}
	HAL_GPIO_WritePin(R3_GPIO_Port,R3_Pin,RESET);

	HAL_GPIO_WritePin(R4_GPIO_Port,R4_Pin,SET);
	if(HAL_GPIO_ReadPin(GPIOA, pin_var) == 0){
		clm = 4;
	}
	HAL_GPIO_WritePin(R4_GPIO_Port,R4_Pin,RESET);

	HAL_GPIO_WritePin(R1_GPIO_Port,R1_Pin,SET);
	HAL_GPIO_WritePin(R2_GPIO_Port,R2_Pin,SET);
	HAL_GPIO_WritePin(R3_GPIO_Port,R3_Pin,SET);
	HAL_GPIO_WritePin(R4_GPIO_Port,R4_Pin,SET);
	return clm;
}

unsigned char key_press(void){
	unsigned char clm_var;
	unsigned char key_arr[] = {7,8,9,15,4,5,6,14,1,2,3,13,0,11,12};
	if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)){
		clm_var = check_clm(C1_Pin);
		return key_arr[clm_var-1];
	}
	if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)){
		clm_var = check_clm(C2_Pin);
		return key_arr[clm_var+3];
	}
	if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)){
		clm_var = check_clm(C3_Pin);
		return key_arr[clm_var+7];
	}
	if(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)){
		clm_var = check_clm(C4_Pin);
		return key_arr[clm_var+11];
	}
	else
		return 16;
}
 void pass_key(unsigned char key_var){
	 static unsigned char pass_var1 = 0;
	 unsigned char key_arr[6];
	 unsigned char enter_key[6] = {"271076"};
	 unsigned char i;

	 if(key_var != 16){
		 key_arr[pass_var1] = key_var + 48;
		 lcd_goto_XY(key_var+48, 1);
		 pass_var1++;
		 if(pass_var1 == 6){
			 lcd_goto_XY(1, 0);
			 for(i = 0; i < 6; i++){
				 if(key_arr[i] != enter_key[i]){
					 HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
					 wrong_buzzer();
					 lcd_send_string("type again.");
					 pass_var1 = 0;
					 break;
				 }
			 }
			 if(i == 6)
			 {
				 HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
				 right_buzzer();
				 lcd_send_string("Welcome User !!!");
			 }
			 HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
			 HAL_Delay(3000);
			 pass_var1 = 0;
			 lcd_clear_display();
			 lcd_goto_XY(0, 0);
			 lcd_send_string("Enter password.");
			 lcd_goto_XY(1,0);
		 }
	 }
 }
