#include <IRremote.h>
int RECV_PIN = 14;
int IRData = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;
int verde = 11;
int azul = 12;
int rojo = 13;
int Led_Status = 0;
int outputValue = 0;
int counter = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(rojo, OUTPUT);
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

    
    
     // Controlar Led
    if (Led_Status == 1 && IRData != 2295)  // !(1)
    { 
      if (IRData == 20655)  //  (up)
      {  
        if (counter<3)
        {
        	counter++;  
        }  
      }
      if (IRData == 4335)  // (down)
      {
        if (counter>1)
        {
        	counter--;  
        } 
      }
      if (IRData == 16575)  //  (func/stop)
      {
        digitalWrite(rojo, 0);
        digitalWrite(verde, 0);
        digitalWrite(azul, 0);
        Led_Status = 0;
        counter = 0;
      }
    }
    
    switch (counter)   //funcion cambio de color
    {
      case 1:
      		setColor(0,255,0);
      		Serial.print("verde");
      		break;
      case 2:
      		setColor(0,0,255);
      		Serial.print("azul");
      		break;
      case 3:
      		setColor(255,0,0);
      		Serial.print("rojo");
      		break;
      default:
      		break;
    } 
      
    if (IRData == 2295)  //  (1)
    {
        setColor(0,255,0);
        Led_Status = 1;
      	if (counter == 0)
        {
      		counter++;
        }
    }
      
  }//if decode(&results)
}//void loop

void setColor(int red, int green, int blue)
{
      digitalWrite(verde, green);
      digitalWrite(azul, blue);
      digitalWrite(rojo, red);
} 