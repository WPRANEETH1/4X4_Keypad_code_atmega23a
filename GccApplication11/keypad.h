
#include<avr/io.h>
#include<util/delay.h>

///////  keypad CONNECTIONS  ///////

#define ROW_1 PC0       //output pin 1
#define ROW_2 PC1       //output pin 2
#define ROW_3 PC2       //output pin 3
#define ROW_4 PC3		//output pin 4
#define COLUMN_1 PC4		//input pin 1
#define COLUMN_2 PC5		//input pin 2
#define COLUMN_3 PC6		//input pin 3
#define DEFINE_PIN_TYPE DDRC

////////////////////////////////////////

struct keypad_return
{
	int keypad_value;
	int keypad_counter;
};
struct keypad_return keypad;


void keypad_init()
{
	DEFINE_PIN_TYPE|=((1<<ROW_1)|(1<<ROW_2)|(1<<ROW_3)|(1<<ROW_4));   //define output pin
	DEFINE_PIN_TYPE &= ~((1<<COLUMN_1)|(1<<COLUMN_2)|(1<<COLUMN_3));  //define input pin
	
}

int keypad_read()
{
	
	keypad_init();
	
	PORTC |= (1<<PORTC0);
	_delay_us(2);
	if(PINC & (1<<COLUMN_1))
	{
		keypad.keypad_value=1;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else if(PINC & (1<<COLUMN_2))
	{
		keypad.keypad_value=2;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else if(PINC & (1<<COLUMN_3))
	{
		keypad.keypad_value=3;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	
	else
	;
	PORTC &= ~(1<<PORTC0);
	
	
	
	
	PORTC |= (1<<PORTC1);
	_delay_us(2);
	if(PINC & (1<<COLUMN_1))
	{
		keypad.keypad_value=4;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else if(PINC & (1<<COLUMN_2))
	{
		keypad.keypad_value=5;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else if(PINC & (1<<COLUMN_3))
	{
		keypad.keypad_value=6;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else
	;
	PORTC &= ~(1<<PORTC1);
	
	
	
	
	PORTC |= (1<<PORTC2);
	_delay_us(2);
	if(PINC & (1<<COLUMN_1))
	{
		keypad.keypad_value=7;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else if(PINC & (1<<COLUMN_2))
	{
		keypad.keypad_value=8;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else if(PINC & (1<<COLUMN_3))
	{
		keypad.keypad_value=9;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else
	;
	PORTC &= ~(1<<PORTC2);
	
	
	
	PORTC |= (1<<PORTC3);
	_delay_us(2);
	if(PINC & (1<<COLUMN_1))
	{
		keypad.keypad_value=10;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else if(PINC & (1<<COLUMN_2))
	{
		keypad.keypad_value=0;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else if(PINC & (1<<COLUMN_3))
	{
		keypad.keypad_value=11;
		keypad.keypad_counter++;
		_delay_ms(250);
	}
	else
	;
	PORTC &= ~(1<<PORTC3);
	
	return;
}