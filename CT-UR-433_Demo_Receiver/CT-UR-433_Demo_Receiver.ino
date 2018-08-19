/*
 * This is a demo of remote receiver using CT-UR-433M.
 * It receive data from the remote and then control the LED
 */

#define LED     13

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
unsigned int tick;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (stringComplete) {
    if(inputString == "-1:80001\r\n") {     //check the receive data is KEY1
      digitalWrite(LED, HIGH);    //LED ON
    }
    else if(inputString == "-1:80002\r\n") {  //check the receive data is KEY2
      digitalWrite(LED, LOW);     //LED OFF
    }
    else if(inputString == "-1:80003\r\n") {  //check the receive data is KEY3
      if((millis() - tick) >= 1500)  //to ignore the repeat data
      {
        digitalWrite(LED, !digitalRead(LED)); //toggle the LED
      }
      tick = millis();
    }
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
 * Serial receive handler
 * Receive all the data come from CT-UR-433M and save to inputString
 * Once the \r\n come, then set the complete flag
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if(inChar == '\r') {
    }
    else if (inChar == '\n') {
      stringComplete = true;
    }
  }
}



