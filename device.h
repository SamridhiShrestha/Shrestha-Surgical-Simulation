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
        int devPoint; 
        int battery; 
        int power; 

    public:
        //Constructors:
        Device();  //default constructor 
        Device(string tool, int devPoint, int battery, int power);  // parameterized constructor

        // Getters (or accessors)
        string getToolName();
        bool getdevPoint(); 
        int getBattery(); 
        int getPowerLevel(); 

        // Setters (or mutators)
        void setToolName(string toolOne);
        void setdevPoint(int devPointOne); 
        void setBattery(int curBattOne); 
        void setPowerLevel(int powerLvl); 
        
        void setCompTools(); 
        void displayDeviceStats(); //This will print out the stats for display for the device 
        

};

#endif