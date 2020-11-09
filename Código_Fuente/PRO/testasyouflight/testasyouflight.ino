//Initializing LED Pin
#define PWMX 2  //se usa el PWMX PARA EL GIRO (esta decisión es arbitraria) 
#define PWMY 3
#define PWMZ 4
#define PWMW 5 
#define sentidoAX1  22
#define sentidoBX1  23
#define sentidoAX2  24
#define sentidoBX2  25

#define sentidoAY1  28
#define sentidoBY1  29
#define sentidoAY2  30
#define sentidoBY2  31

#define sentidoAZ0  34
#define sentidoBZ0  35

long randEje;
long randSentido;
long randTiempo;
long randDutycycle;

void setup() {

  pinMode(PWMX, OUTPUT);
  pinMode(PWMY, OUTPUT);
  pinMode(PWMZ, OUTPUT);
  pinMode(PWMW, OUTPUT);
  pinMode(sentidoAX1,OUTPUT);
  pinMode(sentidoBX1,OUTPUT);
  pinMode(sentidoAX2,OUTPUT);
  pinMode(sentidoBX2,OUTPUT);
  
  pinMode(sentidoAY1,OUTPUT);
  pinMode(sentidoBY1,OUTPUT);
  pinMode(sentidoAY2,OUTPUT);
  pinMode(sentidoBY2,OUTPUT);
  
  pinMode(sentidoAZ0,OUTPUT);
  pinMode(sentidoBZ0,OUTPUT);

  randomSeed(analogRead(0));
  Serial.begin(9600);
  
}

void tipodemaniobra(int eje,int sentido,int dutycycle){ //eje: x=1; y=2; z=3, giro = 4 sentido          1=adelante/horario ; -1=atras/antihorario ;
//configuro el sentido de rotacion de los motores segun el eje y sentido
  switch(eje){
    case 1:{ //eje x
          if(sentido == 1){  
            digitalWrite(sentidoAX1, HIGH);
            digitalWrite(sentidoBX1, LOW);
            digitalWrite(sentidoAX2, HIGH); 
            digitalWrite(sentidoBX2, LOW);
          }else if(sentido == -1){
            digitalWrite(sentidoAX1, LOW);
            digitalWrite(sentidoBX1, HIGH);
            digitalWrite(sentidoAX2, LOW); 
            digitalWrite(sentidoBX2, HIGH);
          }
          analogWrite(PWMX, dutycycle);
    }break;
    case 2:{ //eje y
          if(sentido == 1){
            digitalWrite(sentidoAY1, HIGH);
            digitalWrite(sentidoBY1, LOW);
            digitalWrite(sentidoAY2, HIGH); 
            digitalWrite(sentidoBY2, LOW);
          }else if(sentido == -1){
            digitalWrite(sentidoAY1, LOW);
            digitalWrite(sentidoBY1, HIGH);
            digitalWrite(sentidoAY2, LOW); 
            digitalWrite(sentidoBY2, HIGH);
          }
          analogWrite(PWMY, dutycycle);
      
    }break;
    case 3:{  //eje z
          if(sentido == 1){
            digitalWrite(sentidoAZ0, HIGH);
            digitalWrite(sentidoBZ0, LOW);
            
          }else if(sentido == -1){
            digitalWrite(sentidoAZ0, LOW);
            digitalWrite(sentidoBZ0, HIGH);
          }
          analogWrite(PWMZ, dutycycle);
    }break;

    case 4:{  //giro
          if(sentido == 1){  //horario
            digitalWrite(sentidoAX1, HIGH);
            digitalWrite(sentidoBX1, LOW);
            digitalWrite(sentidoAX2, LOW); 
            digitalWrite(sentidoBX2, HIGH);
            digitalWrite(sentidoAY1, HIGH);
            digitalWrite(sentidoBY1, LOW);
            digitalWrite(sentidoAY2, LOW); 
            digitalWrite(sentidoBY2, HIGH);
          }else if(sentido == -1){      
            digitalWrite(sentidoAX1, LOW);
            digitalWrite(sentidoBX1, HIGH);
            digitalWrite(sentidoAX2, HIGH); 
            digitalWrite(sentidoBX2, LOW);
            digitalWrite(sentidoAY1, LOW);
            digitalWrite(sentidoBY1, HIGH);
            digitalWrite(sentidoAY2, HIGH); 
            digitalWrite(sentidoBY2, LOW);
          }  
          analogWrite(PWMX, dutycycle);
          analogWrite(PWMY, dutycycle);
    }break;
    default:{
      Serial.print("no se reconoce el comando"); 
    }
  }

}

void loop() { //eje: x=1; y=2; z=3, giro = 4 sentido; 1=adelante/horario ; -1=atras/antihorario ; visto desde techo de carpa 
int sentido = 0;
  //aca los imputs serian que maniobra hacer , con que dutycycle el pwm

  randEje = random(1,5);
  randSentido = random(-1,1);
  randDutycycle = random(150,255);
  randTiempo = random(30000);
  Serial.print("Eje = ");
  Serial.println(round(randEje));
  Serial.print("Sentido = ");
  Serial.println(round(randSentido));
  Serial.print("Duty = ");
  Serial.println(round(randDutycycle));
  Serial.print("Tiempo = ");
  Serial.println(round(randTiempo));
  
  if(round(randSentido)>0){
    sentido = 1;
  }else{
    sentido = -1;
  }
  tipodemaniobra(round(randEje),sentido, round(randDutycycle));
  delay(round(randTiempo));

}
