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


void Move::cutMove()
{
   int cuts;
   char input;  

   cout << "Make ten executive cuts using the | key to represent each cut made." << endl; 
   cout <<" _______________________________________________________________________" << endl; 
   cout << "                              SURGERY AREA                             " << endl; 
   while(cuts < 10)
   {       cout << "                             " << endl; 
           cin >> input; 
           cuts++; 
   }
   cout <<" _______________________________________________________________________" << endl;
}

void Move::cleanMove()
{
   int clean;
   char input;  

   cout << "Make ten executive cuts using the C key to represent each wipe made." << endl; 
   cout <<" _______________________________________________________________________" << endl; 
   cout << "                              SURGERY AREA                             " << endl; 
   while(clean < 10)
   {
           cout << "                             " << endl; 
           cin >> input; 
           clean++; 
   }
   cout <<" _______________________________________________________________________" << endl;
}

void Move::stitchMove()
{
   int stiches;
   char input;  

   cout << "Make ten executive cuts using the X key to represent each stitch made followed by enter." << endl; 
   cout <<" _______________________________________________________________________" << endl; 
   cout << "                              SURGERY AREA                             " << endl; 
   while(stiches < 10)
   {
           cout << "                           " << endl; 
           cin >> input; 
           stiches++; 
   }
   cout <<" _______________________________________________________________________" << endl;
}