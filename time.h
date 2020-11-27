// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

#include <iostream>
#include <string>
using namespace std;
#ifndef TIME_H
#define TIME_H

class Time{
    private:
        int hours; 
        int minutes; 
        int seconds; 
        int milliseconds; 

    public:
        //Constructors:
        Time(); //default constructor 
        Time(int hours, int minutes, int seconds, int milliseconds);  // parameterized constructor

        // Getters (or accessors)
        int gethours(); 
        int getminutes(); 
        int getseconds(); 
        int getmilliseconds(); 

        // Setters (or mutators)
        void sethours(int curhour); 
        void setminutes(int curminute); 
        void setseconds(int cursecond); 
        void setmilliseconds(int curmillisecond); 
        
        void displaytime(); 


};


#endif