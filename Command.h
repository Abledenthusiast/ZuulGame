#include <iostream>

using namespace std;

#ifndef Command_H
#define Command_H
/*
Written by Aaron Pitman
Date: 10.5.2015
*/
class Command
{
	private:
		string commandWord;
        string secondWord;

	public:
	Command(string firstWord, string secondWord);
    /**
     * Return the command word (the first word) of this command. If the
     * command was not understood, the result is null.
     * @return The command word.
     */
    string getCommandWord();

    /**
     * @return The second word of this command. Returns null if there was no
     * second word.
     */
    string getSecondWord();
  

    /**
     * @return true if this command was not understood.
     */
    bool isUnknown();

    /**
     * @return true if the command has a second word.
     */
    bool hasSecondWord();
};
#endif