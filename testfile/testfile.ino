void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float adc, voltage;
  adc = analogRead(A0);
  voltage = (float)map(adc,(620+140),(850+140),21000,29000)/1000;
  
  Serial.print("ADC Value = ");
  Serial.print(adc);
  Serial.print("\t Voltage = ");
  Serial.println(voltage);

  // Read the value every 2 seconds
  delay(1000);
}
