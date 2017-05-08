
#include "Buzzer.h"

Buzzer::Buzzer() : pwm(PTA2){
    pwm = 0.0;
}

void Buzzer::buttonBeep(){
    playFreq(420, 100, 1);
}

void Buzzer::playFreq(float frequency, float duration, float volume){
        pwm.period(1.0/frequency);
        pwm = volume/2.0;
        wait_ms(duration);
        pwm = 0.0;
}

void Buzzer::startupSound(){
    playFreq(300, 200, 1);
    playFreq(600, 200, 1);
    playFreq(900, 200, 1);
}
