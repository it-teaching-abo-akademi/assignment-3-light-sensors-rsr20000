//Q6

const int windowSize = 100;  // size of the sliding window
int sensorPin1 = A0;         // select the input pin for the first LDR sensor
int sensorPin2 = A1;         // select the input pin for the second LDR sensor
int sensorPin3 = A2;         // select the input pin for the third LDR sensor
int sensorPin4 = A3;         // select the input pin for the fourth LDR sensor

int sensorValues1[windowSize]; // array to store the last 100 readings for sensor 1
int sensorValues2[windowSize]; // array to store the last 100 readings for sensor 2
int sensorValues3[windowSize]; // array to store the last 100 readings for sensor 3
int sensorValues4[windowSize]; // array to store the last 100 readings for sensor 4

int index = 0;  // index for the current reading (used for the sliding window)

void setup() {
  Serial.begin(9600);  // sets serial port for communication
  // Initialize sensor values arrays with 0s
  for (int i = 0; i < windowSize; i++) {
    sensorValues1[i] = 0;
    sensorValues2[i] = 0;
    sensorValues3[i] = 0;
    sensorValues4[i] = 0;
  }
}

void loop() {
  // Read new values from the sensors
  int newValue1 = analogRead(sensorPin1);
  int newValue2 = analogRead(sensorPin2);
  int newValue3 = analogRead(sensorPin3);
  int newValue4 = analogRead(sensorPin4);
  
  // Add new values to the sliding window
  sensorValues1[index] = newValue1;
  sensorValues2[index] = newValue2;
  sensorValues3[index] = newValue3;
  sensorValues4[index] = newValue4;

  // Update the index for the sliding window
  index = (index + 1) % windowSize;

  // Only print results after the sliding window is full
  if (index == 0) {

    // Calculate the average and variance for each sensor
    float average1 = calculateAverage(sensorValues1);
    float variance1 = calculateVariance(sensorValues1, average1);

    float average2 = calculateAverage(sensorValues2);
    float variance2 = calculateVariance(sensorValues2, average2);

    float average3 = calculateAverage(sensorValues3);
    float variance3 = calculateVariance(sensorValues3, average3);

    float average4 = calculateAverage(sensorValues4);
    float variance4 = calculateVariance(sensorValues4, average4);
    
    // Print the results for each sensor
    Serial.print("Sensor 1: Avg: ");
    Serial.print(average1);
    Serial.print("  Var: ");
    Serial.print(variance1);

    Serial.print(" / Sensor 2: Avg: ");
    Serial.print(average2);
    Serial.print("  Var: ");
    Serial.print(variance2);

    Serial.print(" / Sensor 3: Avg: ");
    Serial.print(average3);
    Serial.print("  Var: ");
    Serial.print(variance3);

    Serial.print(" / Sensor 4: Avg: ");
    Serial.print(average4);
    Serial.print("  Var: ");
    Serial.println(variance4);
  }

  delay(30);  // Delay for 30 milliseconds before reading the values again
}

// Function to calculate the average of the last 100 readings
float calculateAverage(int sensorValues[]) {
  long sum = 0;
  for (int i = 0; i < windowSize; i++) {
    sum += sensorValues[i];
  }
  return sum / float(windowSize);
}

// Function to calculate the variance of the last 100 readings
float calculateVariance(int sensorValues[], float average) {
  long sumSquares = 0;
  for (int i = 0; i < windowSize; i++) {
    sumSquares += pow(sensorValues[i] - average, 2);
  }
  return sumSquares / float(windowSize);
}
