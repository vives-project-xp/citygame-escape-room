
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
        case '1': playFreq(300, 100, 1);  break;
        case '2': playFreq(350, 100, 1);  break;
        case '3': playFreq(400, 100, 1);  break;
        case '4': playFreq(450, 100, 1);  break;
        case '5': playFreq(500, 100, 0.7);  break;
        case '6': playFreq(550, 100, 1);  break;
        case '7': playFreq(600, 100, 1);  break;
        case '8': playFreq(650, 100, 1);  break;
        case '9': playFreq(700, 100, 1);  break;
        case '*': playFreq(750, 100, 1);  break;
        case '0': playFreq(800, 100, 0.7);  break;
        case '#': playFreq(850, 100, 0.8);  break;
    }
}

void Buzzer::completeSound(){
    playFreq(1318, 130, 1);
    playFreq(1567, 130, 1);
    playFreq(2637, 130, 1);
    playFreq(2093, 130, 1);
    playFreq(2349, 130, 1);
    playFreq(3135, 130, 1);
}
