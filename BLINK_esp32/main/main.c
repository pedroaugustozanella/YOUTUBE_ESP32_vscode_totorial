#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED 2

void app_main(void)
{
    gpio_reset_pin(LED);                            //Inicializa pino 2 -> LED
    gpio_set_direction(LED,GPIO_MODE_OUTPUT);       //Define pino 2 como saida

    printf("LED 2 Foi inicializado... \n");         //Escreve na serial
    vTaskDelay(1000/portTICK_PERIOD_MS);            //Espera 1 segundo

    while(1) {                              // lupe infinito
        gpio_set_level(LED,0);                        //Apaga LED
        printf("LED 2 esta apagado. \n");               //Escreve na serial
        vTaskDelay(1000/portTICK_PERIOD_MS);            //Espera 1 segundo
        gpio_set_level(LED,1);                       //liga o LED
        printf("LED 2 esta ligado \n");                 //Escreve na serial
        vTaskDelay(1000/portTICK_PERIOD_MS);            //Espera 1 segundo
    }
}
