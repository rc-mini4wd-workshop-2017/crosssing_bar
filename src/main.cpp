#include <Arduino.h>
#include <Servo.h>

Servo sv;

void moveShaft(int angle, long int delay_ms)
{
    int pulse = map(angle, 0, 180, 800, 2300);
    int pulse_now = sv.readMicroseconds();

    if( pulse > pulse_now ){
        for( int i = pulse_now; i <= pulse; i++ ){
            sv.writeMicroseconds(i);
            delay(delay_ms);
        }
    }
    else if( pulse < pulse_now ){
        for( int i = pulse_now; i >= pulse; i-- ){
            sv.writeMicroseconds(i);
            delay(delay_ms);
        }
    }
    else{
        // do nothing
    }
}

void setup()
{
    Serial.begin(9600);
    Serial.write("Started...\n");
    Serial.write("  crossing bar v0.1\n");
    sv.attach(4, 800, 2300);
}

void loop()
{
    Serial.write("move to 90 deg.\n");
    moveShaft(90, 5);
    delay(5000);
    Serial.write("move to  0 deg.\n");
    moveShaft(0, 5);
    delay(5000);
}
