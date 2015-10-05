/**
* 
* Runs the zuul game
**/
#include <iostream>
#include <string>
#include "CommandWords.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Game.h"
using namespace std;

/**
*version: 2015.10.03
*author     Aaron Pitman
*main function for Zuul. 
*launches game.
*/
int main()
{
/**
*test code for a few individual modules of Zuul
*/
	//CommandWords command;
	//command.showAll();
	//Command testCommand("go", "west");
	//cout << testCommand.getCommandWord() << endl;
	//cout << testCommand.getSecondWord() << endl;
	//cout << command.isCommand("go")<<  endl;
	//cout << command.isCommand("exit")<< endl;
	//cout << command.isCommand("stop")<< endl;
	//Parser parser;
	//parser.getCommand();
	//parser.showCommands();
	Game theGame;
	theGame.play();
}