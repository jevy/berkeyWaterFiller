#define upperWaterSensorPin A0
#define lowerWaterSensorPin A1
#define fillWaterPumpPin A7
#define ledPin 13      // select the pin for the LED
int upperSensorValue = 0;
int upperPercentageValue = 0;
int lowerSensorValue = 0;
int lowerPercentageValue = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(upperWaterSensorPin, INPUT);
  pinMode(lowerWaterSensorPin, INPUT);

}

void ledOn() {
  digitalWrite(ledPin, HIGH);
}

void ledOff() {
  digitalWrite(ledPin, LOW);
}

int percentageFullSensorOne(int rawValue) {
  return (rawValue-500)*100L/(735-500);
}

int percentageFullSensorTwo(int rawValue) {
  return (rawValue-525)*100L/(670-525);
}

void loop() {
  
  // read the value from the sensor:
  upperSensorValue = analogRead(upperWaterSensorPin);
  lowerSensorValue = analogRead(lowerWaterSensorPin);
  upperPercentageValue = percentageFullSensorOne(upperSensorValue); // < 25 not reliable
  lowerPercentageValue = percentageFullSensorTwo(lowerSensorValue); // < 25 not reliable

  delay(250);

  // https://forum.arduino.cc/t/baffled-by-ranging-an-analog-value-into-a-percentage/364834/2
  Serial.println(upperPercentageValue);

}
