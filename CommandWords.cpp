#include <iostream>
#include <string>
#include <vector>
#include "CommandWords.h"
using namespace std; 

/*
Written by Aaron Pitman
Date: 10.5.2015
*/

/*
init Commandwords with commands
*/
CommandWords::CommandWords()
{
    validCommands.push_back("play");
    validCommands.push_back("quit");
    validCommands.push_back("help");
}
 /**
     * Check whether a given String is a valid command word. 
     * @return true if it is, false if it isn't.
     */
     bool  CommandWords::isCommand(string aString)
     {
        for(int i = 0; i < validCommands.size(); i++) {
            if(validCommands[i]==(aString))
                return true;
        }
        // if we get here, the string was not found in the commands
        return false;
    }

    /**
     * Print all valid commands to terminal
     */
     void  CommandWords::showAll() 
     {
        cout << "" << endl;
        for(vector<string>::iterator command = validCommands.begin(); 
           command != validCommands.end(); command++)
        {
            cout << *command << "  "<< endl;
        }
        cout << "" << endl;
    }
