/*
  Blink
  Acende um LED por um segundo, depois apaga por um segundo, repetidamente.
  A maioria dos Arduinos tem um LED integrado que você pode controlar. No UNO, MEGA e ZERO
  ele está conectado ao pino digital 13, no MKR1000 no pino 6. LED_BUILTIN é definido como
  o pino de LED correto, independentemente de qual placa é usada.
  Se você quiser saber em qual pino o LED on-board está conectado no seu modelo Arduino, verifique
  as especificações técnicas da sua placa em https://www.arduino.cc/en/Main/Products
  
  Este código de exemplo é de domínio público.
*/


// A função de configuração é executada uma vez quando você pressiona reset ou liga a placa
void configuração() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
}

// A função de loop é executada repetidamente para sempre
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
