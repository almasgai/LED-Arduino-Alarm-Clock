#include <TimeLib.h>
#include <TimeAlarms.h>

#define PIN 10            // control pin
#define DELAY 10          // 20ms internal delay; increase for slower fades
#define DAYINSECS 86400   // Total number of seconds in a single day

void setup() {

  pinMode(PIN, OUTPUT);

  // Setting time format (24 hour):
  // HOUR, MINS, SECS, MONTH, DAY, YEAR (20XX)
  setTime(8, 38, 00, 2, 26, 18);

  // Setting up when the alarm should go off
  Alarm.alarmRepeat(6, 30, 00, fade);
  Alarm.alarmRepeat(8, 38, 1, fade);
  
}

void loop() {
  // digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
  // fade();
}

void fade() {
  // fade in
  for(int i=0; i< 255; i++) {
    analogWrite(PIN, i);
    delay(DELAY);
  }

  // fade out
  for(int i=0; i< 255; i++) {
    analogWrite(PIN, 255 - i);
    delay(DELAY);
  }
}
