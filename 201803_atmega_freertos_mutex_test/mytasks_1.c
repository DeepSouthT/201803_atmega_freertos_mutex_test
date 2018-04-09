/*
 * mytasks_1.c
 *
 * Created: 02.04.2018 20:27:06
 * Author: DeepSouthT
 */ 
#include "FreeRTOS.h"
#include "task.h"
#include "port_b_led.h"
#include "mytasks_1.h"
#include "semphr.h"
#include "queue.h"
#include <stdbool.h>

void vLEDFlashTask_1( void *pvParameters )
{
	static bool bInitialTaskRun =true;
	
	if (bInitialTaskRun ==true)
	{
		vLEDInit(5);
		vLEDInit(7);
		
		bInitialTaskRun =false;
	}
	
	portTickType xLastWakeTime;
	
	extern uint16_t uint16_delay_time_ms;
	extern SemaphoreHandle_t xMutex;
	
	xLastWakeTime=xTaskGetTickCount();
	
	for( ;; )
	{
		xSemaphoreTake(xMutex, portMAX_DELAY);
		vLEDOn(5);
		vLEDToggle(7);
		
		vTaskDelayUntil(&xLastWakeTime,uint16_delay_time_ms);
		
		if (uint16_delay_time_ms <=500)
		{ uint16_delay_time_ms =2000; } 
		else{ uint16_delay_time_ms =uint16_delay_time_ms - 100; }

		xSemaphoreGive(xMutex);
		vLEDOff(5);
	}
}