/*
 * signal.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Fung
 */

#ifndef INC_SIGNAL_H_
#define INC_SIGNAL_H_

#include "main.h"
#include "buzzer.h"
#include "lcd.h"
#include "led_rgb.h"
#include "wifi.h"

void correct();
void wrong();
void reset();
void choosingUser(char* user_array);
#endif /* INC_SIGNAL_H_ */
