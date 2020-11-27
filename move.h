// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

#include <iostream>
#include <string>
using namespace std;
#ifndef MOVE_H
#define MOVE_H

class Move{
    private:
        string moveName; 
        double probOfSuccess; 
        int duration;
        int point; 

    public:
        //Constructors:
        Move();  //default constructor 
        Move(string moveName, double probOfSuccess, int duration, int point);  // parameterized constructor

        // Getters (or accessors)
        string getmoveName(); 
        double getprobOfSuccess(); 
        int getduration();
        int getpoint(); 

        // Setters (or mutators)
        void setmoveName(string moveOne); 
        void setprobOfSuccess(int probOne); 
        void setduration(int durOne);
        void setpoint(int pointOne); 
};

#endif