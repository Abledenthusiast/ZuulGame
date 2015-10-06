#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef CommandWords_H
#define CommandWords_H
/*
Written by Aaron Pitman
Date: 10.5.2015
*/
class CommandWords
{
    // a constant array that holds all valid command words
    private: 
         std::vector<string> validCommands;
    public:
    /**
     * Constructor - initialise the command words.
     */
    CommandWords();
    /**
     * Check whether a given String is a valid command word. 
     * @return true if it is, false if it isn't.
     */
    bool isCommand(string aString);
    /**
     * Print all valid commands to System.out.
     */
    void showAll(); 
 
};
#endif
