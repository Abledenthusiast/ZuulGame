 
#include <iostream>
#include <string>
#include <set>
#include <map>
#include "CommandWords.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"

using namespace std;

/**
*version: 2015.10.03
*author     Aaron Pitman
*/
    Room::Room(string description) 
    {
        this->description = description;
        exits = map<string, Room*>();
    }

    /**
     * Define an exit from this room.
     * @param direction The direction of the exit.
     * @param neighbor  The room to which the exit leads.
     */
    void  Room::setExit(string direction, Room* neighbor) 
    {
        exits[direction] = neighbor;
    }

    /**
     * @return The short description of the room
     * (the one that was defined in the constructor).
     */
    string  Room::getShortDescription()
    {
        return description;
    }

    /**
     * Return a description of the room in the form:
     *     You are in the kitchen.
     *     Exits: north west
     * @return A long description of this room
     */
    string  Room::getLongDescription()
    {
        return "Welcome to " + description + "\n" + getExitString();
    }

    /**
     * Return a string describing the room's exits, for example
     * "Exits: north west".
     * @return Details of the room's exits.
     */
    string  Room::getExitString()
    {
        string returnString = "Topics:";

        for(map<string, Room*>::iterator exit = exits.begin();
            exit != exits.end(); exit++)
            {
                returnString += " " + exit->first;
            }
        return returnString;
    }

    /**
     * Return the room that is reached if we go from this room in direction
     * "direction". If there is no room in that direction, return null.
     * @param direction The exit's direction.
     * @return The room in the given direction.
     */
    Room*  Room::getExit(string direction) 
    {
        if(exits.find(direction)!= exits.end())
        {
            return exits[direction];
        }
        return NULL;
    }
    string Room::getCurrentRoom()
    {
        return description;
    }