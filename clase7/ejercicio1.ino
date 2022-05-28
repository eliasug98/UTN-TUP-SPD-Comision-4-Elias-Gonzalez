#include <IRremote.h>
int RECV_PIN = 14;
int IRData = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;
int Led_Pin = 2;
int Led_Pin2 = 8;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() 
{
  if (irrecv.decode(&results))
  {
    IRData = results.value;
    irrecv.resume();
    Serial.print("Datos: ");
    Serial.print(IRData, HEX);
    Serial.print(" {");
    Serial.print(IRData);
    Serial.println("}");
	switch(IRData)
    {
      case 2295:
      			digitalWrite(Led_Pin2, 0);
      			digitalWrite(Led_Pin, 1);
      			break;
      case -30601:
      			digitalWrite(Led_Pin, 0);
      			digitalWrite(Led_Pin2, 1);
				break;
    }
  }
}