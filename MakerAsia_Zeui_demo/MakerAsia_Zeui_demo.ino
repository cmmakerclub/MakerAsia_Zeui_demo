
#include "ZEUI_LIB.h"

float mA = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(15, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {

  Turn_on ();   // turn the LED on (HIGH is the voltage level)

  delay(3000);
  mA = Read_mA_RMS();
  Serial.print("Turn ON Current = ");
  Serial.print(mA);
  Serial.print(" mA.  Power = ");
  Serial.print(mA * 0.220);
  Serial.print(" W.\n");

  Turn_off ();   // turn the LED off by making the voltage LOW

  delay(3000);
  mA = Read_mA_RMS();
  Serial.print("Turn OFF Current = ");
  Serial.print(mA);
  Serial.print(" mA.  Power = ");
  Serial.print(mA * 0.220);
  Serial.print(" W.\n");


}
