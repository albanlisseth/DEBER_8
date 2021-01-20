// este programa reinicia el Uc cada minuto y lo mantiene en modo espera hasta leer un vlor analógico
#include "LowPower.h"
int indicador=13;
int reset=12;
int i=0;
int datos=0;
unsigned long tiempo;
void setup()
{
Serial.begin(9600);
pinMode(reset,OUTPUT);
pinMode(indicador,OUTPUT);
} 
void loop()
{
digitalWrite(indicador,LOW);
tiempo=millis();
if (tiempo<(60000-50))
{
LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_ON, TIMER1_ON, TIMER0_ON,SPI_OFF, USART0_OFF, TWI_OFF);
}
else
{
digitalWrite(indicador,HIGH);
datos=analogRead(0);
Serial.println(datos);
delay(50);
asm("jmp 0x0000");
}
}
