/*
 * timer.c
 *
 *  Created on: Oct 25, 2024
 *      Author: Admin
 */

#include "timer.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	timerRun();
}

void timerRun()
{

}
