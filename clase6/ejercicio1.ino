// Temperatura
int readValue = 0;
int lastValue = 1;
int sensorPin = A0;
int Led_Pin1 = 3;
int Led_Pin2 = 4;  
float voltsValue;
float tempValue;
void setup()
{
  Serial.begin(9600);
  pinMode(Led_Pin1, OUTPUT); 
  pinMode(Led_Pin2, OUTPUT); 
}
void loop()
{
  // Lectura Analoga
  readValue = analogRead(sensorPin);
  if (lastValue != readValue) {
    Serial.print("readValue: ");
    Serial.print(readValue);
    lastValue = readValue;
    voltsValue = 5.0 / 1024 * readValue;
    Serial.print(" -> voltsValue: ");
    Serial.print(voltsValue);
    tempValue = voltsValue * 100 - 50;
    Serial.print(" -> tempValue: ");
    Serial.println(tempValue);
    if (tempValue < 25)
    {
      Serial.print("Hace frio");
      digitalWrite(Led_Pin2,0);
      digitalWrite(Led_Pin1,1);
  	}
    else
    {
      Serial.print("Hace calor");
      digitalWrite(Led_Pin1,0);
      digitalWrite(Led_Pin2, 1);
    }
  }  
    delay(100);
}