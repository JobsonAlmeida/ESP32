#include <stdio.h> 
#include <stdbool.h> 
#include <unistd.h> 
#include "driver/gpio.h" 

#define LED_RED 2
#define LED_GREEN GPIO_NUM_15 
#define LED_YELLOW GPIO_NUM_4 



void app_main(void) 
{  
	
	gpio_reset_pin(LED_GREEN); // se esse pino não for resetado ele não funciona
	//gpio_reset_pin(LED_YELLOW);
		
	gpio_set_direction(LED_RED, GPIO_MODE_OUTPUT); 
  	gpio_set_direction(LED_GREEN, GPIO_MODE_OUTPUT); 
  	gpio_set_direction(LED_YELLOW, GPIO_MODE_OUTPUT); 

	while(true){ 
		  
		printf("LED acesso!\n");
		gpio_set_level(LED_RED, 1); 
		gpio_set_level(LED_GREEN, 1); 
		gpio_set_level(LED_YELLOW, 1);

		sleep(2); 
		  
		printf("LED apagado!\n");
		gpio_set_level(LED_RED, 0);
		gpio_set_level(LED_GREEN, 0);
		gpio_set_level(LED_YELLOW, 0);
		sleep(2);  
	    
	}   

} 

 
