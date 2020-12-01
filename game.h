
#include "device.h"
#include "patient.h"
#include <iostream>
#include <cmath>
#include <fstream> 
#include <string>
using namespace std;
#ifndef GAME_H
#define GAME_H

class Game{
    private:

        int stage; 
        int min; 
        int max; 
        int tool; 

    public:

    int randomVal(int min, int max); 

    bool complicationMath(int stage); 
    bool complicationUnscramble( int stage); 
    bool complicationFacts( int stage); 

    // bool complicationBattery(int tool);
    // bool complicationPower(int tool);  
        

};

#endif