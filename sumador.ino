int estadojugador = 0;
int jverde = 13; //jugador2
int jazul = 12;  //jugador1
int rojo= 2;   //suma 1
int amarillo= 3;
int verde= 4;
int marron=5;
int azul= 6;
int rosa= 7;
int negro= 8;   //suma 7
int cambiojugador= 9;
int restar= 10;
int falta= 11;
int suma=0;
int suma2= 0;
int valorronda = 0;
int valormax1;
int valormax2;
int pinBuzzer = 18;
unsigned long tiempo, horas, minutos, segundos;  //para mostrar el tiempo en horas/min/seg.
long tiempo1 = 0;  // variable de tiempo para inicio
long tiempo2 = 0;  // variable de tiempo para final


void setup() 
{

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, OUTPUT);    //azul
  pinMode(13, OUTPUT);     //verde
  pinMode(18, OUTPUT); 
  digitalWrite(jverde,LOW);  // activamos jugador 1
  digitalWrite(jazul,HIGH);
  Serial.begin(9600);
 
}

void loop(){
  
{
if (digitalRead(9) == LOW){
    tiempo1 = millis();
    estadojugador++;
   delay(300);
if (estadojugador == 2){
    estadojugador=0;
   delay(300);
  }

switch(estadojugador){
  
  case 0:         // si estado es 0,juega el azul
  
if (valorronda <= valormax2){
   Serial.print("PUNTUACION MAXIMA JUGADOR 2  =  ");
   Serial.println(valormax2);
} 
 if (valorronda > valormax2){
   valormax2 = valorronda;
   Serial.print("NEW RECORD JUGADOR 2  =  ");
   Serial.println(valormax2);
 }
   Serial.print("jugador verde:  ");
   Serial.print(suma);
   Serial.print("  /  jugador azul:   ");
   Serial.print(suma2);
   Serial.print("    /    valor maximo 2  =  ");
   Serial.println(valormax2);
   Serial.println("TURNO JUGADOR 1  ");
  
   tone(pinBuzzer, 400);
   delay(300);
   tone(pinBuzzer, 500);
   delay(300);
   noTone(pinBuzzer);
   delay(300);
   digitalWrite(jverde,LOW);
   digitalWrite(jazul,HIGH);

   valorronda = 0;

  break;
 
  case 1:          // si estado es 0,juega el verde

 if (valorronda <= valormax1){
 
   Serial.print("PUNTUACION MAXIMA JUGADOR 1  =  ");
   Serial.println(valormax1);
  }

  if (valorronda > valormax1){
   valormax1 = valorronda;
   Serial.print("NEW RECORD JUGADOR 1  = ");
   Serial.println(valormax1);
  }

   Serial.print("jugador verde:  ");
   Serial.print(suma);
   Serial.print("  /  jugador azul:   ");
   Serial.print(suma2); 
   Serial.print("    /    valor maximo 1  =  ");
   Serial.println(valormax1);
   Serial.println("TURNO JUGADOR 2  ");

   tone(pinBuzzer, 500);
   delay(300);
   tone(pinBuzzer, 400);
   delay(300);
   noTone(pinBuzzer);
   delay(300);
   digitalWrite(jverde,HIGH);
   digitalWrite(jazul,LOW);

  valorronda = 0;
 }
 }
 if (digitalRead(rojo) == LOW){
   tiempo1 = millis(); 
 if (estadojugador == 0){       //si esta seleccionado jugador 1
   suma=suma+1;
   valorronda=valorronda+1;
  }
 if (estadojugador == 1){
   suma2=suma2+1;
   valorronda=valorronda+1;
  }
   tone(pinBuzzer, 600 , 400);
   delay(400);
   noTone(pinBuzzer);
   Serial.print("jugador verde:  ");
   Serial.print(suma);
   Serial.print("  /  jugador azul:   ");
   Serial.print(suma2);
   Serial.print("    valor ronda = ");
   Serial.println(valorronda);
   delay(500);
  }

 if (digitalRead(amarillo) == LOW){
   tiempo1 = millis(); 
 if (estadojugador == 0){       //si esta seleccionado jugador 1
   suma=suma+2;
   valorronda=valorronda+2;
  }
 if (estadojugador == 1){
   suma2=suma2+2;
   valorronda=valorronda+2;
  }
   tone(pinBuzzer, 600);
   delay(300);
   tone(pinBuzzer, 700 , 300);
   delay(300);
   noTone(pinBuzzer);
   
   Serial.print("jugador verde:  ");
   Serial.print(suma);
   Serial.print("  /  jugador azul:   ");
   Serial.print(suma2);
   Serial.print("    valor ronda = ");
   Serial.println(valorronda);
   
   delay(500);
  }

 if (digitalRead(verde) == LOW){
    tiempo1 = millis(); 
 if (estadojugador == 0){       //si esta seleccionado jugador 1
    suma=suma+3;
    valorronda=valorronda+3;
  }
 if (estadojugador == 1){
    suma2=suma2+3;
    valorronda=valorronda+3;
  }
    tone(pinBuzzer, 600);
    delay(200);
    tone(pinBuzzer, 700);
    delay(200);
    tone(pinBuzzer, 800 , 200);
    delay(200);
    noTone(pinBuzzer);
   
    Serial.print("jugador verde:  ");
    Serial.print(suma);
    Serial.print("  /  jugador azul:   ");
    Serial.print(suma2);
    Serial.print("    valor ronda = ");
    Serial.println(valorronda);
    delay(500);
  }

 if (digitalRead(marron) == LOW){
   tiempo1 = millis(); 
   
  if (estadojugador == 0){       //si esta seleccionado jugador 1
    suma=suma+4;
    valorronda=valorronda+4;
  }
 if (estadojugador == 1){
    suma2=suma2+4;
    valorronda=valorronda+4;
 } 
    tone(pinBuzzer, 600);
    delay(200);
    tone(pinBuzzer, 700);
    delay(200);
    tone(pinBuzzer, 800);
    delay(200);
    tone(pinBuzzer, 900 , 200);
    delay(200);
    noTone(pinBuzzer);
  
    Serial.print("jugador verde:  ");
    Serial.print(suma);
    Serial.print("  /  jugador azul:   ");
    Serial.print(suma2);
    Serial.print("    valor ronda = ");
    Serial.println(valorronda);
    delay(500);
  }

 if (digitalRead(azul) == LOW){
    tiempo1 = millis();
    
 if (estadojugador == 0){       //si esta seleccionado jugador 1
    suma=suma+5;
    valorronda=valorronda+5;
  }
 if (estadojugador == 1){
    suma2=suma2+5;
    valorronda=valorronda+5;
  }
   tone(pinBuzzer, 600);
   delay(150);
   tone(pinBuzzer, 700);
   delay(150);
   tone(pinBuzzer, 800);
   delay(150);
   tone(pinBuzzer, 900);
   delay(150);
   tone(pinBuzzer, 1000 , 150);
   delay(150);
   noTone(pinBuzzer);
  
   Serial.print("jugador verde:  ");
   Serial.print(suma);
   Serial.print("  /  jugador azul:   ");
   Serial.print(suma2);
   Serial.print("    valor ronda = ");
   Serial.println(valorronda);
   delay(500);
  }

 if (digitalRead(rosa) == LOW){
    tiempo1 = millis(); 
 if (estadojugador == 0){       //si esta seleccionado jugador 1
    suma=suma+6;
    valorronda=valorronda+6;
  }
 if (estadojugador == 1){
    suma2=suma2+6;
    valorronda=valorronda+6;
 }  
    tone(pinBuzzer, 600);
    delay(130);
    tone(pinBuzzer, 700);
    delay(130);
    tone(pinBuzzer, 800);
    delay(130);
    tone(pinBuzzer, 900);
    delay(130);
    tone(pinBuzzer, 1000);
    delay(130);
    tone(pinBuzzer, 1100 , 130);
    delay(130);
    noTone(pinBuzzer);
    Serial.print("jugador verde:  ");
    Serial.print(suma);
    Serial.print("  /  jugador azul:   ");
    Serial.print(suma2);
    Serial.print("    valor ronda = ");
    Serial.println(valorronda);
    delay(500);
 }

 if (digitalRead(negro) == LOW){
   tiempo1 = millis(); 
 if (estadojugador == 0){       //si esta seleccionado jugador 1
    suma=suma+7;
    valorronda=valorronda+7;
  }
 if (estadojugador == 1){
    suma2=suma2+7;
    valorronda=valorronda+7;
  }
    tone(pinBuzzer, 600);
    delay(100);
    tone(pinBuzzer, 700);
    delay(100);
    tone(pinBuzzer, 800);
    delay(100);
    tone(pinBuzzer, 900);
    delay(100);
    tone(pinBuzzer, 1000);
    delay(100);
    tone(pinBuzzer, 1100);
    delay(100);
    tone(pinBuzzer, 1200 , 100);
    delay(100);
    noTone(pinBuzzer);
    
    Serial.print("jugador verde:  ");
    Serial.print(suma);
    Serial.print("  /  jugador azul:   ");
    Serial.print(suma2);
    Serial.print("    valor ronda = ");
    Serial.println(valorronda);
    delay(500);
  }

 if (digitalRead(restar) == LOW){
 if (estadojugador == 0)       //si esta seleccionado jugador 1
 if (0 < suma)
    {suma=suma-1;}
 if (estadojugador == 1)
 if (0 < suma2)
 {suma2=suma2-1;}
 
   tone(pinBuzzer, 600);
   delay(100);
   tone(pinBuzzer, 500);
   delay(100);
   tone(pinBuzzer, 400);
   delay(100);
   noTone(pinBuzzer);
   Serial.print("jugador verde:  ");
   Serial.print(suma);
   Serial.print("  /  jugador azul:   ");
   Serial.print(suma2);
   Serial.println(" RESTAR 1 ");
   delay(500);
 }

if (digitalRead(falta) == LOW){
   tiempo1 = millis(); 
 if (estadojugador == 0)       //si esta seleccionado jugador 1
   {suma2=suma2+4;}
 if (estadojugador == 1)
   {suma=suma+4;}
    tone(pinBuzzer, 523);
    delay(800);
    tone(pinBuzzer, 440);
    delay(700);
    noTone(pinBuzzer);
    delay(300);
    
    Serial.print("jugador verde:  ");
    Serial.print(suma);
    Serial.print("  /  jugador azul:   ");
    Serial.print(suma2);
    Serial.println(" FALTA 4 PUNTOS PENALIZACION ");
    delay(500);

}
 }}
 
