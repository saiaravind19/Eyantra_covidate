#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

int ir = D5;
int light = A0;
int intensity=0;
int obstacle=0;


char auth[] = "UfbQNmsCBikBCOKf9wxF66kxP7vHlOxI";
char ssid[] = "DESKTOP-EM2HJ6E 1456";
char pass[] = "473w*Y37";

WidgetBridge bridge1(V1);

void bridge_to_another_device()
{ intensity = analogRead(light);
obstacle=digitalRead(ir);
bridge1.virtualWrite(V2,intensity);
bridge1.virtualWrite(V3,obstacle);
  
}


BLYNK_CONNECTED() {
  bridge1.setAuthToken("W0Y7_EgpZ1Ew1PMK1vTCFPUPlioF1v7p"); // Place the AuthToken of the second hardware here
}



void setup() {
  pinMode(ir, INPUT);
  pinMode(light, INPUT);
  timer.setInterval(1000L, bridge_to_another_device);
  Blynk.begin(auth, ssid, pass, IPAddress(192,168,0,13), 8080);
  Serial.begin(9600);

}

void loop() {
  Blynk.run();
  timer.run();

}
