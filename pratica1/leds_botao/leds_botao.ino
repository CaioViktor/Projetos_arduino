//Code By: Caio Viktor

int vermelho = 13;
int verde = 12;
int btVermelho = 2;
int btVerde = 7;

int ultimoEstadoVermelho,ultimoEstadoVerde;
int acesoVermelho,acesoVerde;

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

void tentarAcender(int cor,int bt,int *estado,int *aceso){
  int nivel = digitalRead(bt);
  if(nivel != *estado){
    if(nivel == HIGH){
      if(*aceso == 0){
        *aceso = 1;
        acenderLed(cor);
      }
      else{
        *aceso = 0;
        apagarLed(cor);
      }
    }
    delay(50);
  }
  *estado = nivel;
}


void setup() {
  // put your setup code here, to run once:
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(btVermelho,INPUT);
  pinMode(btVerde,INPUT);
  apagarTodos();
  ultimoEstadoVermelho = HIGH;
  ultimoEstadoVerde = HIGH;
  acesoVermelho=0;
  acesoVerde=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  tentarAcender(vermelho,btVermelho,&ultimoEstadoVermelho,&acesoVermelho);
  tentarAcender(verde,btVerde,&ultimoEstadoVerde,&acesoVerde);
  

}
