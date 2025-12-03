/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "uart.h"

#define mainTASK_PRIORITY    ( tskIDLE_PRIORITY + 2 )

void vProducer(void *pvParameters);
void vConsumer(void *pvParameters);
QueueHandle_t queueHandler;

int main(int argc, char **argv){

	(void) argc;
	(void) argv;

  //init uart and queue
  UART_init();
  queueHandler = xQueueCreate(100, sizeof(int));

  xTaskCreate(vProducer,"Producer",configMINIMAL_STACK_SIZE,NULL,mainTASK_PRIORITY,NULL);
	xTaskCreate(vConsumer,"Consumer",configMINIMAL_STACK_SIZE,NULL,mainTASK_PRIORITY,NULL);

	// Give control to the scheduler
	vTaskStartScheduler();

	// If everything ok should never reach here
    for( ; ; );
}

/* Task Function */
void vProducer(void *pvParameters) {

	// Avoid warning about unused pvParameters
  (void) pvParameters;
  int i = 0;
    
  for (;;) {

        xQueueSend(queueHandler, &i, 0);

        // Task code: print a message
        UART_printf("produced %d\n", i);
        i++;

        // Delay for 1 second
        //vTaskDelay(pdMS_TO_TICKS(500));
    }
}

/* Task Function */
void vConsumer(void *pvParameters) {

	// Avoid warning about unused pvParameters
    (void) pvParameters;
    int i;

    for (;;) {
        
        if(xQueueReceive(queueHandler, &i, portMAX_DELAY) == pdTRUE){
      
        // Task code: print a message
        UART_printf("consumed %d\n", i);

        // Delay for 1 second
        //vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
}
