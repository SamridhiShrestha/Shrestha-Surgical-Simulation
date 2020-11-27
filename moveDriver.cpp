// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

// Implementation Patient.cpp
// This is where we are defining all of our components 
#include "move.h" // Include header file
#include <iostream>
#include <cmath>

using namespace std;

// Default constructor
// This is for the case that the there is no input so we have empty values 
Move::Move()
{
        moveName = ""; 
        probOfSuccess = 0.0; 
        duration = 0;
        point = 0; 
}
 
// Parameterized constructor
//This is to take in the parameters given by the user 
Move::Move(string moveOne, double probOne, int durOne, int pointOne) 
{
        moveName = moveOne; 
        probOfSuccess = probOne; 
        duration = durOne;
        point = pointOne;     
}

// Getters (or accessors)
// Public members that can access private data members 

string Move::getmoveName()
{
    return moveName; 
}

double Move::getprobOfSuccess()
{
    return probOfSuccess; 
} 

int Move::getduration()
{
    return duration; 
}

int Move::getpoint()
{
    return point; 
}

// Setters (or mutators)
// Public members that are able to change the private data members 

void Move::setmoveName(string moveOne)
{
        moveName = moveOne; 
        
}

void Move::setprobOfSuccess(int probOne)
{
        probOfSuccess = probOne; 
  
}

void Move::setduration(int durOne)
{
        duration = durOne;

}

void Move::setpoint(int pointOne)
{
        point = pointOne;   
}
