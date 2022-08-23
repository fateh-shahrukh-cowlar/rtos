#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
static TaskHandle_t receievrHandler=NULL;
void sender(void *params)
{
    while(true)
    {
        xTaskNotifyGive(receievrHandler);
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}
void receiver(void *params)
{
    while(true)
    {
        int count=ulTaskNotifyTake(pdFALSE,portMAX_DELAY);
        printf("Recieved Notification %d times \n",count);
    }
}
void app_main(void)
{
    xTaskCreate(&receiver,"sender",2048,NULL,2,&receievrHandler);
    xTaskCreate(&sender,"reciever",2048,NULL,2,NULL);
}