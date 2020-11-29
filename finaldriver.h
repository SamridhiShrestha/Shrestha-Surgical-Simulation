// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

#include <iostream>
#include <string>
#include "patient.h"
#include "time.h"
#include "device.h"
#include "move.h"
#include "game.h"
using namespace std;
#ifndef DRIVER_H
#define DRIVER_H

class Driver{
    private:
        Device tools[6];
        static const int size = 6;
        Time timeLeft;
        string surgeonName; 
        int surgeonYear; 
        int patindex; 
        int opt; 

    public:
        //Constructors:
        Driver();  //default constructor 
    
        // Getters (or accessors)
        string getpatient(int patindex);


        void displayGrandMenu();
        void displayCleanMenu(); 
        void displayCutMenu(); 
        void displayStitchMenu(); 
        void chooseMenu(int opt); 

        int randomNum(); 

        void failureStorage(string surgeonName,string patient, int surgeonYear); 
        void successStorage(string surgeonName, string patient, int surgeonYear); 

        void startgame(string surgeonName,int surgeonYear); 
};

#endif