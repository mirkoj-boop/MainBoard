/*
 Naslov: MIKRORA�UNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okru�enju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Mileti�
 
 Vje�ba 4.1.3
 */ 


#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija(){
	
	DDRB |= (1 << PB7); // pin PB7 postavljen kao izlazni port
	PORTB |= (1 << PB7); // postavljanje pina PB7 u logi�ku jedinicu

}
		


int main(void){
		
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	

return 0;
	
}