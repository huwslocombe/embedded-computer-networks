/*
 * main.c
 *
 * this is the main blinky application (this code is dependent on the
 * extra shu libraries such as the pinmappings list and the clock configuration
 * library)
 *
 * author:    Dr. Alex Shenfield
 * date:      01/09/2018
 * purpose:   55-604481 embedded computer networks : lab 101
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the leds to GPIO PI1, GPIO PB_14, and GPIO PB_15 (again, this is the inbuilt led)
gpio_pin_t led1 = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led2 = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led3 = {PB_15, GPIOB, GPIO_PIN_15};

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pins
  init_gpio(led1, OUTPUT);
	init_gpio(led2, OUTPUT);
	init_gpio(led3, OUTPUT);
  
  // loop forever ...
  while(1)
  {
    // toggle the led on the gpio pin
    write_gpio(led1,HIGH);
		HAL_Delay(5000);
		
		write_gpio(led2,HIGH);
		HAL_Delay(1000);
		toggle_gpio(led2);
		HAL_Delay(1000);
		toggle_gpio(led2);
		HAL_Delay(1000);
		toggle_gpio(led2);
		HAL_Delay(1000);
		toggle_gpio(led2);
		HAL_Delay(1000);
		toggle_gpio(led2);
		HAL_Delay(1000);
	
		write_gpio(led1,LOW);
		
		write_gpio(led3,HIGH);
		HAL_Delay(5000);
		write_gpio(led3,LOW);
     
  }
}
