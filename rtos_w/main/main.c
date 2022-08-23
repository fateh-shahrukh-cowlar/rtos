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
        xTaskNotify(receievrHandler,(1<<0),eSetBits); //
        vTaskDelay(1000/portTICK_PERIOD_MS);
        xTaskNotify(receievrHandler,(1<<1),eSetBits); //
        vTaskDelay(1000/portTICK_PERIOD_MS);
         xTaskNotify(receievrHandler,(1<<2),eSetBits); //
        vTaskDelay(1000/portTICK_PERIOD_MS);
         xTaskNotify(receievrHandler,(1<<3),eSetBits); //
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
void receiver(void *params)
{
    uint state;
    while(true)
    {
        xTaskNotifyWait(0,0,&state,portMAX_DELAY);
        printf("Recieved Notification %d times \n",state);
    }
}
void app_main(void)
{
    xTaskCreate(&receiver,"sender",2048,NULL,2,&receievrHandler);
    xTaskCreate(&sender,"reciever",2048,NULL,2,NULL);
}