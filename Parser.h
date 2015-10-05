#include <iostream>
#include <string>
#include <vector>
#include "CommandWords.h"
#include "Command.h"
using namespace std;

#ifndef Parser_H
#define Parser_H

/**
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 * 
 * This parser reads user input and tries to interpret it as an "Adventure"
 * command. Every time it is called it reads a line from the terminal and
 * tries to interpret the line as a two word command. It returns the command
 * as an object of class Command.
 *
 * The parser has a set of known command words. It checks user input against
 * the known commands, and if the input is not one of the known commands, it
 * returns a command object that is marked as an unknown command.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
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
