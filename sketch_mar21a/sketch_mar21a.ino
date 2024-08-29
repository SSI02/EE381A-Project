// Define the analog input pins
const int pinE = A5;
const int pinB = A6;
const int pinC = A7;
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}
void loop() {
  // Read analog values from each pin
  int sensorValueVE = analogRead(pinE);
  int sensorValueVB = analogRead(pinB);
  int sensorValueVC = analogRead(pinC);
  // Convert analog values to voltages
  float voltageVE = sensorValueVE * (5.0 / 1024.0);
  float voltageVB = sensorValueVB * (5.0 / 1024.0);
  float voltageVC = sensorValueVC * (5.0 / 1024.0);
 String bjt_state_str = bjt_state(voltageVE, voltageVB, voltageVC);
  // Print the readings to the serial monitor
  Serial.print("VE: ");
  Serial.print(sensorValueVE);
  Serial.print(" (");
  Serial.print(voltageVE);
  Serial.println("V)");
  Serial.print("VB: ");
  Serial.print(sensorValueVB);
  Serial.print(" (");
  Serial.print(voltageVB);
  Serial.println("V)");
  Serial.print("VC: ");
  Serial.print(sensorValueVC);
  Serial.print(" (");
  Serial.print(voltageVC);
  Serial.println("V)");
  Serial.println(bjt_state_str);
 Serial.println("------------");
  // Delay before taking next readings
  delay(1000);
}
String bjt_state(float vE, float vB, float vC) {
  // Assuming typical BJT characteristics
  float V_BE_threshold = 0.7;
  float V_CE_threshold = 0.2;
  if (vB - vE > V_BE_threshold && vC - vE > V_CE_threshold) {
    return "Saturation";
  } else if (vB - vE < V_BE_threshold && vC - vE < V_CE_threshold) {
    return "Cutoff";
  } else {
    return "Linear";
  }
}