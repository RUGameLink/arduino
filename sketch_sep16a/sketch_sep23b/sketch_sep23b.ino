#define REMOTEXY_MODE__ESP8266WIFI_LIB_CLOUD
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

#include <DHT.h>
#define DHTPIN 5 // Тот самый номер пина, о котором упоминалось выше

// настройки соединения 
#define REMOTEXY_WIFI_SSID "bbb"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "992cf14e8c7cd22e4febd1c9a7b6c025"


// конфигурация интерфейса  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,0,0,22,0,77,0,13,13,1,
  129,0,10,21,18,6,135,208,162,208,
  181,208,188,208,191,208,181,209,128,208,
  176,209,130,209,131,209,128,208,176,0,
  129,0,7,38,33,6,135,208,146,208,
  187,208,176,208,182,208,189,208,190,209,
  129,209,130,209,140,0,67,4,9,29,
  20,5,2,26,11,67,4,9,46,20,
  5,2,26,11 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // output variables
  char text_1[11];  // =строка UTF8 оканчивающаяся нулем 
  char text_2[11];  // =строка UTF8 оканчивающаяся нулем 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

DHT dht(DHTPIN, DHT11);

void setup() 
{
  RemoteXY_Init (); 
  
  Serial.begin(9600);
  dht.begin();
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // используйте структуру RemoteXY для передачи данных
  // не используйте функцию delay() 
  delay(2000); // 2 секунды задержки
  float h = dht.readHumidity(); //Измеряем влажность
  float t = dht.readTemperature(); //Измеряем температуру

   dtostrf(t, 0, 1, RemoteXY.text_1);
   dtostrf(h, 0, 1, RemoteXY.text_2);

}
