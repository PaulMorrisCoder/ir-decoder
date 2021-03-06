#include <Arduino.h>
#include <IRremote.h>

int IR_RECEIVE_PIN  = 15;

void setup() {
  Serial.begin(115200);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  Serial.println();
  Serial.println(F(__FILE__ " : " __DATE__ " : " __TIME__));
  Serial.printf("IR Receive pin %i \n", IR_RECEIVE_PIN);
  Serial.println();
}

void loop() {
  if (IrReceiver.decode())
  {
    IrReceiver.printIRResultShort(&Serial);
    Serial.println();
    
    IrReceiver.resume(); // Receive the next value
    delay(300); // Delay to prevent flooding our serial output
  }
}
