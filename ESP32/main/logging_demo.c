#include <stdio.h>

#include "logging_demo.h"
#include "ledControl.h"

#include "esp_log.h"

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#define LOG_TAG "MAIN"

void app_main(void)
{
    const TickType_t delay = 500 / portTICK_PERIOD_MS; // Tick to port conversion.

    ledControl_Init();    

    while (true)
    {
        ESP_LOGI(LOG_TAG, "Hello World!");
        ledControl_Runtime();
        vTaskDelay(delay);
    }
}
