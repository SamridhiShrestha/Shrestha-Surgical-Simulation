#include "finaldriver.h" // Include header file
#include "patient.h"
//#include "time.h"
//#include "device.h"
#include "move.h"
#include "game.h"
#include <iostream>
#include <cmath>
#include <fstream> 
#include <unistd.h>
#include <cmath> 
#include <vector>

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
            cout << "test" << endl; 
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

 int main()
 {
    
    vector<string> vectorName = returnLast15("surgeoninfo.txt"); 

   for(unsigned int i = 0; i < vectorName.size(); i++)
   {
       cout << vectorName[i] << endl; 
       cout << endl; 
   }
 }