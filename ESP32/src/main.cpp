#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/uart.h"
#include "string.h"
#include "driver/gpio.h"


#include "wifi_config.h"
#include "web_server.h"


static const int RX_BUF_SIZE = (1024*2);

#define TXD_PIN (GPIO_NUM_17)
#define RXD_PIN (GPIO_NUM_16)
//#define CTS_PIN (GPIO_NUM_23)
//#define RTS_PIN (GPIO_NUM_21)
#define uart_num (UART_NUM_2)
int counter = 0;
int num = 0;
void init_ua(void) 
{
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 122,
    };
    QueueHandle_t uart_queue;
    // Install UART driver using an event queue here
    ESP_ERROR_CHECK(uart_driver_install(uart_num, RX_BUF_SIZE, RX_BUF_SIZE, 10, &uart_queue, 0));
    // Configure UART parameters
    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(uart_num, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
}
void sendMessage(const char* message) { 
    uart_write_bytes(uart_num, message, strlen(message)); 
    //Serial.printf("Sent: %s\n", message);
}
void setup() {
    Serial.begin(115200);
    init_ua();
    setupWiFi();          // Kết nối WiFi
    setupTime();          // Cấu hình NTP
    setupRFID();          // Khởi động RFID
    setupWebServer();     // Khởi động WebServer

    Serial.println("Place RFID card near the reader:");
}
void loop() {
    
    // handleWebServer();    // Xử lý WebServer
    // handleRFID();         // Xử lý quét thẻ RFID


    sendMessage("0");
    uint8_t data[100]; 
    //uint8_t* data = (uint8_t*) malloc(1024);
    memset(data, 0, 100);

    int length = uart_read_bytes(uart_num, data, sizeof(data)-1, 100 / portTICK_PERIOD_MS); 
    if (length > 0) { 
        data[length] = '\0'; 
        
        Serial.printf("Data received: %s\n", data); 
        if (strcmp((char*)data, "YELLO esp32") == 0) { 
            Serial.println("Data matched"); 
        }else{ 
            Serial.println("Data mismatch");
        }
    }else { 
        //Serial.println("No data received"); // Debug message 
    }
}