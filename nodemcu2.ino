#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
//initilisation of variables

int ir = D5;
int light = A0;
int intensity=0;
int obstacle=0;

//The auth is tokent generated and sent to the gmail account once u make an account in the app
//ssid and password are the wifi network id and password
char auth[] = "UfbQNmsCBikBCOKf9wxF66kxP7vHlOxI";
char ssid[] = "DESKTOP-EM2HJ6E 1456";
char pass[] = "473w*Y37";
//initilisation of lcd display which is used to notify the user in case of any abnormal activity is detected

WidgetBridge bridge1(V1);
/*Initilisation of bridge which helps in communicating with other nodemcus
if we dont use This feature it will be difficult to display the patient whox is in difficult situation 
as it is not possible to give a space in display for every patient to display when they are in critical condition*/
//Below function is called for every 1 sec as it is initilised in the setup of the code 
void bridge_to_another_device()
{ intensity = analogRead(light);
obstacle=digitalRead(ir);
bridge1.virtualWrite(V2,intensity);
bridge1.virtualWrite(V3,obstacle);
  
}
//This is used to connect to the othef nodemcu to which it has to communicate with
BLYNK_CONNECTED() {
  bridge1.setAuthToken("W0Y7_EgpZ1Ew1PMK1vTCFPUPlioF1v7p"); // Place the AuthToken of the second hardware here
}


/*here we intilised the pins,LCDand timer which is used in calling the function in timebased intervels
and started the Blynk whixh helps in binding the nodemcu with app  */
void setup() {
  pinMode(ir, INPUT);
  pinMode(light, INPUT);
  timer.setInterval(1000L, bridge_to_another_device);
  Blynk.begin(auth, ssid, pass, IPAddress(192,168,0,13), 8080);
  Serial.begin(9600);

}
//this is the loop which runs multiple number of times and does the necessary actions require

void loop() {
  Blynk.run();
  timer.run();

}
