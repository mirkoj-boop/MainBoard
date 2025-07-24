/*
 Naslov: MIKRORA�UNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okru�enju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Mileti�
 
 Vje�ba 4.1.1
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>

void inicijalizacija(){
	
	output_port(DDRB,PB7);
	set_port(PORTB,PB7,1);
}


int main(void){
		
	inicijalizacija();		
	
return 0;
	
}