// CSCI1300 Fall 2020
// Author: Samridhi Shrestha 
// Recitation: 202 - Elizabeth Spaulding 
// Project 3

// Implementation Patient.cpp
// This is where we are defining all of our components 
#include "finaldriver.h" // Include header file
#include "patient.h"
#include "device.h"
#include "move.h"
#include "game.h"
#include <iostream>
#include <cmath>
#include <fstream> 
#include <unistd.h>
#include <cmath> 
#include <vector>
#include <string> 


using namespace std;

//Function to print out the last 15 variables 
vector<string> returnLast15(string fn)
{
        vector <string> fileResult; 
        ifstream rdFile; 
        rdFile.open(fn); 
        string line; 
        int count = 0; 
        int lineNum = 0; 
        while(getline(rdFile,line))
        {
            // cout << "test" << endl; 
            count++; 
        }

        rdFile.close(); 

        if(count < 15)
        {
            cout << "Not enough information has been stored yet." << endl; 
            return fileResult; 
        }
        else
        {

        rdFile.open(fn); 
        while(getline(rdFile,line))
        {
            cout << "test1" << endl; 
            cout << count << endl; 
            if(lineNum == count - 15)
            {
                fileResult.push_back(line); 
    
            }
            else 
            {
                lineNum++; 
            }
        }
        return fileResult; 
        }

    
 }

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

void Driver::setCompTools()
{

    string line; 
    ifstream useFile; 
    int count = 0; 
    useFile.open("deviceinfo.txt"); 
    while(getline(useFile, line))
        {
            
            string finaltools[4]; 
            split(line,',',finaltools,4); 
            tools[count] = Device(finaltools[0], stoi(finaltools[1]), stoi(finaltools[2]), stoi(finaltools[3])); 
            count++; 

        }

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

int Driver::chooseMenu(int opt)
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
        return tool; 
        break; 

        case 2: 
        menu.displayCutMenu(); 
        cout << "Which tool would you like to use?" << endl; 
        cin >> tool; 
        move.cutMove(); 
        return tool; 
        break; 

        case 3: 
        menu.displayStitchMenu(); 
        cout << "Which tool would you like to use?" << endl; 
        cin >> tool; 
        move.stitchMove(); 
        return tool; 
        break; 

        case 6: 
        return; 

        break; 

        default: 

        cout << "invalid menu input" << endl; 

    }
}


