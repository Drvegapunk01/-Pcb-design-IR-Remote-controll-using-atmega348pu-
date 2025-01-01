#include<IRremote.h>

const int PinIR = 4, LED = 13;
bool state = 0;
IRrecv recv(PinIR);
decode_results hasil;

void setup() {
pinMode(LED,OUTPUT);
Serial.begin(9600);
recv.enableIRIn();
}

void loop() {
if(recv.decode(&hasil)){
  Serial.println(hasil.value);
 state = !state;
digitalWrite(LED, state); 
  recv.resume();
}
}
