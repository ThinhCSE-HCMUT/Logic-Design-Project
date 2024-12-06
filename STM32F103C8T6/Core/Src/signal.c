/*
 * signal.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Fung
 */

#include "signal.h"


void correct(){
//	lcd_init();
	lcd_clear_display();
	lcd_goto_XY(0, 0);
	lcd_send_string("Welcome User");
	lcd_goto_XY(1, 1);
	lcd_send_string("Thinh");
	right_buzzer();
}
void wrong(){
	lcd_clear_display();
	lcd_goto_XY(1, 0);
	lcd_send_string("Wrong User");
	wrong_buzzer();
}
void reset(){
	lcd_clear_display();
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
}
