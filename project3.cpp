#include <iostream>
#include<fstream>
#include<string>
#include<cctype> 
#include <iomanip> 
#include "finaldriver.h"
using namespace std;

// -------- GAME PLAY BREAK DOWN --------- 

//                      +++ SURGERY MINUS THE LAWSUIT +++ 
// -A surgical simulation made by your favorite comp sci major pre-med student-

// 1) Welcome the user to the main screen
//     -cout << welcome message << endl: 
// 2) Allow the player to choose from three patients: 
//     - Easy : Kim, 18 >>> 
//     - Medium : Tiffany, 36 >>> 
//     - Hard : Kevin, 89 >>> 
//         -File reading function for all of these characters are going to 
//         be put into one file
//         -Each patient will have the following information stored for vitals: 
//             -heartRate 
//             -oxygenLevel 
//             -temperature

// Devices: All of these devices are gonna have the following componenets kept track of: 
//     - The specific tool that they are using from the list below 
//     - The status of the overall device 
//         -Warning message comes when there is 30 mins left 
//         -Point value: -10 
//     - The battery: 
//         -Decreases by 10% every move
//     - Power: 
//         - set it to the right power amount to accumulate 5 points 
//         - set it to the wrong power amount and lose 5 points 
// -Knife: FUNCTION 
//     -  Incision 
//     - Power == 30 < x < 38 
//     - Status == True if power is within range 
// -Laser: FUNCTION 
//     - Suture 
//     - Power == 10 < x < 20 
//     - Status == True if power is within range 
// -Disposal Vaccum: FUNCTION 
//     - Clean 
//     - Power == 10 < x < 50 
//     - Status == True if power is within range 

// Moves 
// -Incision: FUNCTION 
//     - Duration : 20 mins time reduce 
// -Suture: FUNCTION 
//     - Duration : 20 mins time reduce 
// -Clean: FUNCTION 
//     - Duration : 10 mins time reduce 

// HELPER FUNCTIONS 
// - getDeviceStats
//     - This will give a real time state evaluation on the device and produce a printed 
//     redport of the battery, status.. etc. 
// - getUserVitals 
//     -This will produce a real time evaluation of the patients vitals and produce an outcome 
//     to figure out if they are stable or not 
//         -This will help to indicate whether the player is closer to winning or losing
// - getcurrentPointCOunt
//     -This will update the player how many points they have currently accumulated and updates 
//     every single move that they will make
// - getCurrentTime 
//     -This will account for the moves made so far and create a value for the time that the user 
//     has left in order to complete the surgery

// DIFFERENT SEQUENCES FOR EACH PLAYER 

// -The main difference between these three players is going to be the number of steps that they 
// have to do correctly to accumulate the minimum number of steps

// EASY : KIM 
// 1. MIN VALUE == 100 
//     -They need to make 5 exact moves win 
//     -Timer set at 4 hours 
//     -Time does not affect point val 
//     -Status of device doesnt affect point val 

//     Sequence to win this game: 
//     1) Knife 
//     2) Knife 
//     3) Vaccumm 
//     4) Laser 
//     5) Vaccumm 


// MEDIUM : TIM 
// 1. MIN VALUE == 200 
//     -They need to make 8 exact moves to win 
//     -Timer set at 3 hours 
//     -Time does affect the point val 
//     -Status of the device does not affect the point val 

//     Sequence to win this game: 
//     1) Knife 
//     2) Knife 
//     3) Vaccumm 
//     4) Laser 
//     5) Vaccumm 
//     6) Laser 
//     7) Knife 
//     8) Vaccumm 

// HARD : JENNY 
// 1. MIN VALUE == 300 
//     -Timer set at 2 hour 
//     -Time and Status affect the total point val 
//     -They need to make the exact 10 sequence of moves to win 

//     Sequence to win this game: 
//     1) Knife 
//     2) Knife 
//     3) Vaccumm 
//     4) Laser 
//     5) Vaccumm 
//     6) Laser 
//     7) Knife 
//     8) Vaccumm 
//     9) Knife 
//     10) Vaccum 

// 3) The main objective of the game is to accumulate at least THE MIN VALUE of points by making a sequence of 
// 10 correct decisions each worth 10 points. 
//     - Final verdict on the surgery passing and falling are: 
//         - Battery > 0 
//         - Status = true 
//         - Stable = true
//         - Points > min value 
//     -If the final point count >= MIN VALUE then the surgery was a success
//         -Prompt the play again button 
//         -Promp the quit button 
//     -If the final point count < MIN VALUE  then the surgery was a failure 
//         -Prompt the play again button 
//         -Prompt the quit button 


int main()
{
    // In case this gets compiled :) 
    cout << " Please feel free to make suggestions with strucutre, I need all of the help that 
    I can get and I am a little worried I am overstepping on this project so please suggest methods 
    that would keep this manageable and structured! " << endl; 

}