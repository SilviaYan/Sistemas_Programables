// Tarea: Semáforo interactivo para paso de peatones

int cochesRojo = 12; // asignación variable luz roja coches
int cochesAmarillo = 11; // asignación variable luz amarilla coches
int cochesVerde = 10; // asignación variable luz verde coches
int peatRojo = 9; // asignación luz roja peatones
int peatVerde = 8; //asignación luz verde peatones
int boton = 2; // asignación del pin 2 variable botón accionamiento peatones
int pot = 1; //potenciometro
int cruceTiempo; //tiempo en el cual crusara el peaton

    void setup() {
    pinMode(cochesRojo, OUTPUT); // asignación del pin 12 como salida
    pinMode(cochesAmarillo, OUTPUT); // asignación del pin 11 como salida
    pinMode(cochesVerde, OUTPUT); // asignación del pin 10 como salida
    pinMode(peatRojo, OUTPUT); // asignación del pin 9 como salida
    pinMode(peatVerde, OUTPUT); // asignación del pin 8 como salida
    pinMode(boton, INPUT); // asignación del pin 2 como entrada
    
    digitalWrite(cochesVerde, HIGH);
    digitalWrite(peatRojo, HIGH);
    }

void loop() {
  int state = digitalRead(boton);

   if (state == HIGH) { //si se a presionado el boton se realizara el cambio de luces para el peaton 
   cambioLuces();
    }
 }

   void cambioLuces(){
    delay(5000); //espera 5 segundos antes de que pase el peaton para que pasen los coches
    digitalWrite(cochesVerde, LOW); // apaga verde coches
    digitalWrite(cochesAmarillo, HIGH); // enciende amarillo coches
    delay(2000); // el ciclo se detiene 2 segundos
    digitalWrite(cochesAmarillo, LOW); // apaga amarillo coches
    digitalWrite(cochesRojo, HIGH); // enciende rojo coches
    delay(1000); // el ciclo se detiene un segundo como precaución
    digitalWrite(peatRojo, LOW); // apaga rojo peatones
    digitalWrite(peatVerde, HIGH); // enciende verde peatones
    cruceTiempo = analogRead(pot)*8;//el cruce se detiene según el que se asigne por el potensiometro
    delay(cruceTiempo);

    for (int x=0; x<10; x++) { //Antes de pasar a rojo para los peatones, se inicia el parpadeo de la luz verde. Esto lo ejecutamos mediante un bucle for que alterna el encendido y apagado de la luz verde, a intervalos iguales de 5 segundos. Al final del bucle, la luz verde queda en estado apagado (LOW).
    digitalWrite(peatVerde, HIGH);
    delay(250);
    digitalWrite(peatVerde, LOW);
    delay(250);
    // al finalizar el bucle la luz verde peatones queda apagada

}
    //el ciclo termina de manera secuencial volviendo al estado de luz verde para vehículos y roja para peatones, con un intervalo de medio segundo entre medias.
    digitalWrite(peatRojo, HIGH); // cambio a rojo para peatones
    delay(500); // el siclo se detiene medio segundo
    digitalWrite(cochesRojo, LOW); // apaga roja coches
    digitalWrite(cochesVerde, HIGH); // enciende verde coches 

}
