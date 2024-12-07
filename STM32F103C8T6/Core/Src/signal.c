/*
 * signal.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Fung
 */

#include "signal.h"


void correct(){
	lcd_clear_display();
	lcd_goto_XY(0, 0);
	lcd_send_string("Welcome User");
	lcd_goto_XY(1, 1);
	lcd_send_string("thinh");
	right_buzzer();
	blinkClolor(LED_STATE_ACCEPT);
}
void wrong(){
	lcd_clear_display();
	lcd_goto_XY(1, 0);
	lcd_send_string("Wrong User");
	wrong_buzzer();
	blinkClolor(LED_STATE_DENY);
}
void choosingUser(char* user_array){
	int index = checkForID(); //ham nhan tin hieu va tra ve index can cho mang
	if(index == -1){
		//chua quet duoc tin hieu
		//ham if nay dung de chong nhieu
	}else{
		if(index == 0) wrong();
		else {
			correct(user_array[index]);
		}
	}
}


void reset(){
	lcd_clear_display();
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
}
