/*!
 * @file 	    main.c
 * @brief 	    Program entry
 * @author 	    Tom Christ
 * @date 	    2024-03-18
 * @copyright   Copyright (c) 2024 Tom Christ; MIT License   
 * @version	    0.1		Initial Version
 */

#include "Application.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "nvs_flash.h"
#include "esp_err.h"
#include "esp_log.h"

#define TAG "MAIN"

/*!
 * @brief   app_main
 *          Entry for user code.
 */
void app_main(void)
{
    ESP_LOGI(TAG, "Entered app_main");

    // NVS INIT
    esp_err_t result = nvs_flash_init();
    if (result == ESP_ERR_NVS_NO_FREE_PAGES || result == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        result = nvs_flash_erase();
        if (result != ESP_OK) {
            ESP_LOGE(TAG, "NVS error, could not erase flash, rebooting in 10s");
            vTaskDelay(pdMS_TO_TICKS(10000));
            esp_restart();
        } else {
            result = nvs_flash_init();
            if (result != ESP_OK) {
                ESP_LOGE(TAG, "NVS error, could not initialize, rebooting in 10s");
                vTaskDelay(pdMS_TO_TICKS(10000));
                esp_restart();
            }
        } 
    }

    // Begin C++ (Application.cpp)
    run();
}