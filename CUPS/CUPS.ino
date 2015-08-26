
int cup1 = A0;
int cup2 = A1;
int cup3 = A2;
int cup4 = A3;
int gross_input = A4;
int key1 = A5;
int key2 = A6;
int key3 = A7;
int key4 = A8;


int cupsPin = 9;
int ukazPin = 11;
int gross = 0;
int counter = 0;

enum state{
  CUPS,
  UKAZ  
};
state state = UKAZ;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(cup1, INPUT);
  pinMode(cup2, INPUT);
  pinMode(cup3, INPUT);
  pinMode(cup4, INPUT);
  pinMode(gross_input, INPUT);
  pinMode(cupsPin, OUTPUT);

}

void loop() {
  switch(state)
    {
      case CUPS:
        {
          if (digitalRead(cup1)==LOW and digitalRead(cup2)==LOW and digitalRead(cup3)==LOW and digitalRead(cup4)==LOW )
          {
          gross = analogRead(gross_input);
          if (gross > 770 and gross < 830)
          {
            counter++;
            Serial.println (counter);
            }
          else
            {
            counter = 0;
            digitalWrite(cupsPin, LOW);
            }
            
          Serial.println (gross);
          if (gross > 770 and gross < 830 and counter == 1024)
            {
            digitalWrite(cupsPin, HIGH);
            delay(1000);
            break;
            counter = 0;
            }
          
          }
         else
          {
           digitalWrite(cupsPin, LOW);
           delay(1000);
           break;     
          }
       }
     case UKAZ:
          if (digitalRead(key1) == LOW)
            {
              counter = 1;
              Serial.println (counter);
            }
          else if(digitalRead(key2) == LOW)
            {
              if ( counter == 1 )
                {  
                  counter = 2;
                  delay(500);
                  Serial.println (counter);
                }
              else
                counter = 0;
                Serial.println (counter);
            }
          else if (digitalRead(key3) == LOW)
            {
              if ( counter == 2 )  
                 {
                  counter = 3;
                  delay(500);
                  Serial.println (counter);
                 }
            
              else
                counter = 0;
                Serial.println (counter);
            }
          else if (digitalRead(key4) == LOW)
            {
              if ( counter == 3 )
                {
                  counter = 4;
                  delay(500);
                  Serial.println (counter);
                  digitalWrite(ukazPin, HIGH);
                  break;
                }
              else
                counter = 0;
                Serial.println (counter);                   
              
            }
    }
      
    }
 



