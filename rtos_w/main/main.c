#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void sender(void *params)
{
    while(true)
    {

    }
}
void sender(void *params)
{
    while(true)
    {
        
    }
}
void app_main(void)
{
    xTaskCreate(&reciever,"sender",2048,NULL,2,NULL);
    xTaskCreate(&sender,"reciever",2048,NULL,2,NULL);
}