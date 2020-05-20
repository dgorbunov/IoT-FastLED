#include "config.h"

#include <Wire.h>
#include <PolledTimeout.h>

#define SDA_PIN 5
#define SCL_PIN 4
const int16_t I2C_MASTER = 0x42;
const int16_t I2C_SLAVE = 0x08;

// set up the group
AdafruitIO_Group *group = io.group("google-assistant");

void setup() {

  Wire.begin(SDA_PIN, SCL_PIN, I2C_MASTER); // join i2c bus (address optional for master)
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  group->onMessage("lightstripmode", lightmode);
  group->onMessage("lightstripbrightness", brightness);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  // force IO to update our MQTT subscription with the current values of all feeds
  group->get();
}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();
}


// this function is called whenever a 'counter-1' message
// is received from Adafruit IO. it was attached to
// the counter-1 feed in the setup() function above.
void lightmode(AdafruitIO_Data *data) {
  String val = data->value();

  
  Wire.beginTransmission(I2C_SLAVE);
  Wire.write("mode ");
  Wire.write(val.c_str());
  Wire.endTransmission();
  
  delay(85);
}

// this function is called whenever a 'counter-2' message
// is received from Adafruit IO. it was attached to
// the counter-2 feed in the setup() function above.
void brightness(AdafruitIO_Data *data) {
  String val = data->value();

  Wire.beginTransmission(I2C_SLAVE);
  Wire.write("bright ");
  Wire.write(val.c_str());
  Wire.endTransmission();
  
  delay(85);
  
}
