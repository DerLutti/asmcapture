// Code von https://playground.arduino.cc/Code/MCP3208/

#define SELPIN 10 //Selection Pin 
#define DATAOUT 11//MOSI 
#define DATAIN  12//MISO 
#define SPICLOCK  13//Clock 
int readvalue;

float amplitude_current;
float effective_value;

void setup() {
  // put your setup code here, to run once:
  pinMode(SELPIN, OUTPUT);
  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK, OUTPUT);
  //disable device to start with
  digitalWrite(SELPIN, HIGH);
  digitalWrite(DATAOUT, LOW);
  digitalWrite(SPICLOCK, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(250);

  int sensor_max;
  sensor_max = getMaxValue();
  Serial.print("sensor_max = ");
  Serial.println(sensor_max);


  amplitude_current = (float)sensor_max / 4096 * 5 / 800 * 2000000; //conversion incorrect (12-bit statt 10)
  amplitude_current = (amplitude_current * 1.05);       // Korekturwert, Wert wird um 5% erhöht
  effective_value = amplitude_current / 1.41;

  Serial.println("The amplitude of the current is(in mA)");
  Serial.println(amplitude_current, 1); //Only one number after the decimal point
  Serial.println("The effective value of the current is(in mA)");
  Serial.println(effective_value, 1);
}

int read_adc(int channel) {
  int adcvalue = 0;
  byte commandbits = B11000000; //command bits - start, mode, chn (3), dont care (3)

  //allow channel selection
  commandbits |= ((channel - 1) << 3);

  digitalWrite(SELPIN, LOW); //Select adc
  // setup bits to be written
  for (int i = 7; i >= 3; i--) {
    digitalWrite(DATAOUT, commandbits & 1 << i);
    //cycle clock
    digitalWrite(SPICLOCK, HIGH);
    digitalWrite(SPICLOCK, LOW);
  }

  digitalWrite(SPICLOCK, HIGH);   //ignores 2 null bits
  digitalWrite(SPICLOCK, LOW);
  digitalWrite(SPICLOCK, HIGH);
  digitalWrite(SPICLOCK, LOW);

  //read bits from adc
  for (int i = 11; i >= 0; i--) {
    adcvalue += digitalRead(DATAIN) << i;
    //cycle clock
    digitalWrite(SPICLOCK, HIGH);
    digitalWrite(SPICLOCK, LOW);
  }
  digitalWrite(SELPIN, HIGH); //turn off device
  return adcvalue;
}

int getMaxValue()
{
  int sensorValue;             //value read from the sensor
  int sensorMax = 0;
  uint32_t start_time = millis();
  while ((millis() - start_time) < 1000) //sample for 1000ms
  {
    //sensorValue = analogRead(ELECTRICITY_SENSOR);
    sensorValue = read_adc(1);
    if (sensorValue > sensorMax)
    {
      /*record the maximum sensor value*/
      sensorMax = sensorValue;
    }
  }
  return sensorMax;
}