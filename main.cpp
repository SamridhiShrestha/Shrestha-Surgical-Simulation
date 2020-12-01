// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

#include <iostream> 
#include <fstream> 
#include <string> 
#include <cmath> 
#include "finaldriver.h" 

using namespace std; 

int main(){

    //Declare variables 
    Driver newgame; //This will allow us to start the game through the Driver class
    string surgeonName; // Initial intake of this variable that will be used at a later time
    int surgeonYear; // Initial intake of this variable that will be used at a later time

    //Displaying the inital storyline and what the user is in this specific simulation, character wise they are a surgeon
    cout << " ++++ SHRESTHA SURGICAL SIMULATION ++++ " << endl; 
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 
    cout << "Welcome! As an aspiring med student in training it is crucial that you learn about the rapidly advancing world of robotic surgery." << endl; 
    cout << "In this simulation we will put your critical thinking skills and mental flexibility to the test while conducting a heart surgery." << endl; 
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 
    cout << "It is a beautiful day to save lives!" << endl; 

    //Ask the user if they would like to start the game or not giving them the option to quit if they would like.
    cout << "Would you like to start the surgery? Enter Y or N" << endl;
    char response; //Input declaration
    cin >> response; // Input intake 

        if (response == 'N' || response == 'n') // This is accounting for user error given that they type either lower case/ upper case
        {
            cout << "Good bye!" << endl; // Ending game if they choose not to do the surgery 
            return 0; 
        }
        else if(response == 'Y' || response == 'y')// This is accounting for user error given that they type either lower case/ upper case
        {
            // We will be writing this information to file surgeoninfo.txt later on 
            cout << "Please enter your last name: ";
            cin >> surgeonName; // Storing the name of the player 
            cout << endl; 

            cout << "Please enter your current year in med school (ex. 2021, 2022...): "; 
            cin >> surgeonYear; // Storing the year of med school that they are in
            cout << endl; 
                    
            //Calls the driver to initiate the start of the game and stores the inputs from above 
            newgame.startgame(surgeonName,surgeonYear); 
        }
        else
        {
            cout << "Your input needed to either be a Y or N value." << endl; 
            cout << "Goodbye!" << endl; 
            //User will have to restart the game in the event that they do not provide a valid input
        }

        return 0; 

}

    



