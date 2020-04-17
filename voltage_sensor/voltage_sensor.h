/*
File Name: voltage_sensor.h

Created Date: 16-April-2020

Description: Header file for variable and structure decalrarions

Created By: Narahari Kasagatta Ramesh,
			      Development Engineer,
			      Done Enterprises Ab Oy, Vaasa

Contact:  narahari.kasagattaramesh@doneenterprises.fi
		      +358-417501750

*/

#define ADC_MIN_COUNT (620+140)           // ADC count when the battery is at critically low voltage
#define ADC_MAX_COUNT (850+140)           // ADC count when the battery is fully charged
#define BAT_MIN_VOLTAGE 21000       // LiPo voltage at critical state in mV
#define BAT_MAX_VOLTAGE 29000       // Lipo voltage at full cahrge state in mV

#define BAT_ANALOG_PIN A0      		// Analog input pin A0
#define BAT_LED_PIN 12         		// Digital output pin 12
#define UPDATE_INTERVAL 1000  		// Loop update interval in ms


typedef enum{
  LIPO_FULL = 1,        // Battery is in full charged state (29V)
  LIPO_DISCHARGING,     // Battery started to discharge and ready for first warning (<=26V)
  LIPO_LOW,             // Battery is near to completely discharge state (<=24V)
  LIPO_CRITICAL         // Battery is completely disccharged (<=23V)
}batteryState;             

typedef enum{
  FULL_CHARGE=29,      // Voltage when battery is full charged
  DRAIN_STARTED=26,    // Voltage when battery starts to drain but some energy is left
  REACHING_LOW=24,     // Voltage when battery discharge characteristics are reaching towards flat 
  CRITICAL=23          // Voltage when battery must be charged
}batteryVoltage;

typedef enum
{
  RED = 2,   // digital pin 2 
  GREEN,     // digital pin 3
  BLUE       // digital pin 4 
}RGBled;

unsigned long batterylevelindicatorTimer = millis();
unsigned long updateintervalTimer = millis();



/*
 if(batteryVoltage>=29)
      Serial.println("Battery Full..!!!");
    //battery_LED_indicator(STATE_FULL); //Green light
    else if((batteryVoltage>=762)||(batteryVoltage<=853))
      Serial.println("\t Battery started discharging, still have energy left");
    //battery_LED_indicator(STATE_DISCHARGING); //Blink Green light
    else if((batteryVoltage>=703)||(batteryVoltage<=707))
      Serial.println("Start charging..! Battery is low");
    //battery_LED_indicator(STATE_LOW); //Blink Green and Red light in 500ms interval
    else
      Serial.println("Battery critically low");
    //battery_LED_indicator(STATE_CRITICAL); //Blink Red light
    //END of if(batteryVoltage>853)
*/
