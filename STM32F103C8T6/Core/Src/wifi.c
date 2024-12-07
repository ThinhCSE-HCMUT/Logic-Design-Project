/*
 * wifi.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "wifi.h"


uint32_t uint8ArrayToInt(uint8_t* array, size_t length) {
    uint32_t result = 0;
    for (size_t i = 0; i < length; i++) {
        result = (result << 8) | array[i]; } return result;
}



uint32_t checkForID(){
	uint8_t Rx_data[2];
    memset(Rx_data, 0, 2); //clear array before receiving again
    uint32_t temp = -1;

    if (HAL_UART_Receive(&huart1, Rx_data, sizeof(Rx_data)-1, 1000) == HAL_OK) { // receiving the index
        temp = uint8ArrayToInt(Rx_data, sizeof(Rx_data)); //decode the index
		//for debug purposes transmit back to esp32
		//HAL_UART_Transmit(&huart1, Rx_data, strlen((char *)Rx_data), 1000);
    }
    return temp;
}

