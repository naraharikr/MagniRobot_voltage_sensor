#include "voltage_sensor.h"

void setup() 
{
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // set digital pins as output for RGB LED indicator
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

float readandmap_analog_signal()
{
  float mapAdc; 
  mapAdc = (float)map(analogRead(BAT_ANALOG_PIN), ADC_MIN_COUNT,
                    ADC_MAX_COUNT, BAT_MIN_VOLTAGE, BAT_MAX_VOLTAGE)/1000;    
  return(mapAdc);
}

void batterystatus_led_indicator(int mode)
{
  switch(mode)
  {
    case LIPO_FULL: RGB_color(0, 0, 255);           // Green
    case DRAIN_STARTED: RGB_color(255, 255, 0);     // Magneta
    case REACHING_LOW: RGB_color(255, 125, 255);    // Raspberry
    case CRITICAL: RGB_color(255, 0, 0);            // Red
  }
}

void RGB_color(int rvalue, int bvalue, int gvalue)
{
  analogWrite(RED, rvalue);
  analogWrite(GREEN, gvalue);
  analogWrite(BLUE, bvalue);
}

void loop() 
{
  float adc_in_volts;
  /* Read battery voltage from the ADC Channel A0 and map the
     the range of BAT_MIN_VOLTAGE and BAT_MAX_VOLTAGE */
  #ifdef UPDATE_INTERVAL
  if (millis() - updateintervalTimer >= UPDATE_INTERVAL)
  {
    adc_in_volts = readandmap_analog_signal();
    Serial.print("Voltage = ");
    Serial.print(adc_in_volts);
    if((adc_in_volts<=FULL_CHARGE)&&(adc_in_volts>28.9))
    {
      Serial.println("\t Battery Full..!!!");
      batterystatus_led_indicator(LIPO_FULL); 
    }
    else if((adc_in_volts<=DRAIN_STARTED)&&(adc_in_volts>25.5))
    {
      Serial.println("\t Battery started discharging, still have energy left");
      batterystatus_led_indicator(LIPO_DISCHARGING);
    }
    else if((adc_in_volts<=REACHING_LOW)&&(adc_in_volts>23.5))
    {
      Serial.println("\t Start charging..! Battery is low");
      batterystatus_led_indicator(LIPO_LOW);
    }
    else if(adc_in_volts<=CRITICAL)
    {
      Serial.println("\t Battery critically low");
      batterystatus_led_indicator(LIPO_CRITICAL);
    }
    updateintervalTimer = millis();
  }
  #else 
      /* Do Nothing */
  #endif
}
