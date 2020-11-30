// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

#include <iostream>
#include <string>
using namespace std;
#ifndef PATIENT_H
#define PATIENT_H

class Patient{
    private:
        string patientName;
        int lifepoints; 
        int age; 
        int heartRate; 
        int oxygenLevel; 

    public:
        //Constructors:
        Patient();  //default constructor 
        Patient(string patientName, int lifepoints, int age, int heartRate, int oxygenLevel);  // parameterized constructor

        // Getters (or accessors)
        string getpatientName();
        int getlifepoints(); 
        int getage(); 
        int getheartRate(); 
        int getoxygenLevel(); 

        // Setters (or mutators)
        void setpatientName(string patientOne);
        void setlifepoints(int lifeOne); 
        void setage(int ageOne); 
        void setheartRate(int rateOne); 
        void setoxygenLevel(int oxyOne); 


        void displayPatientStatus(); // Displaying the patient status after every turn 
        void displayPatientProfile(); 

};

#endif