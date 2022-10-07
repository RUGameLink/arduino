#define REMOTEXY_MODE__ESP8266WIFI_LIB_CLOUD
#include <ESP8266WiFi.h>
#define sensorPin A0
#include <RemoteXY.h>

// настройки соединения 
#define REMOTEXY_WIFI_SSID "bbb"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "  992cf14e8c7cd22e4febd1c9a7b6c025"


// конфигурация интерфейса  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,12,0,11,0,114,0,13,13,1,
  1,0,10,52,36,36,2,31,68,111,
  110,39,116,32,116,111,117,99,104,32,
  109,101,0,67,4,7,11,20,5,2,
  26,11,129,0,7,5,18,6,17,208,
  146,208,187,208,176,208,182,208,189,208,
  190,209,129,209,130,209,140,0,129,0,
  2,34,54,5,17,208,150,208,181,208,
  187,208,176,208,181,208,188,208,176,209,
  143,32,208,178,208,187,208,176,208,182,
  208,189,208,190,209,129,209,130,209,140,
  0,7,36,4,40,20,5,2,26,2,
  11 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // input variables
  uint8_t button_1; // =1 если кнопка нажата, иначе =0 
  char edit_1[11];  // =строка UTF8 оканчивающаяся нулем  

    // output variables
  char text_1[11];  // =строка UTF8 оканчивающаяся нулем 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  pinMode(5, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(sensorPin, INPUT);
  // TODO you setup code
  Serial.begin(9600);
}

void loop() 
{ 
  RemoteXY_Handler ();
   Serial.print("Analog output: ");
  Serial.println(analogRead(sensorPin));
  delay(1000);
  digitalWrite(5, (RemoteXY.button_1==0)?LOW:HIGH); 
  int val = analogRead(sensorPin); 
  dtostrf(val % 100, 0, 1, RemoteXY.text_1);
}

  // TODO you loop code
  // используйте структуру RemoteXY для передачи данных
  // не используйте функцию delay()
