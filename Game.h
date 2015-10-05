#include <iostream>
#include <string>
#include <map>

#include "Parser.h"
#include "Room.h"


using namespace std;

#ifndef Game_H
#define Game_H
/**
 *  This class is the main class of the "World of Zuul" application. 
 *  "World of Zuul" is a very simple, text based adventure game.  Users 
 *  can walk around some scenery. That's all. It should really be extended 
 *  to make it more interesting!
 * 
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 * 
 *  This main class creates and initialises all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
 */


/**
*version: 2015.10.03
*author     Aaron Pitman
*/
class Game 
{
    private:
        Parser parser;
        Room* currentRoom;

        /**
        * Create all the rooms and link their exits together.
        */
        void createRooms();

        /**
        * Print out the opening message for the player.
        */
        void printWelcome();

        /**
        * Given a command, process (that is: execute) the command.
        * @param command The command to be processed.
        * @return true If the command ends the game, false otherwise.
        */
        bool processCommand(Command command); 

        /**
     * Print out some help information.
     * Here we print some stupid, cryptic message and a list of the 
     * command words.
     */
        void printHelp();

        /** 
     * Try to in to one direction. If there is an exit, enter the new
     * room, otherwise print an error message.
     */
        void goRoom(Command command); 

    /** 
     * "Quit" was entered. Check the rest of the command to see
     * whether we really quit the game.
     * @return true, if this command quits the game, false otherwise.
     */
        bool quit(Command command); 

        void printTrivia(string topic);
        void playTrivia();
    public:   
    /**
     * Create the game and initialise its internal map.
     */
    Game(); 

      /**
     *  Main play routine.  Loops until end of play.
     */
    void play(); 

};

#endif
