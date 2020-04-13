{\rtf1\ansi\ansicpg1252\cocoartf2759
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 /*\
  IOT internet of things\
  10/4/18\
  IOT_Solenoids by Paulina Osikoya\
  lectutrer: Brian O' shea\
  reviewed: 15/4/18\
\
  Code Objective: The purpose of this code is to show the solenoids popping up using a switch case statement based on the responce entered from the\
  user into the serial terminal.The solenoids work in conjuction with speech synthesizer with the help of a user present to enter details into\
  the serial terminal. The solenoids are interfaced with uln2803a transistor aray chip , this is done to reduce circuitry. the solenoids represent the six braille cell\
\
*/\
// declaring the six Braille to pins on the arduino\
const int SOL_1 = 12;\
const int SOL_2 = 11;\
const int SOL_3 = 10;\
const int SOL_4 = 9;\
const int SOL_5 = 8;\
const int SOL_6 = 7;\
// declaring the six leds to pins on the arduino\
const int led = 13;\
const int led2 = 6;\
const int led3 = 5;\
const int led4 = 4;\
const int led5 = 3;\
const int led6 = 2;\
\
\
void setup()\
\{\
  // delcaring solenoids as outputs so they can written to\
  pinMode(SOL_1, OUTPUT);\
  pinMode(SOL_2, OUTPUT);\
  pinMode(SOL_3, OUTPUT);\
  pinMode(SOL_4, OUTPUT);\
  pinMode(SOL_5, OUTPUT);\
  pinMode(SOL_6, OUTPUT);\
  pinMode(led, OUTPUT);\
  pinMode(led2, OUTPUT);\
  pinMode(led3, OUTPUT);\
  pinMode(led4, OUTPUT);\
  pinMode(led5, OUTPUT);\
  pinMode(led6, OUTPUT);\
\
  digitalWrite(led, HIGH);\
  digitalWrite(led2, HIGH);\
  digitalWrite(led3, HIGH);\
  digitalWrite(led4, HIGH);\
  digitalWrite(led5, HIGH);\
  digitalWrite(led6, HIGH);\
  delay(2000);\
  digitalWrite(led, LOW);\
  digitalWrite(led2, LOW);\
  digitalWrite(led3, LOW);\
  digitalWrite(led4, LOW);\
  digitalWrite(led5, LOW);\
  digitalWrite(led6, LOW);\
  Serial.begin(9600); // the baud rate at which serial communication takes place which is on pins 0 and 1 (TX RX)\
\}\
\
void loop() // run over and over\
\{\
\
  int  inByte; //assign to serial read and is neater than writing serial read multiple times all over the place\
  if ( Serial.available() > 0) // if the value is highr than 1 the serial monitor must be working. //  WORKING ON 9600 BAUD\
  \{\
    inByte = Serial.read();// stating that it will read what values is given\
\
    Serial.println(F("\\nUser please enter letter voiced by the speech synthesizer\\n""in order to yield the braille equivalent")); // giving the user instruction of what to do in regards to\
    //inputting data into the serial terminal\
\
    /*************************************************************************\
       CODE FUNCTION:  is a switch statment that 26+ cases that represent the\
                       alphabet and the numerical system. the serial terminal\
                       is used to invoke the solenoids and the solenoids will \
                       pop up appropiate braille pattern based on statement\
                       selected.\
    **************************************************************************/\
    switch (inByte) // is a neater  and cleaner way of imlementing a nested if else statement\
    \{\
      case 'a': //ADD\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(led, HIGH);\
        Serial.println(F("Braille equivalent for letter A  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(led, LOW);\
        Serial.println(F("A recieved"));\
        break;\
\
      case 'b':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        Serial.println(F("Braille equivalent for letter B  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        Serial.println("B recieved");\
        break;\
\
      case 'c':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led4, HIGH);\
        Serial.println(F("Braille equivalent for letter C  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led4, LOW);\
        Serial.println("C recieved");\
        break;\
\
\
      case 'd':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter D  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\nD  recieved");\
        break;\
\
      case 'e':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter E  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\n E recieved");\
        break;\
\
\
      case 'f':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led4, HIGH);\
        Serial.println(F("Braille equivalent for letter F  is ready"));\
        delay(4000);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led4, LOW);\
        Serial.print("\\nF recieved");\
        break;\
\
      case 'g':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter G is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\n G recieved");\
        break;\
\
      case 'h':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter H  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\nH recieved");\
        break;\
\
      case 'i':\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led4, HIGH);\
        Serial.println(F("Braille equivalent for letter I  is ready"));\
        delay(4000);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led4, LOW);\
        Serial.print("\\nI recieved");\
        break;\
\
      case 'j':\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.print("Braille equivalent for letter J is now available");\
        delay(5000);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\n J recieved");\
        break;\
\
      case 'k':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led3, HIGH);\
        Serial.println(F("Braille equivalent for letter K is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led3, LOW);\
        Serial.print("\\n K recieved");\
        break;\
\
      case 'l':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led3, HIGH);\
        Serial.println(F("Braille equivalent for letter L  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led3, LOW);\
        Serial.print("\\n L recieved");\
        break;\
\
      case 'm':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led4, HIGH);\
        Serial.println(F("Braille equivalent for letter M is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led4, LOW);\
        Serial.print("\\nM recieved");\
        break;\
\
      case 'n':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter N  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\n N recieved");\
        break;\
\
      case 'o':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter O  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\n O recieved");\
        break;\
\
      case 'p':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led4, HIGH);\
        Serial.println(F("Braille equivalent for letter P is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led4, LOW);\
        Serial.print("\\n P recieved");\
        break;\
\
      case 'q':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter Q  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\n Q recieved");\
        break;\
\
      case 'r':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter R  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\n R recieved");\
        break;\
\
      case 's':\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led4, HIGH);\
        Serial.println(F("Braille equivalent for letter S is ready"));\
        delay(4000);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led4, LOW);\
        Serial.print("\\n S recieved");\
        break;\
