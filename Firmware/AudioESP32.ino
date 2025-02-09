// ESP32 and DFPlayer Test

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;

#define Stop 34
#define Prev 33
#define Next 14

void setup() {
    pinMode(Stop, INPUT);
    pinMode(Prev, INPUT);
    pinMode(Next, INPUT);

    Serial2.begin(9600);   //communicate with DFPlayer: RX = 16; TX = 17
    Serial.begin(9600);

    Serial.println();
    Serial.println("DFRobot DFPlayer Mini Demo");
    Serial.println("Inirializing DFPlayer ... (May take 3~5 seconds)");
    delay(2000); 

    // Use hardwareSerial to communicate with DFPlayer
    if (!myDFPlayer.begin(Serial2)) {
        Serial.println("Unable to begin");
        Serial.println("1. Please recheck the connection!");
        Serial.println("2. Please insert the SD Card!");
        while(true);
    }

    Serial.println("DFPlayer Mini online");
    // Set serial communication time out 500ms
    myDFPlayer.setTimeOut(500);

    // Set volume value (0~30)
    myDFPlayer.volume(20);

    // ----Set different EQ
    myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

    // ----Set device we use SD as default----
    myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

    // ----Mp3 Play Testing ----
    myDFPlayer.randomAll();
}

void loop() {
    if (!digitalRead(Stop)){
         while (!digitalRead(Stop));
         Serial.println("Stop");
         myDFPlayer.stop();
    }
    if (!digitalRead(Prev)){

          while (!digitalRead(Prev));
          Serial.println("Previous");
          myDFPlayer.previous();
    }
    if (!digitalRead(Next)) {
          while (!digitalRead(Next));
          Serial.println("Next");
          myDFPlayer.next();
    }
}
