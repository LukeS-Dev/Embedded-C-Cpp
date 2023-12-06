#include <stdio.h>
#include "ledControl.h"

#include "esp_log.h"


#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#define LOG_TAG "LED_CONTROL"

void ledControl_Init(void)
{
    ESP_LOGI(LOG_TAG,"LED Control Task Init");
}

void ledControl_Runtime(void)
{
    ESP_LOGI(LOG_TAG,"LED Control Main");
}