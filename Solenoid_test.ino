{\rtf1\ansi\ansicpg1252\cocoartf2759
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 \
const int SOL_1 = 13;\
const int SOL_2 = 12;\
const int SOL_3 = 11;\
const int SOL_4 = 10;\
const int SOL_5 = 9;\
const int SOL_6 = 8;\
const int led = 7;\
\
void setup()\
\{\
  pinMode(SOL_1, OUTPUT);    // Make LED port writeable\
  pinMode(SOL_2, OUTPUT);\
  pinMode(SOL_3, OUTPUT);\
  pinMode(SOL_4, OUTPUT);\
  pinMode(SOL_5, OUTPUT);\
  pinMode(SOL_6, OUTPUT);\
\}\
\
void loop() // run over and over\
\{\
  digitalWrite(SOL_1, HIGH);        // Turn on LED\
  digitalWrite(SOL_2, HIGH);\
  digitalWrite(SOL_3, HIGH);\
  digitalWrite(SOL_4, HIGH);\
  digitalWrite(SOL_5, HIGH);\
  digitalWrite(SOL_6, HIGH);\
  digitalWrite(led, HIGH);\
  delay(1000);\
  digitalWrite(SOL_1, LOW);        // Turn on LED\
  digitalWrite(SOL_2, LOW);\
  digitalWrite(SOL_3, LOW);\
  digitalWrite(SOL_4, LOW);\
  digitalWrite(SOL_5, LOW);\
  digitalWrite(SOL_6, LOW);\
  digitalWrite(led, LOW);\
  delay(1000);\
\}\
}