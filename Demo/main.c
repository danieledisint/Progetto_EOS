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
