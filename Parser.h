#include <iostream>
#include <string>
#include <vector>
#include "CommandWords.h"
#include "Command.h"
using namespace std;

#ifndef Parser_H
#define Parser_H

/**
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
 */
 /*
Written by Aaron Pitman
Date: 10.5.2015
*/
class Parser 
{
    private:
        CommandWords commands;  // holds all valid command words
        vector<string> reader;         // source of command input
    public:
    /**
     * Create a parser to read from the terminal window.
     */
    Parser(); 
    /**
     * @return The next command from the user.
     */
    Command getCommand(); 

    /**
     * Print out a list of valid command words.
     */
    void showCommands();

    vector<string> getInput();

    string toLowerCase(string inputString);
    string getAnswer(); 
};
#endif
