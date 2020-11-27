// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

// Implementation Patient.cpp
// This is where we are defining all of our components 
#include "patient.h" // Include header file
#include <iostream>
#include <cmath>

using namespace std;

// Default constructor
// This is for the case that the there is no input so we have empty values 
Patient::Patient()
{
        patientName = "";
        lifepoints = 0; 
        age = 0; 
        heartRate = 0; 
        oxygenLevel = 0; 
}
 
// Parameterized constructor
//This is to take in the parameters given by the user 
Patient::Patient(string patientOne, int lifeOne, int ageOne, int rateOne, int oxyOne) 
{
        patientName = patientOne;
        lifepoints = lifeOne; 
        age = ageOne; 
        heartRate = rateOne; 
        oxygenLevel = oxyOne; 
}

// Getters (or accessors)
// Public members that can access private data members 
string Patient::getpatientName()
{
    return patientName; 
}

int Patient::getage()
{
    return age; 
}

int Patient::getlifepoints()
{
    return lifepoints; 
}

int Patient::getheartRate()
{
    return heartRate; 
}

int Patient::getoxygenLevel()
{
    return oxygenLevel; 
}


// Setters (or mutators)
// Public members that are able to change the private data members 
        void Patient::setpatientName(string patientOne)
        {
            patientName = patientOne;
        }

        void Patient::setlifepoints(int lifeOne)
        {
            lifepoints = lifeOne; 
        } 

        void Patient::setage(int ageOne)
        {
            age = ageOne; 
        }
        
        void Patient::setheartRate(int rateOne)
        {
            heartRate = rateOne;
        }

        void Patient::setoxygenLevel(int oxyOne)
        {
            oxygenLevel = oxyOne; 
        }


        void Patient::displayPatientStatus()
        {
            cout << "---Patient Status---" << endl; 
            cout << "Patient: " << getpatientName() << endl; 
            cout << "Life Points: " << getlifepoints() << endl; 
            cout << "Age: " << getage() << endl; 
            cout << "Heart Rate: " << getheartRate() << endl; 
            cout << "Oxygen Level: " << getoxygenLevel() << endl; 
            cout << "--------------------" << endl; 
        }

        void Patient::displayPatientProfile()
        {
        cout << "Age: " << getage() << endl; 
        cout << "Life Points: " << getlifepoints() << endl; 
        cout << "Heart Rate: " << getheartRate() << endl; 
        cout << "Oxygen Level: " << getoxygenLevel() << endl; 
        }



