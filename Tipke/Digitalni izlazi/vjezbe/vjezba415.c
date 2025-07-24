/*
 Naslov: MIKRORA�UNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okru�enju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Mileti�
 
 Vje�ba 4.1.5
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include <util/delay.h>


void inicijalizacija(){
		
}


int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	
	while (1) // beskona�na petlja 
	{
	
		for (char i = 7; i >= 4; i--){
			
			_delay_ms(100);
			
			PORTB &= ~(1 << i);
			
			if (i > 4){
				PORTB |= (1 << (i-1));
			}
			else{
				PORTB |= (1 << PB7);
			}
			
		}
		
	}
	
	return 0;
	
}