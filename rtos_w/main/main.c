#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void sender(void *params)
{
    while(true)
    {
        xtaskNotifyGive(recieverHandler);
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}
void reciever(void *params)
{
    while(true)
    {
        int count=ulTaskNotifyTake(pdFALSE,portMAX_DELAY);
        printf("Recieved Notification %d times /n",count);
    }
}
void app_main(void)
{
    xTaskCreate(&reciever,"sender",2048,NULL,2,NULL);
    xTaskCreate(&sender,"reciever",2048,NULL,2,NULL);
}