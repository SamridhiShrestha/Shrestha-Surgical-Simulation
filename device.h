// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

#include <iostream>
#include <string>
using namespace std;
#ifndef DEVICE_H
#define DEVICE_H

class Device{
    private:
        string tool; 
        bool status; 
        int battery; 
        int power; 

    public:
        //Constructors:
        Device();  //default constructor 
        Device(string tool, bool status, int battery, int power);  // parameterized constructor

        // Getters (or accessors)
        string getToolName();
        bool getStatus(); 
        int getBattery(); 
        int getPowerLevel(); 

        // Setters (or mutators)
        void setToolName(string toolOne);
        void setStatus(int curStatOne); 
        void setBattery(int curBattOne); 
        void setPowerLevel(int powerLvl); 
        
        void displayDeviceStats(); //This will print out the stats for display for the device 
        

};

#endif