/*
 * keypad.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include "main.h"
#include "lcd.h"
#include "buzzer.h"

unsigned char check_clm(unsigned char pin_var);
unsigned char key_press(void);
void pass_key(unsigned char key_var);
#endif /* INC_KEYPAD_H_ */
