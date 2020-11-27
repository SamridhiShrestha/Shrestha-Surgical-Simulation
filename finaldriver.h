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
using namespace std;
#ifndef DRIVER_H
#define DRIVER_H

class Driver{
    private:
        Patient patient[3];
        static const int size = 3;
        Time timeLeft;
        bool stable; 
        // Device devicePower[5]; 
        bool surgerySuccess; 

    public:
        //Constructors:
        Driver();  //default constructor 
        Driver(string patient[], int timeLeft, bool stable, bool deviceStatus, bool surgerySuccess);  // parameterized constructor

        // Getters (or accessors)
        string getpatient(int patindex);
        int gettimeLeft(); 
        int getstable(); 
        int getdevicePower(); 
        int getsurgerySuccess(); 

        // Setters (or mutators)
        void setpatient(); // How do I implement the seperate patient files here? 
        void settimeLeft(); 
        void setstable(bool curStable); 
        void setdevicePower(int devindex, int powVal); 
        void setsurgerySuccess(bool cursurgerySuccess); 

        void displayDeviceMenu(); 
        void startgame(string surgeonName); 
};

#endif