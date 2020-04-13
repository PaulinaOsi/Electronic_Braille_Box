{\rtf1\ansi\ansicpg1252\cocoartf2759
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 /*\
   Movi programming scratch code\
   Copyright (C) 2014, 2015 by audeme LLC\
*/\
# include <movi.h>  // header file\
\
/* SOLENOID VALES */\
int POS_1 = 2;\
int POS_2 = 3;\
int POS_3 = 4;\
int POS_4 = 5;\
int POS_5 = 6;\
int POS_6 = 7;\
int speechresult = -1; // default didnt pick up anything\
MOVIShield recognizer(); // a function\
\
void setup() \{\
  // put your setup code here, to run once:\
  pinMode(POS_1, OUTPUT);\
  pinMode(POS_2, OUTPUT);\
  pinMode(POS_3, OUTPUT);\
  pinMode(POS_4, OUTPUT);\
  pinMode(POS_5, OUTPUT);\
  pinMode(POS_6, OUTPUT);\
  recognizer.init();\
  recognizer.callSign("MOVI");\
\
  /* SENTENCES*/\
  recognizer.addSentence(1, "Hello Movi");\
  recognizer.addSentence(2, "Option 1");\
  recognizer.addSentence(3, "Option 2");\
  recognizer.addSentence(4, "The letter A");\
  recognizer.addSentence(5, "The letter B");\
  recognizer.addSentence(6, "The letter C");\
  recognizer.addSentence(7, "That will be all Movi");\
  recognizer.addSentence(8, "I want to changee options");\
  recognizer.train(); // trains the sentences i the order that they are in for the recognizer poll\
\}\
\
void loop() \{\
  // put your main code here, to run repeatedly:\
\
  speechresult = recognizer.poll();\
\
  if (speechresult == 1 ) \{\
    recognizer.say("Hello User,Please select your option");\
  \}\
\
  if (speechresult == 2 || speechresult == 3 ) \{\
    recognizer.say("You have choosen an option. let's begin");\
  \}\
\
  if (speechresult == 4 ) \{\
    recognizer.say("This is the Letter A in Braille");\
    digitalWrite(POS_1, HIGH);\
    delay(2000);\
    digitalWrite(POS_1, LOW);\
    digitalWriterecognizer.say("Please say another letter");\
  \}\
\
  if (speechresult == 5 ) \{\
    recognizer.say("This is the Letter B in Braille");\
    digitalWrite(POS_1, HIGH);\
    digitalWrite(POS_2, HIGH);\
    delay(2000);\
    digitalWrite(POS_1, LOW);\
    digitalWrite(POS_2, LOW);\
    digitalWriterecognizer.say("Please say another letter");\
  \}\
\
  if (speechresult == 6 ) \{\
    recognizer.say("This is the Letter C in Braille");\
    digitalWrite(POS_1, HIGH);\
    digitalWrite(POS_4, HIGH);\
    delay(2000);\
    digitalWrite(POS_1, LOW);\
    digitalWrite(POS_4, LOW);\
    digitalWriterecognizer.say("Please say another letter");\
  \}\
\
  if (speechresult == 7 ) \{\
    recognizer.say("Okay, MOVI is going to sleep");\
  \}\
\
  if (speechresult == 8 ) \{\
    recognizer.say("Which option would you like to choose");\
  \}\
\
  if (speechresult == 0 ) \{\
    recognizer.say("i think you are a bit far away. please move close and try again");\
  \}\
\
\
\}\
}