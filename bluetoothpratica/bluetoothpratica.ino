// Programa : Controle de Leds pelo Android utilizando Bluetooth  
// Autor : Arduino e Cia  
// Modified By: Caio Viktor
//  
// Programa utilizado para controlar as portas do Arduino via celular  
// usando o programa Microcontroller BT (Android)  
// O Arduino deve estar desconectado do computador, já 
// que o módulo Bluetooth também usa a comunicação serial, o que 
// pode gerar conflito de dados.  
    
void setup()  
{  
  Serial.begin(9600);  
  //Abaixo, as portas quer serão ativadas pelo celular, via Bluetooth  
  pinMode(5,OUTPUT);  
  pinMode(6,OUTPUT);  
  pinMode(7,OUTPUT);  
}  
    
void loop()  
{  
  if(Serial.available())  
  {  
    int opcao = Serial.parseInt();
    switch(opcao){
      case 1:
        digitalWrite(5,HIGH);
      break;
      case 2:
        digitalWrite(6,HIGH);
      break;
      case 3:
        digitalWrite( 7,HIGH);
      break;
      case 4:
        digitalWrite(5,LOW);
      break;
      case 5:
        digitalWrite(6,LOW);
      break;
      case 6:
        digitalWrite(7,LOW);
      break;
      case 7:
        for(int i = 5 ; i <= 7;i++)
          digitalWrite(i,HIGH);
      break;
      default:
        for(int i = 5 ; i <= 7;i++)
          digitalWrite(i,LOW);
      break;
    }
  }  
} 
