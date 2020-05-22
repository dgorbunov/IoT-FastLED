#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200);           // start serial for output
}

void loop() {
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  String val;

  byte i;
  while (Wire.available()) { // loop through all but the last
    val += (char)Wire.read();
  }
  Serial.println(val);
}
