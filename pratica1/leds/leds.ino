int vermelho = 13;
int verde = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);

}

void acenderLed(int cor){
  digitalWrite(cor,HIGH);
}
void apagarLed(int cor){
  digitalWrite(cor,LOW);
}
void apagarTodos(){
  apagarLed(vermelho);
  apagarLed(verde);
}
void loop() {
  // put your main code here, to run repeatedly:
  apagarTodos();
  acenderLed(vermelho);
  delay(1000 * 3);
  apagarTodos();
  delay(1000 * 1);
  acenderLed(verde);
  delay(1000 * 3);
  apagarTodos();
  delay(1000 * 1);

}
