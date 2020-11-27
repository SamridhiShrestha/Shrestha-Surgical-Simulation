// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

// Implementation Patient.cpp
// This is where we are defining all of our components 
#include "finaldriver.h" // Include header file
#include "patient.h"
#include "time.h"
#include "device.h"
#include "move.h"
#include <iostream>
#include <cmath>
#include <fstream> 
#include <unistd.h>


using namespace std;

// MANIPULATE SO THAT IT IS FITTING TO WHAT I AM DOING 
void slowPrint(unsigned long speed, const char *s)
 {
    int i = 0;
    while(s[i]!=0) {
        cout << s[i++];
        cout.flush();
        usleep(speed);
    }

}

int split(string split, char seperator, string array[], int arrayNum)
{  
    // We need to check for a seperator
    int i; 
    int a = 0; 
    bool found = false; // we have to check whether there is a delimiter present or not 


        while( a < split.size() && found == false) // this is going through all of the indexes to make sure there is a delimiter present 
        {

            if(split[a] == seperator){ // if there is a seperator found we return the value as true 
                found = true; 
            }else{
                a++; // if not we keep searching the string till there is one or it terminates and ends as a false value 
            }

        }


        // The string is split into more pices than the array
        // cout << " a value:" << a << endl; // testing 
        // cout << found << endl; // prints 0

            
        int j = -1;
        int b = 0;

        if(found == true) // in the event there is a delimiter the following code will execute 
        {
            //Start to extract the strings and assign them to array variables 
            for( int i = 0; i <= split.length(); i++)  // we are going through all of the values and printing out only the sperated strings 
            
            {

            
                if(split[i] == seperator)

                {   
                        
                    string temp = split.substr(j + 1 , i - (j + 1)); // this is creating the new substrings from the original strings 
                    j = i; 
                    array[b] = temp; 
                    b++; // we are also counting how many seperated strings or how many arrays are now present 
                } 


            }
            
            
            string temp = split.substr(j + 1 , i - (j + 1)); // this is taking care of the edge case where there isnt a delimiter at the end 
            

                if(temp != "") // nwe are taking care of this by essentially telling it to create a index variable when it reaches the end 

                {
                    array[b] = temp;  
                    b++; 
                }


                if( b > arrayNum) // this is for the case that the number of values are bigger than the capacity of the array or not 
                {
                    return -1; // if it is then it prints -1 

                }else{ 

                    return b; // if it is normal than it just prints the total number of arrays 

                }
                

        }else if(split.size() > 1 && found == 0){ // this is for the edge case that the character is empty 
    
            return 0; 

        }else{ 


            // Return 1 an put the entire string as the first variable of the array
            array[b] = split;
            return 1;

        }


}

//Constructors:
//default constructor 
Driver::Driver()
{
    // Empty constructor for all of theses values for they have pre-set values 
} 

// parameterized constructor
Driver::Driver(string patient[], int curtimeLeft, bool curStable, bool deviceStatus, bool cursurgerySuccess)
{

        stable = curStable; 
        surgerySuccess = cursurgerySuccess; 
} 


// Getters (or accessors)
string Driver::getpatient(int patindex)
{
    return patient[patindex].getpatientName(); 
}

int Driver::gettimeLeft()
{
    return 0; 
}

int Driver::getstable()
{

    return 0; 
}

int Driver::getdevicePower()
{
    return 0; 
}

int Driver::getsurgerySuccess()
{
    return 0; 
}

// Setters (or mutators)

void Driver::setstable(bool curStable)
{
    stable = curStable; 
    // This will be updated after each move and update depending on whether a correct move was made or not 
} 

void Driver::displayDeviceMenu()
{
            cout << "---Device Options---" << endl; 
            cout << "1.Bipolar Instrument" ;
            cout << "2.Monopolar Instrument" << endl ;
            cout << "3.Needle Driver" << endl ;
            cout << "4.Suction Instrument" << endl ;
            cout << "5.Anesthesia Tube" << endl; 
            cout << "6.Cleaning Gauze" << endl ;

}

