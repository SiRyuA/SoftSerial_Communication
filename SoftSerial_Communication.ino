#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13); // RX12 TX13

String Message_read;
boolean Message_end = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(4800);

  Serial.println("START");
  mySerial.println("Hi");
}

void loop() {
  // put your main code here, to run repeatedly:

  while(Serial.available()){
    char Message_data = Serial.read();
    mySerial.print(Message_data);
    
    if(Message_data == ';'){
      Serial.println(Message_data);
    }else Serial.print(Message_data);
  }
  delay(20);

  while(mySerial.available()){
    char Message_data = mySerial.read();

    if(Message_data == ';'){
      Serial.println(Message_data);
    }else Serial.print(Message_data);
    
  }
  delay(20); 
}
