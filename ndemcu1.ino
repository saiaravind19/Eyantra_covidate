#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

int ir = D5;
int light = A0;
int intensity=0;
int obstacle=0;
int intensity1=0;
int obstacle1=0;

char auth[] = "W0Y7_EgpZ1Ew1PMK1vTCFPUPlioF1v7p";
char ssid[] = "DESKTOP-EM2HJ6E 1456";
char pass[] = "473w*Y37";

WidgetLCD lcd(V0n);

BLYNK_WRITE(V2)
{
   intensity1 = param.asInt(); 
   

  
}
BLYNK_WRITE(V3)
{
  obstacle1 = param.asInt();
}
void bridge_from_another_device()
{ intensity = analogRead(light);
obstacle=digitalRead(ir);

if(intensity>300 || obstacle==0){
  lcd.print(0,0,"critical id:1");
  Serial.println("critical id:1");
}
if(intensity1>300 || obstacle1==0){
    lcd.print(0,1,"critical id:2");
      Serial.println("critical id:2");

    
}
else if(intensity<500 && obstacle==1 && intensity1<500 && obstacle1==1)
{lcd.clear();
Serial.println("normal");}
}
  
void setup() {
  pinMode(ir, INPUT);
  pinMode(light, INPUT);

  lcd.clear();
  timer.setInterval(1000L, bridge_from_another_device);
  Blynk.begin(auth, ssid, pass, IPAddress(192,168,0,13), 8080);
  Serial.begin(9600);

}


void loop() {
  Blynk.run();
  timer.run();

}
