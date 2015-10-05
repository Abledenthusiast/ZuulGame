#include <iostream>
#include <string>
#include <map>
#include "Parser.h"
#include "Room.h"
#include "Command.h"
#include "CommandWords.h"
#include "Game.h"

/**
*version: 2015.10.03
*author     Aaron Pitman
*/
using namespace std;


Game::Game() 
{
    createRooms(); 
    
    parser = Parser();
}

    /**
     * Create all the rooms and link their exits together.
     */
     void Game::createRooms()
     {
        
      
        // create the rooms
        Room *sports = new Room("sports trivia");
        Room *politics = new Room("politics trivia");
        Room *literature = new Room("literature trivia");
        Room *games = new Room("video game trivia");
        Room *outside = new Room("The landing screen for our game of trivia!");
        
        // initialise room exits
        outside->setExit("sports", sports);
        outside->setExit("politics", politics);
        outside->setExit("literature", literature);

        outside->setExit("games", games);

        sports->setExit("back", outside);
        politics->setExit("back", outside);
        literature->setExit("back", outside);

        games->setExit("back",outside);

      
        currentRoom = outside; 
          // start game outside
    }

    /**
     *  Main play routine.  Loops until end of play.
     */
     void Game::play() 
     {            
        printWelcome();

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.
        
        bool finished = false;
        while (! finished) {
            Command command = parser.getCommand();
            finished = processCommand(command);

        }
        cout << "Thank you for playing.  Good bye." << endl;
    }

    /**
     * Print out the opening message for the player.
     */
     void Game::printWelcome()
     {

        cout << " " << endl;
        cout << "Welcome to the World of Zuul!" << endl;
        cout << "World of Zuul is a new, incredibly boring trivia game." << endl;
        cout << "Type 'help' if you need help." << endl;
        cout << " " << endl;
        cout << currentRoom->getLongDescription() << endl;
    }

    /**
     * Given a command, process (that is: execute) the command.
     * @param command The command to be processed.
     * @return true If the command ends the game, false otherwise.
     */
     bool Game::processCommand(Command command) 
     {
        bool wantToQuit = false;

        if(command.isUnknown()) {
            cout << "I don't know what you mean..." << endl;
            return false;
        }

        string commandWord = command.getCommandWord();
        if (commandWord=="help") {
            printHelp();
        }
        else if (commandWord=="play") {
            goRoom(command);
        }
        else if (commandWord=="quit"||commandWord=="quit ") {
            wantToQuit = quit(command);
        }
        // else command not recognised.
        return wantToQuit;
    }

    // implementations of user commands:

    /**
     * Print out some help information.
     * Here we print some stupid, cryptic message and a list of the 
     * command words.
     */
     void Game::printHelp() 
     {
        cout << "Your goal is to answer trivia questions." << endl;
        cout << "pick a topic." << endl;
        cout << "" << endl;
        cout << "Your command words are:" << endl;
        parser.showCommands();
    
        cout << "The topics are: sports, literature, politics and games" << endl;
        cout << "type 'play' then a topic to play." << endl;
    }

    /** 
     * Try to in to one direction. If there is an exit, enter the new
     * room, otherwise print an error message.
     */
     void Game::goRoom(Command command) 
     {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            cout << "Play what?" << endl;
            return;
        }

        string direction = command.getSecondWord();

        // Try to leave current room.
        Room* nextRoom = currentRoom->getExit(direction);

        if (nextRoom == NULL) {
            cout << "That's not a topic!" << endl;
        }
        else {
            currentRoom = nextRoom;
            cout << currentRoom->getLongDescription() << endl;

            //print out the trivia question
            playTrivia();
        }
    }
    //print out the trivia question based upon topic
    void Game::printTrivia(string topic)
    {
        if(topic=="sports")
        {
            cout << "Which of the following is an NFL quarterback?" << endl;
            cout << "A: Andrew Luck" << endl;
            cout << "B: Billy-bob No Name" << endl;
            cout << "C: Aaron Pitman" << endl;
            cout << "D: Derek Jeter" << endl;
            cout << "Input whichever letter you feel is correct" << endl;
        }

            if(topic=="politics")
        {
            cout << "Which of the following is a Republican Presidential Candidate?" << endl;
            cout << "A: Andrew Luck" << endl;
            cout << "B: Billy-bob No Name" << endl;
            cout << "C: Aaron Pitman" << endl;
            cout << "D: Marco Rubio" << endl;
            cout << "Input whichever letter you feel is correct" << endl;
        }

            if(topic=="literature")
        {
            cout << "Which of the following wrote cool books?" << endl;
            cout << "A: J.R.R Tolkien" << endl;
            cout << "B: My mom" << endl;
            cout << "C: Ice-T" << endl;
            cout << "D: Patrick Star" << endl;
            cout << "Input whichever letter you feel is correct" << endl;
        }
            if(topic=="games")
        {
            cout << "In what year did The Elder Scrolls Skyrim release?" << endl;
            cout << "A: 2000" << endl;
            cout << "B: 2011" << endl;
            cout << "C: 2018" << endl;
            cout << "D: 1911" << endl;
            cout << "Input whichever letter you feel is correct" << endl;
        }

    }
    //main trivia routine. takes input to choose which game to play and which answer
    void Game::playTrivia()
    {
        bool answer = false;
        if(currentRoom->getCurrentRoom()=="sports trivia")
            {
                //keep the game going if the user inputs the wrong answer
                while(!answer)
                {


                    printTrivia("sports");
                    if(parser.getAnswer()=="a")
                    {
                        cout << "correct!" << endl;
                        answer = true;
                        currentRoom = currentRoom->getExit("back");
                        cout << "pick your next topic" << endl;
                    }
                    else{
                        cout << "Nope. Sorry" << endl;
                    }
                }
            }
              if(currentRoom->getCurrentRoom()=="politics trivia")
            {
                while(!answer)
                {
                    printTrivia("politics");
                    if(parser.getAnswer()=="d")
                    {
                        cout << "correct!" << endl;
                        answer = true;
                        currentRoom = currentRoom->getExit("back");
                        cout << "pick your next topic" << endl;
                    }
                    else{
                        cout << "Nope. Sorry" << endl;
                    }
                }
            }

             if(currentRoom->getCurrentRoom()=="literature trivia")
            {
                while(!answer)
                {
                    printTrivia("literature");
                    if(parser.getAnswer()=="a")
                    {
                        cout << "correct! ...Probably..." << endl;
                        answer = true;
                        currentRoom = currentRoom->getExit("back");
                        cout << "pick your next topic" << endl;
                    }
                    else{
                        cout << "Nope. Sorry" << endl;
                    }
                }
            }

             if(currentRoom->getCurrentRoom()=="video game trivia")
            {
                while(!answer)
                {
                    printTrivia("games");
                    if(parser.getAnswer()=="b")
                    {
                        cout << "correct!" << endl;
                        answer = true;
                        currentRoom = currentRoom->getExit("back");
                        cout << "pick your next topic" << endl;

                    }
                    else{
                        cout << "Nope. Sorry" << endl;
                    }
                }
            }
    }
    

    /** 
     * "Quit" was entered. Check the rest of the command to see
     * whether we really quit the game.
     * @return true, if this command quits the game, false otherwise.
     */
     bool Game::quit(Command command) 
     {
        if(command.hasSecondWord()) {
            cout << "Quit what?" << endl;
            return false;
        }
        else {
            return true;  // signal that we want to quit
        }
    }