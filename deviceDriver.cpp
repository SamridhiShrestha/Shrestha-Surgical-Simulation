// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

// Implementation device.cpp
// This is where we are defining all of our components 
#include "device.h"
#include <iostream>
#include <string>
using namespace std;

    //Constructors:

    Device::Device()//default constructor 
    {
        tool = "";
        status = true; 
        battery = 100; 
        power = 100;
    }

    
    Device::Device(string toolOne, bool curStatOne, int curBattOne, int powerLvl) //parameterized constructor
    {
        tool = toolOne; 
        status = curStatOne; 
        battery = curBattOne; 
        power = powerLvl; 

    }


    // Getters (or accessors)
    // Public members that can access private data members 
    string Device::getToolName()
    {
        return tool;
    }

    bool Device::getStatus()
    {
        return status;
    }

    int Device::getBattery()
    {
        return battery;
    }

    int Device::getPowerLevel()
    {
        return power;
    }

    
    // Setters (or mutators)
    // Public members that are able to change the private data members 
        void Device::setToolName(string toolOne)
        {
            tool = toolOne; 
        }
        void Device::setStatus(int curStatOne)
        {
            status = curStatOne; 
        }

        void Device::setBattery(int curBattOne)
        {
            battery = curBattOne; 
        }

        void Device::setPowerLevel(int powerLvl)
        {
            power = powerLvl; 
        }

        void Device::displayDeviceStats()
        {
            cout << "---Device Stats---" << endl; 
            cout << "Tool: " << getToolName() << endl; 
            cout << "Status: " << getStatus() << endl; 
            cout << "Battery: " << getBattery() << endl; 
            cout << "Power: " << getPowerLevel() << endl; 
        }

