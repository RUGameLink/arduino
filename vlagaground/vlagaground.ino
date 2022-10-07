#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>
#define sensorPin A0
#include <RemoteXY.h>

// значение полного полива
#define MINVALUESOILMOISTURE 220
// значение критической сухости
#define MAXVALUESOILMOISTURE 900

// настройки соединения 
#define REMOTEXY_WIFI_SSID "tupiЯЯЯЯkan"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// конфигурация интерфейса  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,3,0,11,0,77,0,13,13,1,
  7,52,17,43,20,5,2,26,2,1,
  0,17,57,27,27,2,31,88,0,67,
  4,15,17,20,5,2,26,11,129,0,
  14,6,18,6,17,208,162,208,181,208,
  186,209,131,209,137,208,176,209,143,0,
  129,0,13,36,18,6,17,208,150,208,
  181,208,187,208,176,208,181,208,188,208,
  176,209,143,0 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // input variables
  int16_t edit_1;  // 32767.. +32767 
  uint8_t button_1; // =1 если кнопка нажата, иначе =0 

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
  digitalWrite(5, (RemoteXY.button_1==0)?LOW:HIGH); 
  int avalue = analogRead(sensorPin); 
  avalue=constrain(avalue, MINVALUESOILMOISTURE,MAXVALUESOILMOISTURE);
  int res=map(avalue, MINVALUESOILMOISTURE, 
                   MAXVALUESOILMOISTURE,100,0);

    int pref = RemoteXY.edit_1;
  if(res < pref){
    digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5, LOW);
  }
  
  dtostrf(res, 0, 1, RemoteXY.text_1);


}

  // TODO you loop code
  // используйте структуру RemoteXY для передачи данных
  // не используйте функцию delay()
