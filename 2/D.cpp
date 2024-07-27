/**
    Author: Shokhsanam Mubashirova
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Project 2 Task D
    This program implements input and play methods
*/

#include "MemoryGame.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

MemoryGame::MemoryGame(): MemoryGame(3,8)
{

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

    // Set the rest elements of values to be empty strings
    for (int i =0;i<numPairs * 2; i+=2)
    {
        values[i] = values[i+1] = to_string(rand() % (999 - 0 + 1) + 0);
    }

    for(int i = numPairs*2; i < numSlots; i++)
        values[i] = "";

    bShown = new bool[numSlots];
    for(int j = 0; j < numSlots; j++)
        bShown[j] = false;  
}

MemoryGame::MemoryGame(string* words, int size, int numSlots) //non-default constructor
{
    int j = 0;
    for (int i = 0; ((j < size) && (i < numSlots)); i += 2) 
    {
        values[i] = words[j];
        values[i + 1] = words[j];
        j++;
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
    // Initialize size to be the number of elements of array values
    int size = numSlots;

    // Generate random index in [0, size) and swap elements until size is 1
    while (size > 1) {
        // Generate a random index in [0, size)
        int random = rand() % size;

        // Swap the element at the random index with the last element in values
        swap(values[random], values[size - 1]);

        // Reduce size by 1 to exclude the last element from further randomization
        size--;}
}

void printSeparatedLine(int size)
{
    cout << "+"; //the first +
    //draw -----+ for (size) many times 
    for (int i = 0; i < size; i++)
    {
        cout << "-----+";
    }
    cout << endl;
}

void MemoryGame::display() const 
{
    //print labels
    cout << " ";
    for (int i = 0; i < numSlots; i++)
    {
        cout <<setw(3)<<i<<setw(3)<<" ";
    }
    cout<<endl;
    printSeparatedLine(numSlots);
    
    cout<<"|";
   
    for(int i=0; i<numSlots; i++)
    {
        if(bShown[i]){
            cout<<setw(5)<<values[i]<<"|";}
        else
        {
            cout<<"     |";
        }
    }
    cout<<endl;
    printSeparatedLine(numSlots);
}

int MemoryGame::input() const
{
    int i=0;
    cout << "Enter an unflipped card in [0, " << numSlots - 1 << "]: ";
    cout<<endl;

    while (true)
    {
        cin >> i;

        if (i >= 0 && i < numSlots && !bShown[i])
        {
            break;
        } 
        else if (i < 0 || i >= numSlots)
        {
            cout << "Input is not in [0, " << numSlots - 1 << "]. Re-enter: ";
        }
        else
        {
            cout << "The card is already flipped. Re-enter: ";
        }
        cout<<endl;
    }
    return i;
}

void MemoryGame::play()
{
    randomize();
    display();

    int round = 0;
    int pairsFound = 0;
    int index;
    int first;
    
    while (pairsFound < numPairs)
    {
        round++;
        cout<<"Round "<<round<<":"<<endl;

        index=input();
        bShown[index]=true;
        first=index;
        display();
        round++;
        cout<<"Round "<<round<<":"<<endl;
        index=input();

        if(values[index]==values[first] && values[index] !="")
        {
            bShown[index]=true;
            pairsFound++;
        }
        else
        {
            bShown[first]=false;
        }
        display();
    }
    cout<<"Congratulations! Found all pairs in "<<round<<" rounds"<<endl;
}


        