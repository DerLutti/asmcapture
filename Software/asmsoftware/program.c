/*
ASM program
program.c
created by
Philipp Mandl
Florian Luttenberger
copyright by: ABOVE

create date 05.05.2020
*/

#include "src/asm/asmcapture.h"

#include <stdio.h>

#include "src/mcp/MCP3208.h"
#include <SPI.h>

#include <wiringPi.h>
#include <iostream>
#include <string>

MCP3208 adc(10);
ASM motor(NULL,NULL);

#define CURRENT_SENSOR 1//pin angeben
#define VOLTAGE_SENSOR 2//pin angeben



int main()
{
   pinMode(CURRENT_SENSOR, INPUT);
   while (/* condition */)
   {
      if (/* start */)
      {
         ASM motor(NULL,NULL);
         //Motor starten
         //motor.begin();

adc.begin();
         while (motor läuft)
         {

            //amplitude_current = (float)sensor_max / 1024 * 5 / 800 * 2000000;
            //effective_value = amplitude_current / 1.414; //minimum_current=1/1024*5/800*2000000/1.414=8.6(mA)

            motor.messwerte(adc.analogRead(CURRENT_SENSOR), adc.analogRead(VOLTAGE_SENSOR));
         }
         motor.stop();
         motor.getresult zeichnen oder ausgeben
      }
   }

   return 0;
}