/*!
 * @file 	    Application.cpp
 * @brief 	    Cpp Application
 * @author 	    Tom Christ
 * @date 	    2024-04-20
 * @copyright   Copyright (c) 2024 Tom Christ; MIT License   
 * @version	    0.1		Initial Version
 */

#include "Application.h"

#include "freertos/FreeRTOS.h"

#include "esp_log.h"

#define TAG "APP"

using namespace std;

/*!
 * @brief   Application entry point.
 */
void run()
{
    ESP_LOGI(TAG,"Hello from C++");
}