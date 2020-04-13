{\rtf1\ansi\ansicpg1252\cocoartf2759
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0  /*\
  WiFiEsp example: WebServerAP\
\
  A simple web server that shows the value of the analog input\
  pins via a web page using an ESP8266 module.\
  This sketch will start an access point and print the IP address of your\
  ESP8266 module to the Serial monitor. From there, you can open\
  that address in a web browser to display the web page.\
  The web page will be automatically refreshed each 20 seconds.\
\
  For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html\
\
  Download library here: https://github.com/bportaluri/WiFiEsp : Clone or download -> Download ZIP\
  Then Sketch -> Include Library -> Add .ZIP Library\
*/\
\
#include "WiFiEsp.h"\
\
#include "SoftwareSerial.h"\
SoftwareSerial Serial1(2, 3); // RX, TX\
\
String request = "";\
\
char ssid[] = "TwimEsp";         // your network SSID (name)\
char pass[] = "12345678";        // your network password\
int status = WL_IDLE_STATUS;     // the Wifi radio's status\
int reqCount = 0;                // number of requests received\
\
WiFiEspServer server(80); // PORT ON WHICH THE HTTP PROTCOL WORKS ON\
\
// use a ring buffer to increase speed and reduce memory allocation\
RingBuffer buf(8); //REASEACRH\
\
void setup()\
\{\
  Serial.begin(9600);   // initialize serial for debugging change it to 9600\
  Serial1.begin(9600);    // initialize serial for ESP module\
  WiFi.init(&Serial1);    // initialize ESP module //SERIA1 RESEACH\
\
  // check for the presence of the shield\
  if (WiFi.status() == WL_NO_SHIELD) \{\
    Serial.println("WiFi shield not present");\
    while (true); // don't continue\
  \}\
\
  Serial.print("Attempting to start AP ");\
  Serial.println(ssid);\
\
  // uncomment these two lines if you want to set the IP address of the AP\
  //IPAddress localIp(192, 168, 111, 111);\
  //WiFi.configAP(localIp);\
\
  // start access point\
  status = WiFi.beginAP(ssid, 10, pass, ENC_TYPE_WPA2_PSK);\
\
  Serial.println("Access point started");\
  printWifiStatus(); // FUNCTION USED\
\
  // start the web server on port 80\
  server.begin();\
  Serial.println("Server started");\
\}\
\
\
void loop()\
\{\
  WiFiEspClient client = server.available();  // listen for incoming clients\
\
  if (client) \{                               // if you get a client,\
    Serial.println("New client");             // print a message out the serial port\
    buf.init();                               // initialize the circular buffer\
    while (client.connected()) \{              // loop while the client's connected\
      if (client.available()) \{               // if there's bytes to read from the client,\
        char c = client.read();               // read a byte, then\
        buf.push(c);                          // push it to the ring buffer\
        request += c;                        // request = request + c; meaning adding c to what ever is in request\
        // you got two newline characters in a row\
        // that's the end of the HTTP request, so send a response\
        if (buf.endsWith("\\r\\n\\r\\n")) \{\
          //  sendHttpResponse(client);\
          if (request.indexOf("page1") >= 0) // means there is reponse because it is greater than zero then it is available\
          \{\
            Serial.println("page1");\
            // call code to send back page1\
            sendPage1(client);\
            client.print(F("<br>\\r\\n"));\
            client.print(F("<A HREF=\\"http://192.168.4.1/page2\\">REFERENCES</A>")); // href creates a hyperlink to what you are reference this is how navigation is possible\
            client.print(F("<br>\\r\\n"));\
            client.print(F("<A HREF=\\"http://192.168.4.1/home page\\">HOME PAGE</A>"));\
          \}\
          else if (request.indexOf("page2") >= 0)\
          \{\
            // call code to send back page2\
            sendPage2(client);\
            Serial.println("page2");\
            client.print(F("<br>\\r\\n"));\
            client.print(F("<A HREF=\\"http://192.168.4.1/page1\\">ABOUT</A>"));\
            client.print(F("<br>\\r\\n"));\
            client.print(F("<A HREF=\\"http://192.168.4.1/home page\\">HOME PAGE</A>"));\
          \}\
          else\
          \{\
            sendHomePage(client); // goes to that function with the client server is still availble\
            Serial.println("home page");\
            client.print(F("<br>\\r\\n"));\
            client.print(F("<A HREF=\\"http://192.168.4.1/page1\\">ABOUT</A>"));\
            client.print(F("<br>\\r\\n"));\
            client.print(F("<A HREF=\\"http://192.168.4.1/page2\\">REFERENCES</A>"));\
\
          \}\
          request = ""; \
          break;\
        \}\
      \}\
    \}\
\
    // give the web browser time to receive the data\
    delay(10);\
\
    // close the connection\
    client.stop();\
    Serial.println("Client disconnected");\
  \}\
\}\
\
void sendHomePage(WiFiEspClient client)\
\{\
  client.print(\
    "HTTP/1.1 200 OK\\r\\n"\
    "Content-Type: text/html\\r\\n"\
    "Connection: close\\r\\n"  // the connection will be closed after completion of the response\
    "Refresh: 60\\r\\n"        // refresh the page automatically every 20 sec\
    "\\r\\n");\
  client.print(F("<!DOCTYPE HTML>\\r\\n"));\
  client.print(F("<html>\\r\\n"));\
  client.print(F("<head>\\r\\n"));\
  client.print(F("<title>Osikoya's Method</title>\\r\\n"));\
  client.print(F("</head>\\r\\n"));\
  client.print(F("<body>\\r\\n"));\
  client.print(F("<center><h1>Osikoya's Method</h1></center>\\r\\n"));\
  client.print(F("<center><h2><b>Home Page</b></h2></center>\\r\\n"));\
  client.print(F("<center><h2>My Project</h2></center>\\r\\n"));\
  client.print(F("<center><p>My Project is an electronic braille device which aids visually impaired individuals in learning Braille.  <br/></p></center>\\r\\n"));\
  client.print(F("<center><p>My device is composed of an Arduino Microcontroller which is interfaced with a speech recognizer and synthesizer. <br/></p></center>\\r\\n"));\
  client.print(F("<center><p>The speech synthesizer allows the user to say a sentence which correlates to one of the letters in the alphabet and the synthesizer responds accordingly by activating a six sequence pattern represented by six D-frame push-pull solenoids, which represent the six braille cell, to produce an alphabet equivalent. <br/></p></center>\\r\\n"));\
  client.print(F("<center><p>My device is also integrated and networked with serial communications such as the Serial terminal and Wi-Fi for added functionality and  the user can view my details of my project via a developed website made with HTML and CSS <br/></p></center>\\r\\n"));\
  client.print(F("<footer><center>Copyright &copy; Osikoya's Method </center></footer>\\r\\n"));\
  client.print(F("</body>\\r\\n"));\
  client.print(F("</html>\\r\\n"));\
\}\
\
void sendPage1(WiFiEspClient client)\
\{\
  client.print(\
    "HTTP/1.1 200 OK\\r\\n"\
    "Content-Type: text/html\\r\\n"\
    "Connection: close\\r\\n"  // the connection will be closed after completion of the response\
    "Refresh: 60\\r\\n"        // refresh the page automatically every 20 sec\
    "\\r\\n");\
\
  client.print(F("<!DOCTYPE HTML>\\r\\n"));\
  client.print(F("<!DOCTYPE HTML>\\r\\n"));\
  client.print(F("<html>\\r\\n"));\
  client.print(F("<body>\\r\\n"));\
  client.print(F("<center><h2>Page 2 - ABOUT</h2></center>\\r\\n"));\
  client.print(F("<center><p>I choose my project simply because I wanted to give back to my community in a different way <br/></p></center>\\r\\n"));\
  client.print(F("<center><p>and the way I did this was by constructing a braille teaching device for the blind community in my locality.<br/></p></center>\\r\\n"));\
  client.print(F("<center><p>Amidst the known technological developments implemented in my area I noticed that not many improvements were being amended to the blind community<br/></p></center>\\r\\n"));\
  client.print(F("<center><p>premised on the fact that braille was still being taught in rudimentary ways in my locality.<br/></p></center>\\r\\n"));\
  client.print(F("<center><p>So,I honed in on this area and decided to mesh electronics and technology into how braille was being taught<br/></p></center>\\r\\n"));\
  client.print(F("<center><p>to help the user enhance their learning and learn braille with ease.<br/></p></center>\\r\\n"));\
  client.print(F("<center><p> https://www.audeme.com/movi.html is the link to view the speech sythnsizer website.<br/></p></center>\\r\\n"));\
  client.print(F("<footer><center>Copyright &copy; Osikoya's Method </center></footer>\\r\\n"));\
  client.print(F("</body>\\r\\n"));\
  client.print(F("</html>\\r\\n"));\
\}\
\
void sendPage2(WiFiEspClient client)\
\{\
  client.print(F("<!DOCTYPE HTML>\\r\\n"));\
  client.print(F("<html>\\r\\n"));\
  client.print(F("<body>\\r\\n"));\
  client.print(F("<center><h2>Page 2 - References</h2></center>\\r\\n"));\
  client.print(F("<center><h2>My Project</h2></center>\\r\\n"));\
  client.print(F("<center><p>Here is a link to website where i gained some of my inspiration from: http://evengrounds.com<br/></p></center>\\r\\n"));\
  client.print(F("<center><p>Here is the list of he material to also create the braile box:https://www.audeme.com/movi.html<br/> </p></center>\\r\\n"));\
  client.print(F("<center><p>Here is tthe link to  www.fightingblindness.ie which supports blind people and research into the area. Copy the link and enter it into your bowser to make a donation.<br/></p></center>\\r\\n"));\
  client.print(F("<footer><center>Copyright &copy; Osikoya's Method </center></footer>\\r\\n"));\
  client.print(F("</body>\\r\\n"));\
  // client.print(F("<h1>Hello From Page 2</h1>\\r\\n"));\
  client.print(F("</html>\\r\\n"));\
\}\
\
void printWifiStatus()\
\{\
  // print your WiFi shield's IP address\
  IPAddress ip = WiFi.localIP(); //REASEARCH\
  Serial.print("IP Address: ");\
  Serial.println(ip);\
\
  // print where to go in the browser\
  Serial.println();\
  Serial.print("To see this page in action, connect to ");\
  Serial.print(ssid);\
  Serial.print(" and open a browser to http://");\
  Serial.println(ip);\
  Serial.println();\
\}\
\
}