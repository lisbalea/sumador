
#define NOTE_D5  587
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_CS6 1109
#define NOTE_DS6 1245

int melodia[] = {    // array con las notas de la melodia
  NOTE_D5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_DS6
};
int duraciones[] = {    // array con la duracion de cada nota
  8, 8, 8, 8, 8, 8, 8,
};

int estadojugador = 0;   //guarda nº de jugador 0 o 1
int jverde = 13;         //led ilumina turno jugador1
int jazul = 12;          //led ilumina turno jugador2
int rojo = 2;     //suma 1
int amarillo = 3; //suma 2
int verde = 4;    //suma 3
int marron = 5;   //suma 4
int azul = 6;     //suma 5
int rosa = 7;     //suma 6
int negro = 8;    //suma 7
int cambiojugador = 9; //pulsador cambia de jugador
int restar = 10;  //resta un punto
int falta = 11;   //suma 4 al contrario
int suma = 0;     //guarda puntos jugador 1
int suma2 = 0;    //guarda puntos jugador 2
int valorronda = 0;  //valor de la ronda activa
int valormax1;       //RECORD de ronda del jugador 1
int valormax2;       //RECORD de ronda del jugador 2
int pinBuzzer = 18;  //buzzer
unsigned long tiempoanterior = 0;    //guarda tiempo de referencia para comparar
int intervalodelay = 300;            //usado en lugar de delay(500)



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
  digitalWrite(jverde, LOW); // activamos jugador 1
  digitalWrite(jazul, HIGH);
  Serial.begin(9600);

}

