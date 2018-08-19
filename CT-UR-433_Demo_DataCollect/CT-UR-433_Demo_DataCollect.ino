/*
 * This is a demo for data collect using CT-UR-433M.
 * The data is coming from the A0 port's analog level.
 */

#define ADDRESS   1   //485 Address, please keep it the same with the address selector on board

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  
  String str = "-";   //Add report head
  str += ADDRESS;     //Add RS485 address
  str += ":";         //Add :
  str += value;       //Add the value
  str += "\r\n";      //Add tail
  Serial.print(str);  //Write to CT-UR-433M
  
  delay(1000);
}


