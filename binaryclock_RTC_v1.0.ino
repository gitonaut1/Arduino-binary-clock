
#include <DS3231.h>

DS3231  rtc(SDA, SCL);// Init the DS3231 using the hardware interface

Time  t;// Init a Time-data structure

int second=0, minute=0, hour=0; //start the time on 00:00:00
int munit,hunit,minuteTens,hourTens,valm=0,valh=0,ledstats,i;

// LEDS positions matrix
int leds[4][4] = {
 {17,2,17,1},
 {17,5,4,3},
 {9,8,7,6},
 {13,12,11,10}
};

void setup() {
  //set outputs
  for(int k=1;k<=13;k++) {
    pinMode(k, OUTPUT);
    digitalWrite(k, LOW);

  }
  //Serial.begin(9600);
  //Serial.println("setup...");
  //pinMode(A1, INPUT);
  //pinMode(A2, INPUT);
  rtc.begin();
}

void loop() {
  t = rtc.getTime();
  second = t.sec;
  minute = t.min;
  hour = t.hour;
  //Serial.println(second);


  munit = (int) (minute%10); //sets the variable munit and hunit for the unit digits
  hunit = (int) (hour%10);
  minuteTens = (int)(minute/10);
  hourTens = (int)(hour/10);
  //minutes units
  if(munit & 1)       {digitalWrite(leds[3][3], HIGH);} else {digitalWrite(leds[3][3],LOW);}
  if(munit & 2)       {digitalWrite(leds[2][3], HIGH);} else {digitalWrite(leds[2][3],LOW);}
  if(munit & 4)       {digitalWrite(leds[1][3], HIGH);} else {digitalWrite(leds[1][3],LOW);}
  if(munit & 8)       {digitalWrite(leds[0][3], HIGH);} else {digitalWrite(leds[0][3],LOW);}

  //minutes
  if(minuteTens & 1)  {digitalWrite(leds[3][2], HIGH);} else {digitalWrite(leds[3][2],LOW);}
  if(minuteTens & 2)  {digitalWrite(leds[2][2], HIGH);} else {digitalWrite(leds[2][2],LOW);}
  if(minuteTens & 4)  {digitalWrite(leds[1][2], HIGH);} else {digitalWrite(leds[1][2],LOW);}

  //hour units
  if(hunit & 1)       {digitalWrite(leds[3][1], HIGH);} else {digitalWrite(leds[3][1],LOW);}
  if(hunit & 2)       {digitalWrite(leds[2][1], HIGH);} else {digitalWrite(leds[2][1],LOW);}
  if(hunit & 4)       {digitalWrite(leds[1][1], HIGH);} else {digitalWrite(leds[1][1],LOW);}
  if(hunit & 8)       {digitalWrite(leds[0][1], HIGH);} else {digitalWrite(leds[0][1],LOW);}

  //hour
  if(hourTens & 1)  {digitalWrite(leds[3][0], HIGH);} else {digitalWrite(leds[3][0],LOW);}
  if(hourTens & 2)  {digitalWrite(leds[2][0], HIGH);} else {digitalWrite(leds[2][0],LOW);}

   //valm = digitalRead(A1);    // add one minute when pressed
   //if(valm== HIGH) {
   //minute++;
   //second=0;
   //rtc.setTime(hour, minute, second);
   //delay(250);
  //}

  //valh = digitalRead(A2);    // add one hour when pressed
   //if(valh==HIGH) {
   //hour++;
   //second=0;
   //rtc.setTime(hour, minute, second);
   //delay(250);
  //}
  delay(500);
}
