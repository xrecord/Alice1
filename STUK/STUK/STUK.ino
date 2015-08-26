/*
 Input Pullup Serial

 This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a
 digital input on pin 2 and prints the results to the serial monitor.

 The circuit:
 * Momentary switch attached from pin 2 to ground
 * Built-in LED on pin 13

 Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
 20K-ohm resistor is pulled to 5V. This configuration causes the input to
 read HIGH when the switch is open, and LOW when it is closed.

 created 14 March 2012
 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/InputPullupSerial

 This example code is in the public domain

 */
int count = 0;
int limit = 3;
int last = 0;
int count_time = 0;
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(15, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = analogRead(15);  
  delay (50);
  //print out the value of the pushbutton
  Serial.println(sensorVal);
  if (sensorVal > 512 and last < 512 ){
    count++ ;  
    count_time = 0;  
    }
    else {
      count_time ++;
      }
  if (count_time > 7)
  {
    count = 0;
    }
    
  last = sensorVal;
  
  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (count >= limit ) {
    
    digitalWrite(2, HIGH);
    delay(3000);
    digitalWrite(4, HIGH);
    delay(3000);
    count = 0;
  }else{
     digitalWrite(2, LOW);
     digitalWrite(4, LOW);
    
  }
}



