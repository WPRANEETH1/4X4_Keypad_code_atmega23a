#include<avr/io.h>
#define	F_CPU	1000000
#include<util/delay.h>
#define		KEYPAD_PORT		PORTC
#define		KEYPAD_PIN		PINC
//#include<avr/keypad.h>
#define		LCD_DATA_PORT		PORTA
#define 	LCD_CONT_PORT		PORTD
#define 	LCD_RS 		PD0
#define 	LCD_RW 		PD1
#define 	LCD_EN 		PD2
#include<avr/lcd.h>
#include "keypad.h"


int main(void)
{
	MCUCSR=(1<<JTD);
	MCUCSR=(1<<JTD);
	
	keypad.keypad_counter=0;
	keypad.keypad_value=0;
	//DDRC=0x0f;
	//PORTC=0xff;
	DDRB=0x0f;
	DDRA=0xff;
	DDRD=0xff;
	unsigned char keypad_value,count=0;
	char password_entered[5];
	char password_set = "1";
	char status=0;

	lcd_init();
	keypad_init();
	lcd_string_write("Coin Counter");
	lcd_command_write(0xc1);
	lcd_string_write("Group-2");

	_delay_ms(500);
	_delay_ms(500);
	_delay_ms(500);
	_delay_ms(500);

	lcd_command_write(0x01);

	lcd_string_write("Enter key to start:");
	

		while(count<1)
		{
			keypad.keypad_counter=0;
			keypad_read();
			if(keypad.keypad_counter > 0)
			{	
				lcd_command_write(0xc1);
				lcd_string_write("*");
				_delay_ms(500);				
				lcd_command_write(0xc1);
				if(keypad.keypad_value == 1)
				{
					lcd_command_write(0x01);
					lcd_string_write("Key Correct");
					
					count++;					
										
					_delay_ms(500);
					_delay_ms(500);
				}	
				else
				{
					lcd_command_write(0x01);
					lcd_string_write("Wrong key");
					_delay_ms(500);
					_delay_ms(500);
					_delay_ms(500);
					_delay_ms(500);
					lcd_command_write(0x01);
					lcd_string_write("Reenter Key:");
				}			
			}	
			//break;		
		}
		
while(status == 0)
	{					
		lcd_command_write(0x01);
		lcd_string_write("Press 2,4,6,8,5");
	
	while(1)
	{
		
		lcd_command_write(0xC0);
		
		keypad_read();
		if(keypad.keypad_counter > 0)
		{
			keypad.keypad_counter = 0;
			
			if(keypad.keypad_value == 2)
			{
				lcd_string_write("Counting RS:1 coins ");
				keypad.keypad_value = 0;
				keypad.keypad_counter = 0;				
				lcd_string_write("No of Coins:");
				while(1){
				keypad_read();
				if(keypad.keypad_counter > 0)
				{
					lcd_number_write(keypad.keypad_value,10);
					for(int i=0; i<keypad.keypad_value; i++)
					{
						PORTB=0x01;
						_delay_ms(500);
						PORTB=0x00;
						_delay_ms(500);
					}	
					lcd_command_write(0x01);
					lcd_string_write("Stopped counting");
					_delay_ms(500);
					_delay_ms(500);
					lcd_command_write(0x01);
					lcd_string_write("Press 2,4,6,8,5");
					keypad.keypad_value = 0;			
					break;
				}
				}
			}
			
			if(keypad.keypad_value == 4)
			{
				lcd_string_write("Counting RS:2 coins ");
				keypad.keypad_value = 0;
				keypad.keypad_counter = 0;
				lcd_string_write("No of Coins:");
				while(1){
					keypad_read();
					if(keypad.keypad_counter > 0)
					{
						lcd_number_write(keypad.keypad_value,10);
						for(int i=0; i<keypad.keypad_value; i++)
						{
							PORTB=0x02;
							_delay_ms(500);
							PORTB=0x00;
							_delay_ms(500);
						}
						lcd_command_write(0x01);
						lcd_string_write("Stopped counting");
						_delay_ms(500);
						_delay_ms(500);
						lcd_command_write(0x01);
						lcd_string_write("Press 2,4,6,8,5");
						keypad.keypad_value = 0;
						break;
					}
				}
			}
			
			if(keypad.keypad_value == 6)
			{
				lcd_string_write("Counting RS:5 coins ");
				keypad.keypad_value = 0;
				keypad.keypad_counter = 0;
				lcd_string_write("No of Coins:");
				while(1){
					keypad_read();
					if(keypad.keypad_counter > 0)
					{
						lcd_number_write(keypad.keypad_value,10);
						for(int i=0; i<keypad.keypad_value; i++)
						{
							PORTB=0x04;
							_delay_ms(500);
							PORTB=0x00;
							_delay_ms(500);
						}
						lcd_command_write(0x01);
						lcd_string_write("Stopped counting");
						_delay_ms(500);
						_delay_ms(500);
						lcd_command_write(0x01);
						lcd_string_write("Press 2,4,6,8,5");
						keypad.keypad_value = 0;
						break;
					}
				}
			}
			
			if(keypad.keypad_value == 8)
			{
				lcd_string_write("Counting RS:10 coins");
				keypad.keypad_value = 0;
				keypad.keypad_counter = 0;
				lcd_string_write("No of Coins:");
				while(1){
					keypad_read();
					if(keypad.keypad_counter > 0)
					{
						lcd_number_write(keypad.keypad_value,10);
						for(int i=0; i<keypad.keypad_value; i++)
						{
							PORTB=0x08;
							_delay_ms(500);
							PORTB=0x00;
							_delay_ms(500);
						}
						lcd_command_write(0x01);
						lcd_string_write("Stopped counting");
						_delay_ms(500);
						_delay_ms(500);
						lcd_command_write(0x01);
						lcd_string_write("Press 2,4,6,8,5");
						keypad.keypad_value = 0;
						break;
					}
				}
			}
			
			if(keypad.keypad_value == 5)
			{
				lcd_string_write("Stopped counting   ");
			}
		}
	}
	}
}
