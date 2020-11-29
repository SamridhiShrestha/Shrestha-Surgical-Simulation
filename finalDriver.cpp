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
#include "game.h"
#include <iostream>
#include <cmath>
#include <fstream> 
#include <unistd.h>
#include <cmath> 


using namespace std;

//Slow Print Function 
void slowPrint(unsigned long speed, const char *s)
 {
     
    int i = 0;
    while(s[i]!=0) {
        cout << s[i++];
        cout.flush();
        usleep(speed);
    }

}

//Split Function 
int split(string text, char separator, string array[], int size){
    
    int deli_count = 0;   //the number of separators
    int array_num = 0;   //the number of elememts in array

    for (int i = 0; i < size; i++)
        array[i].clear();
    
    for (int i = 0; i< text.length(); i++) {
        if(text[i] == separator){
            
            //Increase deli_count by 1 
            deli_count++;
            array_num = deli_count + 1;
            //If the the number of elements in array is greater than the size of array, return -1
            if (array_num  > size)
                return -1;

        }
        //If text[i] is not a separator, save the characters (text[i]) in order.
        else {
            array[deli_count].append(1, text[i]);
           
        }
        
    }

    //If there's no seperator in the text, save text in array[0] and return 1
    if (text.length() != 0 && deli_count == 0) {
        array[0] = text;
        return 1;
    }

   // cout << "split issue" << endl; 
    return array_num;

    
}

//Constructors:
//default constructor 
Driver::Driver()
{
    // Empty constructor for all of theses values for they have pre-set values 
} 

void Driver::successStorage(string surgeonName,string patient, int surgeonYear)
{
    cout << "Congraulations!The surgery was a success and " << patient << " will be placed into the ICU to recover!" << endl; 
    ofstream myfile;

    myfile.open ("surgeoninfo.txt",ios::app);
    myfile << "--------------------------------" << endl;
    myfile << "Surgeon: " << surgeonName << endl;
    myfile << "Year of Medschool: " << surgeonYear << endl;
    myfile << "Status of Surgery: Success" << endl; 
    myfile << "--------------------------------" << endl;

    myfile.close();
}

void Driver::failureStorage(string surgeonName,string patient, int surgeonYear)
{
    cout << "A gloomy day has cast over the Shrestha Surgical Simulation, we have lost our patient " << patient << " ." << endl;
    ofstream myfile;
    myfile.open ("surgeoninfo.txt",ios::app);
    myfile << "--------------------------------" << endl;
    myfile << "Surgeon: " << surgeonName << endl;
    myfile << "Year of Medschool: " << surgeonYear << endl;
    myfile << "Status of Surgery: Failed" << endl; 
    myfile << "--------------------------------" << endl;
    myfile.close();
}


void Driver::displayGrandMenu()
{
            cout << "---Grand Menu---" << endl; 
            cout << "1)Clean" << endl;
            cout << "2)Cut" << endl ;
            cout << "3)Stitch" << endl ;
            cout << "4)Patient Status" << endl ;
            cout << "5)Tool Key" << endl; 
            cout << "6)Quit" << endl ;

}

void Driver::displayCleanMenu()
{
    cout << "---Clean Menu---" << endl; 
    cout << "1)Sanitary Wipe Wand"<< endl; 
    cout << "2)Suction Instrument" << endl; 
}

void Driver::displayCutMenu()
{
    cout << "---Cut Menu---" << endl; 
    cout << "1)Bipolar Instrument"<< endl; 
    cout << "2)Monopolar Instrument" << endl;
}

void Driver::displayStitchMenu()
{
    cout << "---Stitch Menu---" << endl; 
    cout << "1)Clip Appliers"<< endl; 
    cout << "2)Needle Drivers" << endl;  
}

void Driver::chooseMenu(int opt)
{
    Driver menu; 
    Move move; 
    int tool; 

    switch(opt)
    {
        case 1: 
        menu.displayCleanMenu(); 
        cout << "Which tool would you like to use?" << endl; 
        cin >> tool; 
        move.cleanMove(); 
        break; 

        case 2: 
        menu.displayCutMenu(); 
        cout << "Which tool would you like to use?" << endl; 
        cin >> tool; 
        move.cutMove(); 
        break; 

        case 3: 
        menu.displayStitchMenu(); 
        cout << "Which tool would you like to use?" << endl; 
        cin >> tool; 
        move.stitchMove(); 
        break; 

        default: 

        cout << "invalid menu input" << endl; 

    }
}


