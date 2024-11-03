#include <stdio.h> 
#include <stdbool.h> 
#include <unistd.h> 
#include "driver/gpio.h" 
#include "hal/gpio_types.h"

#define LED_YELLOW GPIO_NUM_4 
#define BUTTON GPIO_NUM_5

void app_main(void) 
{  
	
	gpio_reset_pin(LED_YELLOW);
	gpio_set_direction(LED_YELLOW, GPIO_MODE_OUTPUT);
	
	gpio_reset_pin(BUTTON);
	gpio_set_pull_mode(BUTTON, GPIO_PULLUP_ONLY);
	gpio_set_direction(BUTTON, GPIO_MODE_INPUT);
	
	while(true){
		
		int status = gpio_get_level(BUTTON); 
				
		if(status == 0){	
			printf("botão pressionado -> entrada em nível baixo -> ligar led!\n");		
			gpio_set_level(LED_YELLOW, true);
		}
		else {//when the button is pressed, GPIO5 is put to high and the gpio_get_level returns true
		      // and here we want to turn of the led 
			printf("botão não pressionado -> entrada em nível alto -> desligar led!\n");	
			gpio_set_level(LED_YELLOW, false);
						
		}
		
		sleep(1);	
		
	}//while
	
}//app_main 

 
