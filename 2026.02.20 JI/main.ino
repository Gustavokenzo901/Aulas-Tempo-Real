#include <Arduino.h>

static const int LED_PIN = 2;
static bool led = false;
static unsigned long last = 0;
static unsigned long lastPrint = 0;

void blink_led (){
  unsigned long now = millis();
  
  unsigned int diff = now - last;
  if(diff >= 500){
    digitalWrite(LED_PIN, !led);
    led = !led;
    last = now;
    Serial.printf("led has blinked %lu ms\n", diff);
  }
}

  
  // Tarefa 2 - Processo alguma coisa 
  void process_anything()
  {
    unsigned long temp0 = micros();
    for(volatile long i=0; i< 50000; i++){}
    unsigned long temp1 = micros() - temp0;
    if(millis() - lastPrint >= 2000)
    {
      Serial.printf("[micros] periodo = %lu us\n", temp1);
      lastPrint = millis();
    }
  }



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blink_led(); // this speeds up the simulation
process_anything();
}

