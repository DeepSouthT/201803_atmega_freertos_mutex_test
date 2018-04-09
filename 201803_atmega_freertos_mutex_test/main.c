/*
 * 201803_atmega_freertos_mutex_test.c
 *
 * Created: 02.04.2018 20:27:06
 * Author: DeepSouthT
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "mytasks.h"
#include "mytasks_1.h"
#include "semphr.h"
#include "queue.h"

#define mainLED_TASK_PRIORITY			( tskIDLE_PRIORITY )

uint16_t uint16_delay_time_ms =4000;
SemaphoreHandle_t xMutex;

portSHORT main(void)
{
	xMutex = xSemaphoreCreateMutex();
	
	xTaskCreate( vLEDFlashTask, ( signed char * ) "LED_6", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL );
	
	xTaskCreate( vLEDFlashTask_1, ( signed char * ) "LED_7", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL );
	
	//start scheduler
	vTaskStartScheduler();
	//you should never get here
	while(1)
	{
		
	}
	return 0;
}