void Driver::startgame(string surgeonName,int surgeonYear) // This is the main start game componenent that the main.cpp runs through 
{

    // This is where we are implementing an array of objects from the Device Class into the Driver Class 
    setCompTools();

    //We are calling the Game class - Holds our complication mini games 
    Game game; 

    //We are calling the Patient class - Holds all of our individual patient info + reads from file
    Patient John;  
    Patient Samantha; 
    Patient Charles; 
    
    // We are declaring strings to store different values 
    string patientName;
    string line;  
    string tempOne[5];

    // We are declaring int values to store different values 
    int opt; 
    int points = 100; 
    int stage = 0; 
    int tempTwo[4]; 
    int temp; 
    int index = 0; 
    
    //We are declaring our bool value to check for complications 
    bool complication = true; 
    bool success = false; 

        // We are now first opening the file patientinfo.txt and reading the stored patient info
        ifstream theFile; 
        theFile.open("patientinfo.txt"); // Opening the file 

        if(theFile.is_open()) // Checking if the file is open 
        {
                while(getline(theFile,line)) // Iterating through the file 
            {
            
                split(line, ',', tempOne, 4); // Splitting each of the lines in the file 

                for(int i = 1; i < 4; i++)  
                {
                // This loop helps to store the first index in the original array as a string
                // We then store the values that follow as integer values 
                tempTwo[i-1] = stoi(tempOne[i]); // Converting from string to int 
                }

                if(index == 0) // Stored in line 0 
                {
                    // Setting all of the components for the patient John using those two different arrays
                    John.setpatientName(tempOne[0]); // First Array 
                    John.setlifepoints(tempTwo[0]); // Second Array 
                    John.setage(tempTwo[1]); 
                    John.setheartRate(tempTwo[2]); 
                    John.setoxygenLevel(tempTwo[3]); 
                }
                else if(index == 1) // Stored in line 1
                {
                    // Setting all of the components for the patient Samantha using those two different arrays
                    Samantha.setpatientName(tempOne[0]); // First Array 
                    Samantha.setlifepoints(tempTwo[0]); // Second Array 
                    Samantha.setage(tempTwo[1]); 
                    Samantha.setheartRate(tempTwo[2]); 
                    Samantha.setoxygenLevel(tempTwo[3]); 
                }
                else // Stored in line 2 
                {
                    // Setting all of the components for the patient Charles using those two different arrays
                    Charles.setpatientName(tempOne[0]); // First Array 
                    Charles.setlifepoints(tempTwo[0]); // Second Array 
                    Charles.setage(tempTwo[1]); 
                    Charles.setheartRate(tempTwo[2]); 
                    Charles.setoxygenLevel(tempTwo[3]); 
                }
                    

                index++; // We are counting the index or the line we are on here


            }

            
        }
        else 
        {
            // If the file does not open they need to contact the game creator (Samridhi Shrestha)
            cout << "File was not able to open. Please contact game creator." << endl; 

        }

        // We are now closing the file after all of the info has been read and stored
        theFile.close(); 

    // First prompt the surgeon and tell them what surgical procedure they will be doing
    // We will be using the surgeon name that we had captured earlier 
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 
    cout << "Hello, Dr. " << surgeonName << " today you have been given the difficult task of perfoming a Coronary Artery Bypass surgery." << endl; 
    cout << "Coronary Artery Bypass surgery is a surgical procedure that restores normal blood flow to a previously obstructed coronary artery." << endl; 
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 

    //Now we will allow for them to choose from the option of three patients depending on their skill level
    int optionPat; 
    cout << "We will allow you to choose which patient you wish to treat. We hope that you are aware of your ability level and choose wisely." << endl; 
    cout << "--------------Patient List--------------" << endl; 
    cout << "1)John Williams (Easy) " << endl; // Points needed to win : 
    cout << "2)Samantha Westworrow (Medium) " << endl; // Points needed to win : 
    cout << "3)Charles Collier (Difficutl) " << endl; // Points needed to win: 
    cout << "----------------------------------------" << endl; 
    cout << "Enter the number of your chosen patient: "; 
    cin >> optionPat; // Choosing the patient input 
    cout << endl; 
    
    // User Error Check 
    // while(optionPat != 1 || optionPat != 2 || optionPat != 3)
    // {
    // cout << "We will allow you to choose which patient you wish to treat. We hope that you are aware of your ability level and choose wisely." << endl; 
    // cout << "--------------Patient List--------------" << endl; 
    // cout << "1)John Williams (Easy) " << endl; // Points needed to win : 
    // cout << "2)Samantha Westworrow (Medium) " << endl; // Points needed to win : 
    // cout << "3)Charles Collier (Difficutl) " << endl; // Points needed to win: 
    // cout << "----------------------------------------" << endl; 
    // cout << "Enter the number of your chosen patient: "; 
    // cin >> optionPat; // Choosing the patient input 
    // cout << endl; 
    // }

    //Now we will read from the file and display the initial 
    switch(optionPat)
    {
        case 1: 
        //Displaying the main patient profile for John Williams
        cout << "----------------------------------------" << endl; 
        cout << "Patient Profile: John Williams" << endl; 
        cout << "Points needed to win: " << endl; 
        John.displayPatientProfile(); // Calling the patient profile display 
        patientName = "John"; // We are storing this as the permanent patient name for this run 
        cout << "----------------------------------------" << endl; 

        break; 

        case 2: 
        //Displaying the main patient profile for Samantha Westworrow 
        cout << "----------------------------------------" << endl; 
        cout << "Patient Profile: Samantha Westworrow" << endl; 
        cout << "Points needed to win: " << endl; 
        Samantha.displayPatientProfile(); // Calling the patient profile display 
        patientName = "Samantha"; // We are storing this as the permanent patient name for this run 
        cout << "----------------------------------------" << endl; 
        break; 

        case 3: 
        //Displaying the main patient profile for Charles Collier 
        cout << "----------------------------------------" << endl; 
        cout << "Patient Profile: Charles Collier" << endl; 
        cout << "Points needed to win: " << endl; 
        Charles.displayPatientProfile(); // Calling the patient profile display 
        patientName = "Charles"; // We are storing this as the permanent patient name for this run 
        cout << "----------------------------------------" << endl; 
        break; 

        default: 

        cout << "You did not enter a valid value. Good Bye!" << endl; 
        return; // This will terminate the progream 

    }

    // S   T   A   G   E        O   N   E ------------------------------------------ 
    //My timeline is broken down into three stages that the surgery is broken down into, verified by TA (Gabrielle Johnson + Elizabeth Spaulding)
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 
    slowPrint(200000, "+++++ S T A G E  O N E +++++\n"); // This is a function that I made to slowly print out the text to signify timeline
    stage = 1; // Changing stage value 
    cout << "We must first prepare the patient for general anesthesia and cleanse the area, then prepare the arteries for precisde extraction." << endl; 
    cout << "We will be using the veins as bypass grafts, and the heart of the patient will have to be stopped for this portion of the surgery." << endl; 
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 

    //TASK I 
    slowPrint(200000, "+++++ T A S K  O N E +++++\n"); //Slow print function call 
    cout << "First, prep the patient by cleaning area directly above their sternum, and make initial incisions in the chest." << endl; 
    displayGrandMenu(); // We are displaying the grand menu for the very first time and calling it here
    cout << "Chose your option:" << endl; // Prompting user to choose the right action 
    cin >> opt; // Input user 

    while (opt == 4 || opt == 5) // These options bring up either the patient status + Overarching tool key for game
    {
        if(opt == 4) // Patient Status Option 
        {
        
            switch(optionPat) // Choosing which patient depending on initial user input for optionPat 
            {
                case 1: 
                    John.displayPatientStatus(); // John Status 
                    break; 
                case 2: 
                    Samantha.displayPatientStatus(); // Samantha Status 
                    break; 
                case 3: 
                    Charles.displayPatientStatus(); // Charles Status
                    break; 

                default: 
                    cout << "Unable to get status." << endl; 
            }

                displayGrandMenu();  // Reiterating the grand menu to choose action 
                cout << "Chose your option:" << endl; 
                cin >> opt; // Prompting input 

        }

        if(opt == 5) // This option will read you the tool key that I have stored under toolkey.txt
        {
        
            ifstream theFile; 
            theFile.open("toolKey.txt"); // Opening the toolkey.txt

            if(theFile.is_open()) // Checking if the file is open or not 
            {
                while(getline(theFile,line)) // Reading each indiviudal line in the txt file 
                {
                    cout << line << endl; // Printing out the file contents 
                
                }
            }

            theFile.close(); // Closing the file 
        }

            displayGrandMenu(); // Displaying the grand menu again 
            cout << "Chose your option:" << endl;  
            cin >> opt; // User input option 
    }

     if(opt == 6) // This will terminate the game given that the user chooses to do so 
    {
        return; 
    }

    if(opt == 1) // This is the correct option and therefore you will gain points for choosing this input 
    {   
        chooseMenu(opt);
        if(chooseMenu(opt) == 1)
        {
             points = points + 5; // If they choose the more powerful tool they will get 5 points
        }
        else 
        {
             points = points + 2; // If they choose the less powerful tool they will get 2 points
        }
        points = points + 5; // Adding point value 
        cout << "Success! You chose the right action for this task! (+5pts)" << endl; 
    }
    
    if (opt == 2 || opt == 3) // There are incorrect options and therefore you will lose points for this input 
    {
        cout << "Failure, you chose the incorrect action for this task. (-5pts)" << endl; 
        points = points - 5; // Subtracting point value 
    }
    
     
    // COMPLICATION 1 
    slowPrint(200000, "+++++ C O M P L I C A T I O N  A L E R T +++++\n"); //Slow print function call 
    //Prompt the patient and notify them that they are facing a complication
    cout << "Oh no! You have run into your first complication. You have found a blood clot and patient is now unstable. " << endl; 
    cout << "Please complete the complication task to restabilize the patient and extract the clot from the patient." << endl; 
    int comp = game.randomVal(10,25); // This will give us a random value that will help us determine which mini game to give the user

    if(comp >= 6) // If the rand value is greater than 6 
    {
        complication = game.complicationMath(stage); // They get a math question 
    }
    else if (comp < 6 && comp >= 3) // If the rand value is less than 6 but greater than 3 
    {
        complication = game.complicationUnscramble(stage); // They get an unscramble question 
    }
    else // All other numerical events 
    {
        complication = game.complicationFacts(stage); // They get a true or false question 
    }

    // END STATEMENT 
    if(complication == false)
    {
        cout << "Congratulations! You were able to restabilize the patient and no complication points were deducted! (+5pts)" << endl; 
        points = points + 5; // Adding points 
    }
    else 
    {
        cout << "Unfortunately, you were not able to restabilize the patient and as penalty 10 points will be deducted. (-10pts)" << endl;
        points = points - 10; // Deducting points 
    }
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 
    // S   T   A   G   E        T   W   O ------------------------------------------
    slowPrint(200000, "+++++ S T A G E  T W O +++++\n"); // Initiate second stage of my timeline + slowPrint call
    stage = 2; // Changing the stage 
    cout << "Next, you must now put the bypass grafts in the appropriate places and attach the graft to the correct incisions on the patient." << endl; 
    cout << "Technically speaking this means the incision below the blocked artery to the incision made in the aorta." << endl; 
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 
    //TASK 1 
     slowPrint(200000, "+++++ T A S K  T W O +++++\n"); //Slow print function call 
    cout << "Choose the correct action to start cutting into the sternum and moving the grafts to the appropriate place." << endl; 
    displayGrandMenu(); // We are displaying the grand menu for the very first time and calling it here
    cout << "Chose your option:" << endl; // Prompting user to choose the right action 
    cin >> opt;  // Input user 
    while (opt == 4 || opt == 5)// These options bring up either the patient status + Overarching tool key for game
    {
        if(opt == 4)// Patient Status Option 
        {
        
            switch(optionPat)// Choosing which patient depending on initial user input for optionPat 
            {
                case 1: 
                    John.setlifepoints(John.getlifepoints() + points); // Updating the point values in the event that they check patient status
                    John.displayPatientStatus(); // Display Status 
                    break; 
                case 2: 
                    John.setlifepoints(John.getlifepoints() + points); // Updating the point values in the event that they check patient status
                    Samantha.displayPatientStatus(); // Display Status 
                    break; 
                case 3: 
                    John.setlifepoints(John.getlifepoints() + points); // Updating the point values in the event that they check patient status
                    Charles.displayPatientStatus(); // Display Status 
                    break; 

                default: 
                    cout << "Unable to get status." << endl; 
            }

                displayGrandMenu(); // Reiterating the grand menu to choose action 
                cout << "Chose your option:" << endl; 
                cin >> opt; // Prompting input 

        }

        if(opt == 5) // This option will read you the tool key that I have stored under toolkey.txt
        {
        
            ifstream theFile; 
            theFile.open("toolKey.txt"); // Opening the toolkey.txt

            if(theFile.is_open()) // Checking if the file is open or not 
            {
                while(getline(theFile,line)) // Reading each indiviudal line in the txt file 
                {
                    cout << line << endl; // Printing out the file contents 
                
                }
            }

            theFile.close(); // Closing the file 
        }

            displayGrandMenu(); // Displaying the grand menu again 
            cout << "Chose your option:" << endl;  
            cin >> opt; // User input option 
    }

     if(opt == 6) // This will terminate the game given that the user chooses to do so 
    {
        return; 
    }

    if(opt == 2) // This is the correct option and therefore you will gain points for choosing this input 
    {   
        chooseMenu(opt);
        if(chooseMenu(opt) == 1)
        {
             points = points + 5; // If they choose the more powerful tool they will get 5 points
        }
        else 
        {
             points = points + 2; // If they choose the less powerful tool they will get 2 points
        }
        points = points + 5; // Adding point value 
        cout << "Success! You chose the right action for this task! (+5pts)" << endl; 
    }
    
    if(opt == 1 || opt == 3)// There are incorrect options and therefore you will lose points for this input 
    {
        cout << "Failure, you chose the incorrect action for this task. (-5pts)" << endl; 
        points = points - 5; 
    }


    // COMPLICATION 1 
    slowPrint(200000, "+++++ C O M P L I C A T I O N  A L E R T +++++\n"); //Slow print function call 
    cout << "You have run into your second complication and now there is too much foreign material found in the patient. " << endl; 
    cout << "Please complete the complication task to restabilize the patient and clean up the material." << endl; 
    comp = game.randomVal(10,25); // This will give us a random value that will help us determine which mini game to give the user

    if(comp >= 6) // If the rand value is greater than 6 
    {
        complication = game.complicationMath(stage); // They get a math question 
    }
    else if (comp < 6 && comp >= 3) // If the rand value is less than 6 but greater than 3 
    {
        complication = game.complicationUnscramble(stage); // They get an unscramble question 
    }
    else // All other numerical events 
    {
        complication = game.complicationFacts(stage); // They get a true or false question 
    }

    // END STATEMENT  
    if(complication == false)
    {
        cout << "Congratulations! You were able to restabilize the patient and no complication points for deducted!" << endl; 
        points = points + 5; // Adding points 
    }
    else 
    {
        cout << "Unfortunately, you were not able to restabilize the patient and as penalty 10 points will be deducted." << endl;
        points = points - 10; // Deducting points 
    }


    // S   T   A   G   E        T   H   R   E   E ------------------------------------------
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl; 
    slowPrint(200000, "+++++ S T A G E  T H R E E +++++\n");
    stage = 3; 
    cout << "Lastly, you must enclose the correct pacing wire and chest tubing within the sternum " << endl; 
    cout << "before completing the surgery and closing the chest incision." << endl; 

    //TASK 1 
    cout << "Now that the grafts have been put into place, stitcht the patient back up." << endl; 
    displayGrandMenu(); 
    cout << "Chose your option:" << endl; 
    cin >> opt; 
    while (opt == 4 || opt == 5)// These options bring up either the patient status + Overarching tool key for game
    {
        if(opt == 4)// Patient Status Option 
        {
        
            switch(optionPat)// Choosing which patient depending on initial user input for optionPat 
            {
                case 1: 
                    John.setlifepoints(John.getlifepoints() + points); // Updating the point values in the event that they check patient status
                    John.displayPatientStatus(); // Display Status 
                    break; 
                case 2: 
                    John.setlifepoints(John.getlifepoints() + points); // Updating the point values in the event that they check patient status
                    Samantha.displayPatientStatus(); // Display Status 
                    break; 
                case 3: 
                    John.setlifepoints(John.getlifepoints() + points); // Updating the point values in the event that they check patient status
                    Charles.displayPatientStatus(); // Display Status 
                    break; 

                default: 
                    cout << "Unable to get status." << endl; 
            }

                displayGrandMenu(); // Reiterating the grand menu to choose action 
                cout << "Chose your option:" << endl; 
                cin >> opt; // Prompting input 

        }

        if(opt == 5) // This option will read you the tool key that I have stored under toolkey.txt
        {
        
            ifstream theFile; 
            theFile.open("toolKey.txt"); // Opening the toolkey.txt

            if(theFile.is_open()) // Checking if the file is open or not 
            {
                while(getline(theFile,line)) // Reading each indiviudal line in the txt file 
                {
                    cout << line << endl; // Printing out the file contents 
                
                }
            }

            theFile.close(); // Closing the file 
        }

            displayGrandMenu(); // Displaying the grand menu again 
            cout << "Chose your option:" << endl;  
            cin >> opt; // User input option 
    }

     if(opt == 6) // This will terminate the game given that the user chooses to do so 
    {
        return; 
    }

    if(opt == 3) // This is the correct option and therefore you will gain points for choosing this input 
    {   
        chooseMenu(opt);
        if(chooseMenu(opt) == 1)
        {
             points = points + 5; // If they choose the more powerful tool they will get 5 points
        }
        else 
        {
             points = points + 2; // If they choose the less powerful tool they will get 2 points
        }
        points = points + 5; // Adding point value 
        cout << "Success! You chose the right action for this task! (+5pts)" << endl; 
    }
    
    if(opt == 1 || opt == 2)// There are incorrect options and therefore you will lose points for this input 
    {
        cout << "Failure, you chose the incorrect action for this task. (-5pts)" << endl; 
        points = points - 5; 
    }

    // COMPLICATION 1 
    slowPrint(200000, "+++++ C O M P L I C A T I O N  A L E R T +++++\n"); //Slow print function call 
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
    cout << "You have run into a device complication and patient is now unstable. " << endl; 
    cout << "Please complete the complication task to restabilize the patient" << endl; 

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
                successStorage(surgeonName,patientName,surgeonYear); 
            }
            else
            { 
                failureStorage(surgeonName,patientName,surgeonYear); 
            }; 
            break; 
        case 2: 
            if(Samantha.getlifepoints() + points >= 400)
            {
                successStorage(surgeonName,patientName,surgeonYear); 
            }
            else
            {
                failureStorage(surgeonName,patientName,surgeonYear); 
            }; 
            break; 
        case 3: 
            if(Charles.getlifepoints() + points >= 500)
            {
               successStorage(surgeonName,patientName,surgeonYear); 
            }
            else
            {
                failureStorage(surgeonName,patientName,surgeonYear); 
            }; 
            break; 

        default: 
            cout << "Unable to reach a conclusion." << endl; 
    }
   
   cout << endl; 
   cout << "Here are your three latest plays..." << endl; 

   vector<string> vectorName = returnLast15("surgeoninfo.txt"); 

   for(unsigned int i = 0; i < vectorName.size(); i++)
   {
       cout << vectorName[i] << endl; 
       cout << endl; 
   }

}

//cctype
//lowercase compare 

