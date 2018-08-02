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
    sv.attach(9, 800, 2300);
}

void loop()
{
    moveShaft(0, 5);
    delay(5000);
    moveShaft(90, 5);
    delay(5000);
}