\
      case 't':\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led5, HIGH);\
        Serial.println(F("Braille equivalent for letter T  is ready"));\
        delay(4000);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led5, LOW);\
        Serial.print("\\n T recieved");\
        break;\
\
      case 'u':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_6, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led6, HIGH);\
        Serial.println(F("Braille equivalent for letter U is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_6, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led6, LOW);\
        Serial.print("\\nU recieved");\
\
        break;\
\
      case 'v':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_6, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led6, HIGH);\
        Serial.println(F("Braille equivalent for letter V is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_6, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led6, LOW);\
        Serial.print("\\n V recieved");\
        break;\
\
      case 'w':\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(SOL_6, HIGH);\
        digitalWrite(led2, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led5, HIGH);\
        digitalWrite(led6, HIGH);\
        Serial.println(F("Braille equivalent for letter W is ready"));\
        delay(4000);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(SOL_6, LOW);\
        digitalWrite(led2, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led5, LOW);\
        digitalWrite(led6, LOW);\
        Serial.print("\\n W recieved");\
        break;\
\
      case 'x':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_6, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led6, HIGH);\
        Serial.println(F("Braille equivalent for letter X  is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_6, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led6, LOW);\
        Serial.print("\\n X recieved");\
        break;\
\
\
      case 'y':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_4, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_6, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led4, HIGH);\
        digitalWrite(led5, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led6, HIGH);\
        Serial.println(F("Braille equivalent for letter Y is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_6, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led4, LOW);\
        digitalWrite(led5, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led6, LOW);\
        Serial.print("\\n Y  recieved");\
        break;\
\
\
      case 'z':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_5, HIGH);\
        digitalWrite(SOL_3, HIGH);\
        digitalWrite(SOL_6, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led5, HIGH);\
        digitalWrite(led3, HIGH);\
        digitalWrite(led6, HIGH);\
        Serial.println(F("Braille equivalent for letter Z is ready"));\
        delay(4000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_6, LOW);\
         digitalWrite(led, LOW);\
        digitalWrite(led5, LOW);\
        digitalWrite(led3, LOW);\
        digitalWrite(led6, LOW);\
        Serial.print("\\n Z recieved");\
        break;\
\
      case '1':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(led, HIGH);\
        Serial.print(F("Braille equivalent for Number one is now available"));\
        delay(5000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(led, LOW);\
        Serial.print("\\nNumber one ");\
        break;\
\
      case '2':\
        digitalWrite(SOL_1, HIGH);\
        digitalWrite(SOL_2, HIGH);\
        digitalWrite(led, HIGH);\
        digitalWrite(led2, HIGH);\
        Serial.print(F("Braille equivalent for Number two is now available"));\
        delay(5000);\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(led, LOW);\
        digitalWrite(led2, LOW);\
        Serial.print("\\nNumber two");\
        break;\
\
      case '-': // if the user to say that they are done this will discountinue the sessions they are curretly in\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(SOL_6, LOW);\
        Serial.println(F("ARDUINO IS GOING TO SLEEP"));\
        delay(4000);\
        break;\
\
      default: // default case\
        /*****************************************************\
          default all the pins won,t light up and will print to\
          the serial trminl that an error occured in this istances\
          as neither a letter or number was entered\
        *****************************************************/\
        Serial.print("\\n Error");\
        digitalWrite(SOL_1, LOW);\
        digitalWrite(SOL_2, LOW);\
        digitalWrite(SOL_3, LOW);\
        digitalWrite(SOL_4, LOW);\
        digitalWrite(SOL_5, LOW);\
        digitalWrite(SOL_6, LOW);\
    \}\
  \}\
\}\
\
}