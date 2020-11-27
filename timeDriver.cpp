// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

// Implementation Patient.cpp
// This is where we are defining all of our components 
#include "time.h" // Include header file
#include <iostream>
#include <cmath>

using namespace std;

// Default constructor
// This is for the case that the there is no input so we have empty values 
Time::Time()
{
        hours = 100; 
        minutes = 60; 
        seconds = 60; 
        milliseconds = 60; 
}
 
// Parameterized constructor
//This is to take in the parameters given by the user 
Time::Time(int curhour, int curminute, int cursecond, int curmillisecond) 
{
        hours = curhour; 
        minutes = curminute; 
        seconds = cursecond; 
        milliseconds = curmillisecond; 
}

// Getters (or accessors)
// Public members that can access private data members 

int Time::gethours()
{
    return hours; 
}

int Time::getminutes()
{
    return minutes; 
}

int Time::getseconds()
{
    return seconds; 
}

int Time::getmilliseconds()
{
    return milliseconds; 
}


// Setters (or mutators)
// Public members that are able to change the private data members 
        void Time::sethours(int curhour)
        {
            hours = curhour; 
  
        }
        void Time::setminutes(int curminute)
        {
            minutes = curminute; 

        }
        void Time::setseconds(int cursecond)
        {
            seconds = cursecond; 

        }
        void Time::setmilliseconds(int curmillisecond)
        {
            milliseconds = curmillisecond; 
        }

        void Time::displaytime() 
        {
            cout << "---Time Left---" << endl; 
            cout << "Hours: " << gethours() << endl; 
            cout << "Minutes: " << getminutes() << endl; 
            cout << "Seconds: " << getseconds() << endl; 
            cout << "Milliseconds: " << getmilliseconds() << endl; 
        }