void Driver::startgame(string surgeonName)
{
    //cout << "error 2" << endl; 
    Driver deviceMenu; 
    string line;  

    string tempOne[5]; 
    int tempTwo[4]; 

    int temp; 
    int index = 0; 

    Patient John; 
    Patient Samantha; 
    Patient Charles; 

        ifstream theFile; 
        theFile.open("patientinfo.txt"); 
        //cout << "error 3" << endl;

        if(theFile.is_open())
        {
            //cout << "error 4" << endl;
                while(getline(theFile,line))
            {
            
            //cout << "error 5" << endl;
                split(line, ',', tempOne, 5); 

                for(int i = 1; i < 5; i++)
                {
                //Here we are turning values that were originally stored as strings into integer ratings 
                tempTwo[i-1] = stoi(tempOne[i]);

                }

                if(index == 0)
                {
                    John.setpatientName(tempOne[0]); 
                    John.setlifepoints(tempTwo[0]); 
                    John.setage(tempTwo[1]); 
                    John.setheartRate(tempTwo[2]); 
                    John.setoxygenLevel(tempTwo[3]); 
                }
                else if(index == 1)
                {
                    Samantha.setpatientName(tempOne[0]); 
                    Samantha.setlifepoints(tempTwo[0]); 
                    Samantha.setage(tempTwo[1]); 
                    Samantha.setheartRate(tempTwo[2]); 
                    Samantha.setoxygenLevel(tempTwo[3]); 
                }
                else 
                {
                    Charles.setpatientName(tempOne[0]); 
                    Charles.setlifepoints(tempTwo[0]); 
                    Charles.setage(tempTwo[1]); 
                    Charles.setheartRate(tempTwo[2]); 
                    Charles.setoxygenLevel(tempTwo[3]); 
                }
                    

                index++; 


            }

            
        }else 
        {
            cout << "bad" << endl; 
        }

        theFile.close(); 
        //Read the file using get line turn the line into a string 
        //Use split function to break apart the string 



    //First prompt the surgeon and tell them what they will be doing in this surgery
    cout << "Hello, Dr. " << surgeonName << " today you have been given the task of perfoming a coronary artery bypass surgery." << endl; 
    cout << "Coronary artery bypass surgery is a surgical procedure that restores normal blood flow to a previously" << endl; 
    cout << "obstructed coronary artery." << endl; 

    //Now we will allow for them to choose from the option of three patients
    int optionPat; 
    cout << "We will allow you to choose which patient you wish to treat. We hope that you are aware of your ability level and choose wisely." << endl; 
    cout << "--------------Patient List--------------" << endl; 
    cout << "1)John Williams (Easy) " << endl; 
    cout << "2)Samantha Westworrow (Medium) " << endl; 
    cout << "3)Charles Collier (Difficutl) " << endl; 
    cout << "----------------------------------------" << endl; 
    cout << "Enter the number of your chosen patient: "; 
    cin >> optionPat;  
    cout << endl; 
    
    //Now we will read from the file and display the patient stats and information 
    switch(optionPat)
    {
        case 1: 
        
        cout << "----------------------------------------" << endl; 
        cout << "Patient Profile: John Williams" << endl; 
        John.displayPatientProfile(); 
        cout << "----------------------------------------" << endl; 

        break; 

        case 2: 

        cout << "----------------------------------------" << endl; 
        cout << "Patient Profile: Samantha Westworrow" << endl; 
        Samantha.displayPatientProfile(); 
        cout << "----------------------------------------" << endl; 
        break; 

        case 3: 

        cout << "----------------------------------------" << endl; 
        cout << "Patient Profile: Charles Collier" << endl; 
        Charles.displayPatientProfile(); 
        cout << "----------------------------------------" << endl; 
        break; 

        default: 

        cout << "You did not enter a valid value. Good Bye!" << endl; 


    }

    // S   T   A   G   E        O   N   E ------------------------------------------
    slowPrint(200000, "+++++ S T A G E  O N E +++++\n");
    // DISPLAY PROMPT 
    cout << " We must first prepare the patient for general anesthesia and cleanse the area. " << endl;
    cout << " Please check the patient status and choose the correct tools and moves to follow through with this stage. " << endl;  
    // -Display Patient Status 
    switch(optionPat)
    {
        case 1: 
            John.displayPatientStatus(); 
            break; 
        case 2: 
            Samantha.displayPatientStatus(); 
            break; 
        case 3: 
            Charles.displayPatientStatus(); 
            break; 

        default: 
            cout << "Unable to get status." << endl; 
    }
    // -Display Tools 
    //Menu.displayDeviceMenu(); 
    // -Display Display Moves 

            // Display the moves 
            //     -Cut 
            //     -Suture 
            //     -Clean 
            // Display the devices 
            //     -Cut 
            //         -tool 
            //         -tool 
            //     -Suture 
            //         -tool 
            //         - 
            //     Clean 
            //         - 
            //         - 
    //Tool Status 
    //Patient Status 
    // -Display Prompt 
    // -Display Tools 
    // -Display Display Moves 
    //Display Stable 

    // S   T   A   G   E        T   W   O ------------------------------------------
    // slowPrint(200000, "+++++ S T A G E  T W O +++++\n");
    // // S   T   A   G   E        T   H   R   E   E ------------------------------------------
    // slowPrint(200000, "+++++ S T A G E  T H R E E +++++\n");
    // // S   T   A   G   E        F   O   U   R ------------------------------------------
    // slowPrint(200000, "+++++ S T A G E  F O U R +++++\n");
    // // S   T   A   G   E        F   I   V   E------------------------------------------
    // slowPrint(200000, "+++++ S T A G E  F I V E +++++\n");

    // F   I   N   A   L 


}

