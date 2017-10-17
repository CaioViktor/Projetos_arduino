void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void alternarLed(int led,int *estado){
  if(*estado == 0){
    *estado = 1;
    digitalWrite(led,HIGH);
    
  } else{
    *estado = 0;
    digitalWrite(led,LOW);
     
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    //String str = Serial.readString(); //ler Uma string
    Serial.write(Serial.read());
  }

}
