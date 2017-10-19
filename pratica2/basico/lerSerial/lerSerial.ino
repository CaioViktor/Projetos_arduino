int vermelho = 13;
int verde = 12;
int vermelhoAceso;
int verdeAceso;
void setup() {
  // put your setup code here, to run once:
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);
  Serial.begin(9600);
  vermelhoAceso = 0;
  verdeAceso = 0;
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
    int r = Serial.parseInt();
    if(r == 12 || r == 13){
       if(r==12)
        alternarLed(r,&verdeAceso);
       else
        alternarLed(r,&vermelhoAceso);
        
    }else{
      Serial.println("entrada invalida");
    }
  }

}
