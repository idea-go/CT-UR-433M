/*
 * This is a demo for key report using CT-UR-433M.
 */

#define KEY1    8
#define KEY2    9
#define KEY3    10
void setup() {
  // put your setup code here, to run once:
  pinMode(KEY1, INPUT);
  digitalWrite(KEY1, HIGH);
  pinMode(KEY2, INPUT);
  digitalWrite(KEY2, HIGH);
  pinMode(KEY3, INPUT);
  digitalWrite(KEY3, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(KEY1) == LOW)
  {
    Serial.print("-1:80001\r\n");
    delay(10);
  }
  if(digitalRead(KEY2) == LOW)
  {
    Serial.print("-1:80002\r\n");
    delay(10);    
  }
  if(digitalRead(KEY3) == LOW)
  {
    Serial.print("-1:80003\r\n");
    delay(10);
  }

  delay(10);
}


