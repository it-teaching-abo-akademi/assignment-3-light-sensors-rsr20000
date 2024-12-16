//Q4

int sensorPin1 = A0;   // select the input pin for the first LDR sensor
int sensorPin2 = A1;   // select the input pin for the second LDR sensor
int sensorPin3 = A2;   // select the input pin for the third LDR sensor
int sensorPin4 = A3;   // select the input pin for the fourth LDR sensor

int sensorValue1 = 0;  // variable to store the value coming from the first sensor
int sensorValue2 = 0;  // variable to store the value coming from the second sensor
int sensorValue3 = 0;  // variable to store the value coming from the third sensor
int sensorValue4 = 0;  // variable to store the value coming from the fourth sensor

void setup() {
  Serial.begin(9600);  // sets serial port for communication
}

void loop() {
  // read the value from each sensor
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);
  
  // prints the values coming from the sensor on the screen
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);
  Serial.print("\t");

  Serial.print("Sensor 2: ");
  Serial.print(sensorValue2);
  Serial.print("\t");

  Serial.print("Sensor 3: ");
  Serial.print(sensorValue3);
  Serial.print("\t");

  Serial.print("Sensor 4: ");
  Serial.println(sensorValue4);
  
  delay(100);  // delay for 100 milliseconds before reading the values again
}
