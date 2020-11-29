// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

// Implementation device.cpp
// This is where we are defining all of our components 
#include "game.h"
#include "device.h"
#include "patient.h"
#include <iostream>
#include <cmath>
#include <fstream> 
#include <string>
using namespace std;

    int Game::randomVal(int min, int max) //parameterized constructor
    {
        srand (time(NULL));
        return (rand() % (max + min - 4)); 

    }

    bool Game::complicationMath(int stage)
    {
        int input; 
        bool complication = true; 

        switch(stage)
        {
            case 1: 
                cout << " What is the answer to the following question: 10 + 20 - 12 = ?" << endl; 
                cin >> input; 

                if(input == 18)
                {
                    complication = false; 
                    return complication; 
                }
                break; 
            case 2: 
                cout << " What is the answer to the following question: 10 x 50 - 72 = ?" << endl; 
                cin >> input; 

                if(input == 428)
                {
                    complication = false; 
                    return complication; 
                }
                break; 
            case 3: 
                cout << " What is the answer to the following question: 40 x 5 - (72 + 45) = ?" << endl; 
                cin >> input; 

                if(input == 83)
                {
                    complication = false; 
                    return complication; 
                }
                break; 
            default: 

            cout << " error in math." << endl; 
            
        }
        return complication; 
        
    }

    bool Game::complicationUnscramble(int stage)
    {
        string input; 
        bool complication = true; 

        switch(stage)
        {
            case 1: 
                cout << " Unscramble the following word: osthipla " << endl; 
                cin >> input; 

                if(input == "hospital" || input == "Hospital")
                {
                    complication = false; 
                    return complication; 
                }
                break; 
            case 2: 
                cout << " Unscramble the following word: arioldoygc " << endl; 
                cin >> input; 

                if(input == "cardiology" || input == "Cardiology")
                {
                    complication = false; 
                    return complication; 
                }
                break; 
            case 3: 
                cout << " Unscramble the following word: erbahliittaino" << endl; 
                cin >> input; 

                if(input == "rehabilitation")
                {
                    complication = false; 
                    return complication; 
                }
                break; 
            default: 

            cout << " error in unscramble." << endl; 
            
        }
        
        return complication; 
        
    }

    bool Game::complicationFacts(int stage)
    {
        char input; 
        bool complication = true; 

        switch(stage)
        {
            case 1: 
                cout << " Is the following fact T or F?: Coronary Artery Bypass Surgery is an open-heart procedure." << endl; 
                cin >> input; 

                if(input == 'T' || input == 't')
                {
                    complication = false;
                    return complication;  
                }
                break; 
            case 2: 
                cout << " Is the following fact T or F?: Memory loss is not a possible complication of Coronary Artery Bypass Surgery. " << endl; 
                cin >> input; 

                if(input == 'F' || input == 'f')
                {
                    complication = false; 
                    return complication; 
                }
                break; 
            case 3: 
                cout << " Is the following fact T or F?: Variations of minimally invasive surgery might be called port-access or keyhole surgery. " << endl; 
                cin >> input; 

                if(input == 'T' || input == 't')
                {
                    complication = false; 
                    return complication; 
                }
                break; 
            default: 

            cout << " error in facts." << endl;
        }

        return complication; 
    }

    // bool Game::complicationDevice()
    // {

    // }

   