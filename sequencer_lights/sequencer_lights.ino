// int redLED = 9;
// int greenLED = 6;
// int yellowLED = 11;
// int blueLED = 12;
int leds[] = {9, 6, 11, 12};

// void allOff(){
//   for (int i = 0; i < 4; i++){
//     digitalWrite(leds[i], LOW);
//   }
// }

void lightUp(byte currentLight){
  digitalWrite(leds[currentLight -65], HIGH);
  delay(50);
  digitalWrite(leds[currentLight -65], LOW);
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 4; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    byte received = Serial.read();

    if(received >= 65 && received <= 68){
          lightUp(received);
    }

    // if(received == 69){
    //   allOff();
    // } else if(received >= 65 && received <= 68){
    //   allOff();
    //   digitalWrite(leds[received -65], HIGH);
    //   delay(200);
    // }
  }
}