
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

void Buzzer::keypadBeep(char button){
    switch(button){
        case '1': playFreq(300, 200, 1);  break;
        case '2': playFreq(350, 200, 1);  break;
        case '3': playFreq(400, 200, 1);  break;
        case '4': playFreq(450, 200, 1);  break;
        case '5': playFreq(500, 200, 0.7);  break;
        case '6': playFreq(550, 200, 1);  break;
        case '7': playFreq(600, 200, 1);  break;
        case '8': playFreq(650, 200, 1);  break;
        case '9': playFreq(700, 200, 1);  break;
        case '*': playFreq(750, 200, 1);  break;
        case '0': playFreq(800, 200, 0.7);  break;
        case '#': playFreq(850, 200, 0.8);  break;
    }
}
