
#include <iostream>
#include <string>
#include <map>
#include "CommandWords.h"
#include "Command.h"
#include "Parser.h"

using namespace std;

#ifndef Room_H
#define Room_H

/**
*version: 2015.10.03
*author     Aaron Pitman
*/
class Room 
{
    private:
        string description;
        map<string, Room*> exits;    // stores exits of this room.
         /**
     * Return a string describing the room's exits, for example
     * "Exits: north west".
     * @return Details of the room's exits.
     */
    
        string getExitString();    

    public:       
    /**
     * Create a room described "description". Initially, it has
     * no exits. "description" is something like "a kitchen" or
     * "an open court yard".
     * @param description The room's description.
     */
        Room(string description);

    /**
     * Define an exit from this room.
     * @param direction The direction of the exit.
     * @param neighbor  The room to which the exit leads.
     */
   void setExit(string direction, Room* neighbor); 

    /**
     * @return The short description of the room
     * (the one that was defined in the constructor).
     */
    string getShortDescription();


    /**
     * Return a description of the room in the form:
     *     You are in the kitchen.
     *     Exits: north west
     * @return A long description of this room
     */
    string getLongDescription();
    /**
     * Return the room that is reached if we go from this room in direction
     * "direction". If there is no room in that direction, return null.
     * @param direction The exit's direction.
     * @return The room in the given direction.
     */
    Room* getExit(string direction); 

    string getCurrentRoom();
};

#endif

