#include <iostream> 
#include <fstream> 
#include <string> 
#include <cmath> 
#include "finaldriver.h"

using namespace std; 

int main(){

    //Declare variables 
    Driver newgame; 
    string surgeonName; 
    int surgeonYear; 
    bool start = false; 

    //Display the initial story line 
    cout << " ++++ SHRESTHA SURGICAL SIMULATION ++++ " << endl; 
    cout << "As a med student in training it is crucial that you learn about the rapidly advancing world of robotic surgery." << endl; 
    cout << "In this simulation we will put your critical thinking skills and mental flexibility to the test while conducting a heart surgery." << endl; 
    cout << "It is a beautiful day to save lives!" << endl; 

    //Ask the user if they would like to start the game or not
    cout << "Would you like to start the surgery? Enter Y or N" << endl;
    char response;
    cin >> response;

    //Should I implement a while loop to keep generating this display until I get a true for the bool? 

        if (response == 'N' || response == 'n')
        {
            cout << "Good bye!" << endl;
            return 0; 
        }
        else if(response == 'Y' || response == 'y')
        {
            cout << "Please enter your last name: "; 
            cin >> surgeonName; 
            cout << endl; 

            cout << "Please enter your year in med school (ex. 2021, 2022...): "; 
            cin >> surgeonYear; 
            cout << endl; 

            //Writes surgeon information to this particular file to store 
            
            ofstream myfile;
            myfile.open ("surgeoninfo.txt");
            myfile << "--------------------------------" << endl;
            myfile << "Surgeon: " << surgeonName << endl;
            myfile << "Year of Medschool: " << surgeonYear << endl;
            myfile << "--------------------------------" << endl;
            myfile.close();
            
        
            //Calls the driver to initiate the start of the game
            //cout << "error1" << endl; 
            newgame.startgame(surgeonName); 
        }
        else
        {
            cout << "Your input need to be either a Y or N value." << endl; 
        }

        return 0; 

}

    



