// Program to demonstrate the MD_Parola library
//
// Uses the Arduino Print Class extension with various output types
//
// MD_MAX72XX library can be found at https://github.com/MajicDesigns/MD_MAX72XX
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

const uint16_t WAIT_TIME = 1000;

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  P.begin();
  Serial.begin(9600);
  P.print("           ");
  P.print(" Client 2");
}

void loop(void)
{
   char TestData;
   TestData = Serial.read();
     // echo the incoming character to the LCD
 
   if(TestData=='1')
   {
      P.print("           ");
      P.print(" T1");
    }
   else if(TestData=='2')
   {
      P.print("           ");
      P.print(" T2");
   }
    else if(TestData=='3')
   {
      P.print("           ");
      P.print(" T3");
   }
    else if(TestData=='4')
   {
      P.print("           ");
      P.print(" T4");
   }
}
