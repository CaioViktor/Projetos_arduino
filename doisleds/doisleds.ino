//Code By: Caio Viktor
int vermelho = 13;
int verde = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);
}

void acendeVermelho(int segundos){
  digitalWrite(vermelho,HIGH);
  delay(1000 * segundos);
  digitalWrite(vermelho,LOW);
} 

void acendeVerde(int segundos){
  digitalWrite(verde,HIGH);
  delay(1000 * segundos);
  digitalWrite(verde,LOW);
} 

void loop() {
  // put your main code here, to run repeatedly:
  acendeVermelho(1);
  acendeVerde(1);
}
