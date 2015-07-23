#include "Timer.h"

Timer<3> t; // max number of timer 3

void setup()
{
  Serial.begin(9600);
  int tickEvent = t.every(2000, doSomething, 0);
  Serial.print("2 second tick started id=");
  Serial.println(tickEvent);

  tickEvent = t.every(3000, doSomething, 1);
  Serial.print("3 second tick started id=");
  Serial.println(tickEvent);
  
  int afterEvent = t.after(10000, doAfter); // id not needed in timer definition
  Serial.print("After event started id=");
  Serial.println(afterEvent); 
}

void loop()
{
  t.update();
}

void doSomething(uint8_t id)
{
  uint8_t i_am= 2+id;
  Serial.print(i_am);
  Serial.print(" second tick: millis()=");
  Serial.println(millis());
}


void doAfter(uint8_t id) // id always needed in function call
{
  Serial.println("stop the led event");
}
