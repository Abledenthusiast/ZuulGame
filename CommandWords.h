#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef CommandWords_H
#define CommandWords_H

/**
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.
 * 
 * This class holds an enumeration of all command words known to the game.
 * It is used to recognise commands as they are typed in.
 *
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
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
