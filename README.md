**MEDICAL SURVELLIANCE** 
===============================================================
**Description:**        
1.As we know that COVID 19 cases are increasing every day and hence the demand of doctors who knows how handle those cases are also increasing.         
2.If we end up in a situation where we might not have enough doctors are not available, in that case the doctor cannot visit to each patient and look after him.      
3.Hence implementing IoT in this scenario will save the doctor time and helps in taking more care towards the patients who are in critical condition.       
Below are the vital body parameters which are generally monitored for an induvial.      
Vital Body parameters:      
■	Blood Pressure.             
■	Heart Rate.             
■	Oximetry.             
■	Blood Glucose monitoring.              
■	Body Temperature.                     
■	Respiration Rate (when a person is on ventilator).                        
4.Our idea integrates the sensors used in monitoring these parameters with a microcontroller and enable the doctor to monitor the data remotely from any place.                                         
5.If any one of the body parameters is normal, then we can tell that the patient is not well, so we have a notifying system which helps the doctor in identify the patients and take care accordingly.                                                    
6.Maintain a record of all the body parameters without any human interference is another advantage in our idea.  
7.Our idea is can be implemented in hospitals in case server is offline and from any remote place if server is online and the app should be build accourdingly.        
8. The admin access to the app is given only to a person for security purpose anly that person can add and remove the patient accordingly.        
**Hardware and software Requirements:**         
1.We require sensors which are accurate in monitoring an individual body parameter as these sensors are generally used in the ICUs we have to know how use them for our purpose.        
2.We require a microcontroller which has enough number of digital and analog pins with Wi-Fi capability here for demonstration we used NodeMCU.       
3.We need a Router to which all our Wi-Fi modules are connected and it is also connected to the local server.         
4.If the local server is made online the user can monitor the sensor data of patients from any place in the world but if it is not made online then the user has to connect to the same network to which the local server is connected.         
5.We used a Raspberrypi to run the Blynk server this can also be done using a laptop or we can set up a server of our own.        
6.We are running a Blynk server, but we can use Django or other servers and build the app accordingly.        
7.As we are having local server, we can save the data from various sensors from various devices.        
8.The server uses the port 8080 which is generally used for web services and the app(user)is connected to the port 9443(in case of Blynk local server).      
9.We can also sent the live vedio feed to the user which is not done in the vedio.           
**Process Flow:**       
•	The data from various sensors of patients in ICU are collected.         
•	The sensor data is sent to the local server through router using Wi-fi modules.         
•	The data is displayed in the users GUI in app as requested by the user, i.e the user can choose any patient and see medical data in the chart provided in the GUI in the form of graphs with labels on graphs.        
•	If in case any abnormal readings are noted the user get the notification with id of the patient.        


![IMG-20200409-WA0006](https://user-images.githubusercontent.com/39476865/78890785-e042cc80-7a83-11ea-861f-af7512e184bb.jpg)









