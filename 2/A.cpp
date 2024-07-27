/**
    Author: Shokhsanam Mubashirova
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Project 2 Task A
    This program implements constructors and destructors.
 */

#include <iostream>
#include <string>
#include "MemoryGame.hpp"
#include <cstdlib>
#include <iomanip>
using namespace std;

MemoryGame::MemoryGame() //Default Constructor
{
   numPairs=3;
   //Set data member numPairs to be 3.
   numSlots=8;
   //Set data member numSlots to be 8.
   values = new string[numSlots];
   //Allocate dynamic memory for an array of strings with numSlots elements and assign it to data member values.
   bShown = new bool[numSlots];
   //Allocate dynamic memory for an array of booleans with numSlots elements and assign it to data member bShown.
   
   for (int i = 0; i < numPairs;i++)  //Generate three random integers in [0, 999] and place them in pairs in values array
   {
        string randomInt = to_string(rand() % 1000);
        values[i * 2] = randomInt; //place the first integer to the first two slots
        values[i * 2 + 1] = randomInt; //place the second integer to the next two slots
    }
    
    
    // Set the rest elements of values to be empty strings
    for (int i = numPairs * 2; i < numSlots;i++) {
        values[i] = "";
    }
    
    // Set each element of bShown to be false
    for (int i = 0; i < numSlots;i++) {
        bShown[i] = false;
    }
}

MemoryGame::MemoryGame(int numPairs, int numSlots) //Non-default constractor
{
    if (numPairs <= 0 || numSlots <= 0 || numSlots < 2 * numPairs) //Check if the parameters are valid, if not, set default values
    {
        numPairs = 3;
        numSlots = 8;
    }

    // Set data members numPairs and numSlots
    this->numPairs = numPairs;
    this->numSlots = numSlots;

    //Allocate dynamic memory for an array of strings with numSlots elements and assign it to data member values.
    values = new string[numSlots];
    
    // Generate numPairs random integers in [0, 999] and place them in pairs in values array
    for (int i = 0; i < numPairs; ++i) {
        string randomInt = to_string(rand() % 1000);
        values[i * 2] = randomInt; // Place the first integer to the first two slots
        values[i * 2 + 1] = randomInt; // Place the second integer to the next two slots
    }
    
    // Set the rest elements of values to be empty strings
    for (int i = numPairs * 2; i < numSlots; ++i) {
        values[i] = "";
    }
    
    // Allocate dynamic memory for an array of booleans with numSlots elements and assign it to data member bShown.
    bShown = new bool[numSlots];
    
    // Set each element of bShown to be false
    for (int i = 0; i < numSlots; ++i) {
        bShown[i] = false;
    }
}

MemoryGame::MemoryGame(string* words, int size, int numSlots) //non-default constructor
{
    //Adjust numSlots if necessary
    if (size <= 0 || numSlots <= 0 || numSlots < 2 * size) {
        numSlots = 2 * size;
    }
    
    //Set data members numPairs to be formal parameter size, and numSlots to be formal parameter numSlots
    this->numPairs = size;
    this->numSlots = numSlots;
    
    // StepAllocate dynamic memory for an array of strings with numSlots elements and assign it to data member values.
    values = new string[numSlots];
    
    // Place words in pairs in values array
    for (int i = 0; i < size; ++i) {
        values[i * 2] = words[i];
        values[i * 2 + 1] = words[i];
    }
    
    // Set the rest elements of values to be empty strings
    for (int i = size * 2; i < numSlots; ++i) {
        values[i] = "";
    }
    
    // Allocate dynamic memory for an array of booleans with numSlots elements and assign it to data member bShown.
    bShown = new bool[numSlots];
    
    // Set each element of bShown to be false
    for (int i = 0; i < numSlots; ++i) {
        bShown[i] = false;
    }
}

MemoryGame::~MemoryGame() 
{
    delete[]values;
    values=nullptr;
    delete[]bShown;
    bShown=nullptr;
}

void MemoryGame::randomize()
{
    //TODO: placeholder, do not need to implement in Task A
}

void MemoryGame::display() const 
{
    //TODO: placeholder, do not need to implement in Task A
}








 