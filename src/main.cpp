#include <Arduino.h>
#include <LibRobus.h>

float speed = 0.7;

int avance(unsigned int temps);
int recule(unsigned int temps);
int tourneDroite(unsigned int temps);
int tourneGauche(unsigned int temps);
int selectRandomAction();
int selectRandomTime();


int tempsMax = 1200;
int tempsmin = 50;


void setup() {
    Serial.begin(9600);
    BoardInit();
    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
}

void loop() {
    int randAction = selectRandomAction();
    int prevRandAction = 0;
    if(randAction == 3 || randAction == 4){
        tempsMax = 500;
        tempsmin = 10;
    }
    else{
        tempsMax = 2000;
        tempsmin = 50;

    }
    int randTime   = selectRandomTime();
    if(randAction != prevRandAction){
        switch(randAction){
            case 1 :
                avance(randTime);
                Serial.println("Avance");
                Serial.println(randTime);
                break;
            case 2 :
                recule(randTime);
                Serial.println("Recule");
                Serial.println(randTime);
                break;
            case 3 :
                tourneDroite(randTime);
                Serial.println("TourneDroite");
                Serial.println(randTime);
                break;
            case 4 :
                tourneGauche(randTime);
                Serial.println("TourneGauche");
                Serial.println(randTime);
                break;
        }
        prevRandAction = randAction;
    }
}


int selectRandomAction(){
    return (rand()%(5-1) + 1);
}

int selectRandomTime(){
    return (rand()%((tempsMax+1)-tempsmin) + tempsmin);
}

int avance(unsigned int temps){
    unsigned long startTime = millis();
    while((millis() - startTime) < temps){
        MOTOR_SetSpeed(0, speed);
        MOTOR_SetSpeed(1, speed);
    }
    return 0;
}

int recule(unsigned int temps){
    unsigned long startTime = millis();
    while((millis() - startTime) < temps){
        MOTOR_SetSpeed(0, -speed);
        MOTOR_SetSpeed(1, -speed);
    }
    return 0;
}

int tourneDroite(unsigned int temps){
    unsigned long startTime = millis();
    while((millis() - startTime) < temps){
        MOTOR_SetSpeed(0, speed);
        MOTOR_SetSpeed(1, -speed);
    }
    return 0;  
} 

int tourneGauche(unsigned int temps){
    unsigned long startTime = millis();
    while((millis() - startTime) < temps){
        MOTOR_SetSpeed(0, -speed);
        MOTOR_SetSpeed(1, speed);
    }
    return 0;  
} 