//D1 SCL
//D2 SDA
#define BLYNK_PRINT Serial
#define Relay_1 D3  //D3
#define Relay_2 D4//D4
#define SW1 10     //SD3 เปิดปิดเครื่อง
#define SW2 9      //SD2 แสดงQR CODE ด้านซ้าย
#define SW3 8      //SD1 แสดงสถานะ ด้านขวา
#define LED 16     //D0

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 




char auth[] = "2d610ac0e6e944c6ba2d97b180fa3181";
char ssid[] = "A1";
char pass[] = "44332211";
char host[] = "iott.ddns.net";
const uint16_t port = 8080;
int LED_Status = 0;
Adafruit_SSD1306 display(-1);

void debug()
{
  Serial.print("SW=");
  Serial.print(SW1);
  Serial.println("LED=");
  Serial.print(LED);
  Serial.println("Relay_1=");
  Serial.print(Relay_1);
  Serial.println("Relay_2=");
  Serial.print(Relay_2);
  Serial.println("LED_Status=");
  Serial.print(LED_Status);
  delay(100);
}


void setup() {
  

  
  pinMode(Relay_1 , OUTPUT);
  pinMode(Relay_2 , OUTPUT);
  pinMode(SW1 , INPUT);
  pinMode(SW2 , INPUT);
  pinMode(SW3 , INPUT);
  pinMode(LED , OUTPUT);
  digitalWrite(Relay_1, 0);
  digitalWrite(Relay_2, 0);
  digitalWrite(LED, 0);
  Serial.begin(115200);
   Blynk.begin(auth,ssid,pass,host,port);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3c);//สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
  
}

void loop() {
  Blynk.run();
  debug();
}
  //OLED_SW1();
/*  if(digitalRead(SW1)==HIGH)
  {
    if(LED_Status==0)
    {
      state_on();
    }
    else
    {
      state_off();
    }
  }
}
BLYNK_WRITE(V3)
{
if(param.asInt()==0)
  {
    state_on();
  }
if(param.asInt()==1)
  {
    state_off();
  }
}
*/
