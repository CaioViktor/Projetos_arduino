//Author: Caio Viktor.
int vermelho = 13;
int verde = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);
  Serial.begin(9600);
  
}

void acendeVermelho(float segundos){
  digitalWrite(vermelho,HIGH);
  if(segundos > 0){
    delay(1000 * segundos);
    digitalWrite(vermelho,LOW);
  }
} 

void acendeVerde(float segundos){
  digitalWrite(verde,HIGH);
  if(segundos > 0){
    delay(1000 * segundos);
    digitalWrite(verde,LOW);
  }
} 

void apagarLed(int led){
  switch(led){
    case 0:
        digitalWrite(vermelho,LOW);
      break;
      case 1:
        digitalWrite(verde,LOW);
      break;
  }
}

boolean espera = false;

int getVencedor(int p1,int p2){
  if(p1 == p2)
    return 0;
  if( (p1 == 0 && p2 == 2) || (p1 == 1 && p2 == 0) || (p1 == 2 && p2 == 1))
    return 1;
  return 2;
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Ola");
  if(!espera){
    Serial.println("Ola escolha sua opcao:\n\r0)Pedra\n\r1)Papel\n\r2)Tesoura");
    espera = true;
  }
  else{
    if(Serial.available()){
      int opcao = Serial.parseInt();
      if(opcao > 2 || opcao < 0){
        Serial.println("Opcao invalida");
      }else{
        int p2 = rand() % 3;
        String fala = "Eu escolho: ";
        fala.concat(p2);
        Serial.println(fala);
        switch(getVencedor(opcao,p2)){
          case 0:
            Serial.println("Empate, ja que estou pegando leve");
            acendeVermelho(0);
            acendeVerde(0);
            delay(2000);
            apagarLed(0);
            apagarLed(1);
          break;
          case 1:
            Serial.println("Droga, voce venceu por sorte");
            acendeVermelho(2);
          break;
          case 2:
            Serial.println("Hehehe, eu venci. Parece que voce precisa particar mais, humano");
            acendeVerde(2);
          break;
        }
      }
      Serial.println("\n\n---------------------------------------------");
      espera = false;
     }
  }
}