void loop() {

  if (millis() -  tiempoanterior >= intervalodelay ) {


    if (digitalRead(9) == LOW) {
      estadojugador++;

      if (estadojugador == 2) {
        estadojugador = 0;
      }

      switch (estadojugador) {

        case 0:         // si estado es 0,juega el azul



          if (valorronda <= valormax2) {
            Serial.print("PUNTUACION MAXIMA JUGADOR 2  =  ");
            Serial.println(valormax2);
          }
          if (valorronda > valormax2) {
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

          for (int i = 0; i < 2; i++) {     // bucle repite x veces
            int duracion = 2000 / duraciones[i];    // duracion de la nota en milisegundos
            tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
            int pausa = duracion * 1.80;      // calcula pausa
            delay(pausa);         // demora con valor de pausa
            noTone(pinBuzzer);        // detiene reproduccion de tono
          }
          digitalWrite(jverde, LOW);
          digitalWrite(jazul, HIGH);

          valorronda = 0;
          tiempoanterior = millis();


          break;

        case 1:          // si estado es 0,juega el verde



          if (valorronda <= valormax1) {

            Serial.print("PUNTUACION MAXIMA JUGADOR 1  =  ");
            Serial.println(valormax1);
          }

          if (valorronda > valormax1) {
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

          for (int i = 2; i > 0; i--) {      // bucle repite x veces
            int duracion = 2000 / duraciones[i];    // duracion de la nota en milisegundos
            tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
            int pausa = duracion * 1.80;      // calcula pausa
            delay(pausa);         // demora con valor de pausa
            noTone(pinBuzzer);        // detiene reproduccion de tono
          }
          digitalWrite(jverde, HIGH);
          digitalWrite(jazul, LOW);

          valorronda = 0;
          tiempoanterior = millis();

      }
    }

    if (millis() -  tiempoanterior >= intervalodelay ) {

      if (digitalRead(rojo) == LOW) {

        if (estadojugador == 0) {      //si esta seleccionado jugador 1
          suma = suma + 1;
          valorronda = valorronda + 1;
        }
        if (estadojugador == 1) {
          suma2 = suma2 + 1;
          valorronda = valorronda + 1;
        }
        for (int i = 0; i < 1; i++) {      // bucle repite x veces
          int duracion = 1000 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.30;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }
        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.print("    valor ronda = ");
        Serial.println(valorronda);

      }

      if (digitalRead(amarillo) == LOW) {

        if (estadojugador == 0) {      //si esta seleccionado jugador 1
          suma = suma + 2;
          valorronda = valorronda + 2;
        }
        if (estadojugador == 1) {
          suma2 = suma2 + 2;
          valorronda = valorronda + 2;
        }
        for (int i = 0; i < 2; i++) {     // bucle repite x veces
          int duracion = 600 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.30;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }

        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.print("    valor ronda = ");
        Serial.println(valorronda);


      }

      if (digitalRead(verde) == LOW) {

        if (estadojugador == 0) {      //si esta seleccionado jugador 1
          suma = suma + 3;
          valorronda = valorronda + 3;
        }
        if (estadojugador == 1) {
          suma2 = suma2 + 3;
          valorronda = valorronda + 3;
        }
        for (int i = 0; i < 3; i++) {     // bucle repite x veces
          int duracion = 600 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.30;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }

        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.print("    valor ronda = ");
        Serial.println(valorronda);

      }

      if (digitalRead(marron) == LOW) {


        if (estadojugador == 0) {      //si esta seleccionado jugador 1
          suma = suma + 4;
          valorronda = valorronda + 4;
        }
        if (estadojugador == 1) {
          suma2 = suma2 + 4;
          valorronda = valorronda + 4;
        }
        for (int i = 0; i < 4; i++) {     // bucle repite x veces
          int duracion = 600 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.30;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }

        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.print("    valor ronda = ");
        Serial.println(valorronda);

      }

      if (digitalRead(azul) == LOW) {


        if (estadojugador == 0) {      //si esta seleccionado jugador 1
          suma = suma + 5;
          valorronda = valorronda + 5;
        }
        if (estadojugador == 1) {
          suma2 = suma2 + 5;
          valorronda = valorronda + 5;
        }
        for (int i = 0; i < 5; i++) {     // bucle repite x veces
          int duracion = 600 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.30;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }

        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.print("    valor ronda = ");
        Serial.println(valorronda);

      }

      if (digitalRead(rosa) == LOW) {

        if (estadojugador == 0) {      //si esta seleccionado jugador 1
          suma = suma + 6;
          valorronda = valorronda + 6;
        }
        if (estadojugador == 1) {
          suma2 = suma2 + 6;
          valorronda = valorronda + 6;
        }
        for (int i = 0; i < 6; i++) {     // bucle repite x veces
          int duracion = 600 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.30;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }
        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.print("    valor ronda = ");
        Serial.println(valorronda);

      }

      if (digitalRead(negro) == LOW) {

        if (estadojugador == 0) {      //si esta seleccionado jugador 1
          suma = suma + 7;
          valorronda = valorronda + 7;
        }
        if (estadojugador == 1) {
          suma2 = suma2 + 7;
          valorronda = valorronda + 7;
        }
        for (int i = 0; i < 7; i++) {     // bucle repite x veces
          int duracion = 600 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.30;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }

        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.print("    valor ronda = ");
        Serial.println(valorronda);

      }

      if (digitalRead(restar) == LOW) {
        if (estadojugador == 0)       //si esta seleccionado jugador 1
          if (0 < suma)
          {
            suma = suma - 1;
          }
        if (estadojugador == 1)
          if (0 < suma2)
          {
            suma2 = suma2 - 1;
          }


        for (int i = 3; i > 0; i--) {      // bucle repite x veces
          int duracion = 400 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.80;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }

        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.println(" RESTAR 1 ");

      }

      if (digitalRead(falta) == LOW) {
        if (estadojugador == 0)       //si esta seleccionado jugador 1
        {
          suma2 = suma2 + 4;
        }
        if (estadojugador == 1)
        {
          suma = suma + 4;
        }
        for (int i = 5; i > 2; i--) {      // bucle repite x veces
          int duracion = 400 / duraciones[i];    // duracion de la nota en milisegundos
          tone(pinBuzzer, melodia[i], duracion);  // ejecuta el tono con la duracion
          int pausa = duracion * 1.80;      // calcula pausa
          delay(pausa);         // demora con valor de pausa
          noTone(pinBuzzer);        // detiene reproduccion de tono
        }

        Serial.print("jugador verde:  ");
        Serial.print(suma);
        Serial.print("  /  jugador azul:   ");
        Serial.print(suma2);
        Serial.println(" FALTA 4 PUNTOS PENALIZACION ");
      }

      tiempoanterior = millis();

    }
  }
}