void Driver::startgame(string surgeonName,int surgeonYear)
{
    //cout << "error 2" << endl; 
    Driver driver; 
    Driver tools[6]; 
    Game game; 
    int points = 100; 
    string patientName;
    string line;  
    int opt; 
    bool complication = true; 
    int stage = 0; 

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
                split(line, ',', tempOne, 4); 
                //cout << "error 6" << endl;

                for(int i = 1; i < 4; i++)
                {
                //Here we are turning values that were originally stored as strings into integer ratings 
                tempTwo[i-1] = stoi(tempOne[i]);
                //cout << "error 7" << endl;
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
        patientName = "John";
        cout << "----------------------------------------" << endl; 

        break; 

        case 2: 

        cout << "----------------------------------------" << endl; 
        cout << "Patient Profile: Samantha Westworrow" << endl; 
        Samantha.displayPatientProfile(); 
        patientName = "Samantha";
        cout << "----------------------------------------" << endl; 
        break; 

        case 3: 

        cout << "----------------------------------------" << endl; 
        cout << "Patient Profile: Charles Collier" << endl; 
        Charles.displayPatientProfile(); 
        patientName = "Charles";
        cout << "----------------------------------------" << endl; 
        break; 

        default: 

        cout << "You did not enter a valid value. Good Bye!" << endl; 


    }

    // S   T   A   G   E        O   N   E ------------------------------------------
    slowPrint(200000, "+++++ S T A G E  O N E +++++\n");
    stage = 1; 
    cout << " We must first prepare the patient for general anesthesia and cleanse the area, then" << endl;
    cout << " prepare the arteries for surgery and extract the appropriate veins " << endl; 
    cout << "We will be using the veins as bypass grafts, and the heart of the patient will have to be stopped" << endl; 


    //TASK I 
    cout << "First prep the patient by cleaning area directly above their sternum, and make initial incisions in the chest." << endl; 
    driver.displayGrandMenu(); 
    cout << "Chose your option:" << endl; 
    cin >> opt;
    while (opt == 4 || opt == 5)
    {
        if(opt == 4)
        {
        
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

                driver.displayGrandMenu(); 
                cout << "Chose your option:" << endl; 
                cin >> opt;

        }

        if(opt == 5)
        {
        
            ifstream theFile; 
            theFile.open("toolKey.txt"); 
            //cout << "error 3" << endl;

            if(theFile.is_open())
            {
                //cout << "error 4" << endl;
                while(getline(theFile,line))
                {
                    cout << line << endl; 
                
                }
            }

            theFile.close(); 
        }

            driver.displayGrandMenu(); 
            cout << "Chose your option:" << endl; 
            cin >> opt; 
    }
    if(opt == 1)
    {   
        driver.chooseMenu(opt);
        points = points + 5; 
        cout << "Success! You chose the right action for this task! (+5pts)" << endl; 
    }
    else 
    {
        cout << "Failure, you chose the incorrect action for this task. (-5pts)" << endl; 
        points = points - 5; 
    }
     
    // COMPLICATION 1 
    cout << "You have run into your first complication and patient is now unstable. " << endl; 
    cout << "Please complete the complication task to restabilize the patient" << endl; 
    int comp = game.randomVal(10,25); 

    if(comp >= 6)
    {
        complication = game.complicationMath(stage); 
    }
    else if (comp < 6 && comp >= 3)
    {
        complication = game.complicationUnscramble(stage); 
    }
    else 
    {
        complication = game.complicationFacts(stage); 
    }

    // END STATEMENT 
    if(complication == false)
    {
        cout << "Congratulations! You were able to restabilize the patient and no complication points for deducted!" << endl; 
        points = points + 2; 
    }
    else 
    {
        cout << "Unfortunately, you were not able to restabilize the patient and as penalty 10 points will be deducted." << endl;
        points = points - 10; 
    }

    // S   T   A   G   E        T   W   O ------------------------------------------
    slowPrint(200000, "+++++ S T A G E  T W O +++++\n");
    stage = 2; 
    cout << "Next you must now put the bypass grafts in the appropriate places and attach the graft" << endl; 
    cout << "from the incision below the blocked artery to the incision made in the aorta." << endl; 

    //TASK 1 
    cout << "Choose the correct action to start the cutting and extraction of the grafts." << endl; 
    driver.displayGrandMenu(); 
    cout << "Chose your option:" << endl; 
    cin >> opt; 
    while (opt == 4 || opt == 5)
    {
        if(opt == 4)
        {
        
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

                driver.displayGrandMenu(); 
                cout << "Chose your option:" << endl; 
                cin >> opt;

        }

        if(opt == 5)
        {
        
            ifstream theFile; 
            theFile.open("toolKey.txt"); 
            //cout << "error 3" << endl;

            if(theFile.is_open())
            {
                //cout << "error 4" << endl;
                while(getline(theFile,line))
                {
                    cout << line << endl; 
                
                }
            }

            theFile.close(); 
        }

            driver.displayGrandMenu(); 
            cout << "Chose your option:" << endl; 
            cin >> opt; 
    }
    if(opt == 2)
    {   
        driver.chooseMenu(opt);
        points = points + 5; 
        cout << "Success! You chose the right action for this task! (+5pts)" << endl; 
    }
    else 
    {
        cout << "Failure, you chose the incorrect action for this task. (-5pts)" << endl; 
        points = points - 5; 
    }


    // COMPLICATION 1 
    cout << "You have run into your second complication and patient is now unstable. " << endl; 
    cout << "Please complete the complication task to restabilize the patient" << endl; 
    comp = game.randomVal(10,25); 

    if(comp >= 6)
    {
        complication = game.complicationMath(stage); 
    }
    else if (comp < 6 && comp >= 3)
    {
        complication = game.complicationUnscramble(stage); 
    }
    else 
    {
        complication = game.complicationFacts(stage); 
    }

    if(complication == false)
    {
        cout << "Congratulations! You were able to restabilize the patient and no complication points for deducted!" << endl; 
        points = points + 2; 
    }
    else 
    {
        cout << "Unfortunately, you were not able to restabilize the patient and as penalty 10 points will be deducted." << endl;
        points = points - 10; 
    }


    // S   T   A   G   E        T   H   R   E   E ------------------------------------------
    slowPrint(200000, "+++++ S T A G E  T H R E E +++++\n");
    stage = 3; 
    cout << "Lastly, you must enclose the correct pacing wire and chest tubing within the sternum " << endl; 
    cout << "before completing the surgery and closing the chest incision." << endl; 

    //TASK 1 
    cout << "Now that the grafts have been put into place, stitcht the patient back up." << endl; 
    driver.displayGrandMenu(); 
    cout << "Chose your option:" << endl; 
    cin >> opt; 
        while (opt == 4 || opt == 5)
    {
        if(opt == 4)
        {
        
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

                driver.displayGrandMenu(); 
                cout << "Chose your option:" << endl; 
                cin >> opt;

        }

        if(opt == 5)
        {
        
            ifstream theFile; 
            theFile.open("toolKey.txt"); 
            //cout << "error 3" << endl;

            if(theFile.is_open())
            {
                //cout << "error 4" << endl;
                while(getline(theFile,line))
                {
                    cout << line << endl; 
                
                }
            }

            theFile.close(); 
        }

            driver.displayGrandMenu(); 
            cout << "Chose your option:" << endl; 
            cin >> opt; 
    }
    if(opt == 3)
    {   
        driver.chooseMenu(opt);
        points = points + 5; 
        cout << "Success! You chose the right action for this task! (+5pts)" << endl; 
    }
    else
    {
        cout << "Failure, you chose the incorrect action for this task. (-5pts)" << endl; 
        points = points - 5; 
    }

    // COMPLICATION 1 
    cout << "You have run into your first complication and patient is now unstable. " << endl; 
    cout << "Please complete the complication task to restabilize the patient" << endl; 
    comp = game.randomVal(10,25);

    if(comp >= 6)
    {
        complication = game.complicationMath(stage); 
    }
    else if (comp < 6 && comp >= 3)
    {
        complication = game.complicationUnscramble(stage); 
    }
    else 
    {
        complication = game.complicationFacts(stage); 
    }

    // END STATEMENT 
    if(complication == false)
    {
        cout << "Congratulations! You were able to restabilize the patient and no complication points for deducted!" << endl; 
        points = points + 2; 
    }
    else 
    {
        cout<< "Unfortunately, you were not able to restabilize the patient and as penalty 10 points will be deducted." << endl;
        points = points - 10; 
    }

    // DEVICE COMPLICATION 2
    // cout << "You have run into a device complication and patient is now unstable. " << endl; 
    // cout << "Please complete the complication task to restabilize the patient" << endl; 

    // if(devComp >= 6)
    // {
    //     game.complicationBattery(); 
    // }
    // else 
    // {

    // }


    // END STATEMENT 
    // if(!complication)
    // {
    //     cout << "Congratulations! You were able to restabilize the patient and no complication points for deducted!(+2pts)" << endl; 
    // }
    // else 
    // {
    //     cout << "Unfortunately, you were not able to restabilize the patient and as penalty 10 points will be deducted." << endl;

    // }

    // F   I   N   A   L 
    slowPrint(200000, "+++++S U R G E R Y  C O M P L E T E D+++++\n"); 
    switch(optionPat)
    {
         case 1: 
            John.setlifepoints(John.getlifepoints() + points); 
            John.displayPatientStatus(); 
            break; 
        case 2: 
            Samantha.setlifepoints(Samantha.getlifepoints() + points); 
            Samantha.displayPatientStatus(); 
            break; 
        case 3: 
            Charles.setlifepoints(Charles.getlifepoints() + points); 
            Charles.displayPatientStatus(); 
            break; 

        default: 
            cout << "Unable to get status." << endl; 
    }

    switch(optionPat)
    {
         case 1: 
            if(John.getlifepoints() + points >= 300)
            {
                driver.successStorage(surgeonName,patientName,surgeonYear); 
            }
            else
            { 
                driver.failureStorage(surgeonName,patientName,surgeonYear); 
            }; 
            break; 
        case 2: 
            if(Samantha.getlifepoints() + points >= 400)
            {
                driver.successStorage(surgeonName,patientName,surgeonYear); 
            }
            else
            {
                driver.failureStorage(surgeonName,patientName,surgeonYear); 
            }; 
            break; 
        case 3: 
            if(Charles.getlifepoints() + points >= 500)
            {
                driver.successStorage(surgeonName,patientName,surgeonYear); 
            }
            else
            {
                driver.failureStorage(surgeonName,patientName,surgeonYear); 
            }; 
            break; 

        default: 
            cout << "Unable to reach a conclusion." << endl; 
    }
   



}

