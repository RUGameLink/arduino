/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.6 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.8.01 or later version;
     - for iOS 1.5.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,3,0,101,0,118,0,13,13,1,
  7,52,21,38,20,5,2,26,2,67,
  4,19,18,20,5,2,26,101,129,0,
  3,5,59,6,17,208,162,208,181,208,
  186,209,131,209,137,208,176,209,143,32,
  208,178,208,187,208,176,208,182,208,189,
  208,190,209,129,209,130,209,140,0,129,
  0,3,29,56,6,17,208,146,208,187,
  208,176,208,182,208,189,208,190,209,129,
  209,130,209,140,32,208,191,208,190,208,
  187,208,184,208,178,208,176,0,2,0,
  18,54,22,11,2,26,31,31,79,78,
  0,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int16_t txtIn;  // 32767.. +32767 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // output variables
  char txtOut[101];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define MINVALUESOILMOISTURE 220
#define MAXVALUESOILMOISTURE 900
#define sensorPin A0

void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(9600);
  delay(1000);
  Serial.println("ok");
  
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  int avalue = analogRead(sensorPin);
//avalue=constrain(avalue, MINVALUESOILMOISTURE,MAXVALUESOILMOISTURE);
//int res=map(avalue, MINVALUESOILMOISTURE, MAXVALUESOILMOISTURE,100,0);
  dtostrf(avalue, 0, 1, RemoteXY.txtOut);
  int pref = RemoteXY.txtIn;
  if(avalue < pref){
    digitalWrite(5, HIGH);
   }
   else{
     digitalWrite(5, LOW);
   }
  if(RemoteXY.switch_1 == 1){
    Serial.println("Button on");
    digitalWrite(5, HIGH);
  }
   if(RemoteXY.switch_1 == 0){
    digitalWrite(5, LOW);
  }
  
  // TODO you loop code  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
