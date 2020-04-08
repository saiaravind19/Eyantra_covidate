#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
//initilisation of variables
int ir = D5;
int light = A0;
int intensity=0;
int obstacle=0;
int intensity1=0;
int obstacle1=0;
//The auth is tokent generated and sent to the gmail account once u make an account in the app
//ssid and password are the wifi network id and password
char auth[] = "W0Y7_EgpZ1Ew1PMK1vTCFPUPlioF1v7p";
char ssid[] = "DESKTOP-EM2HJ6E 1456";
char pass[] = "473w*Y37";
//initilisation of lcd display which is used to notify the user in case of any abnormal activity is detected
WidgetLCD lcd(V0n);
//blynk provides a feature of virtual pins whcih is very helpful in many cases
//here we are using the virtual pins to get read the data from other nodemcu
BLYNK_WRITE(V2)
{
   intensity1 = param.asInt(); 
}
BLYNK_WRITE(V3)
{
  obstacle1 = param.asInt();
}
//Belo function is called for every 1 sec as it is initilised in the setup of the code 
/*here as i used bridge to communicate between node mcu it not necessary but insted u can give a place values for each nodemcu
to display if any abnormal activity is detected
the below function performs comparision of the sensors values with thresthold set by the user and also reading the sensor data from the 
pins of nodemcu*/
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
/*here we intilised the pins,LCDand timer which is used in calling the function in timebased intervels
and started the Blynk whixh helps in binding the nodemcu with app  */
void setup() {
  pinMode(ir, INPUT);
  pinMode(light, INPUT);

  lcd.clear();
  timer.setInterval(1000L, bridge_from_another_device);
  Blynk.begin(auth, ssid, pass, IPAddress(192,168,0,13), 8080);
  Serial.begin(9600);

}
//this is the loop which runs multiple number of times and does the necessary actions require

void loop() {
  Blynk.run();
  timer.run();

}
