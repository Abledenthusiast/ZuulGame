
#include <iostream>
#include <string>
#include <vector>

#include "CommandWords.h"
#include "Command.h"
#include "Parser.h"

/**
 * @author  Michael Kölling and David J. Barnes
 * @author Aaron Pitman 
 * @version 2011.08.08
 * @version 2015.10.03
 */

using namespace std;
    /**
     * Create a parser to read from the terminal window.
     */
    Parser::Parser() 
    {
       // commands = CommandWords();
       // reader = getInput();
    }

    /**
     * @return The next command from the user.
     */
    Command Parser::getCommand() 
    {
        string inputLine;   // will hold the full input line
        string word1 = "";
        string word2 = "";
        reader = getInput(); // read the user's input
        //inputLine = reader;

        if(reader[0] != "")
        {
            word1 = reader[0];
        }

        if(reader[1] != "")
        {
            word2 = reader[1];
        }
        // Now check whether this word is known. If so, create a command
        // with it. If not, create a "null" command (for unknown command).
        if(commands.isCommand(word1)) {
            return Command(word1, word2);
        }
        else {
            return Command("", word2); 
        }
    }
    //Get the input and return each individual word inside of a vector
    vector<string> Parser::getInput() 
    {
        cout << "> ";
        // print prompt
        string inputLine;                //reader.nextLine().trim().toLowerCase();
        getline(cin, inputLine); 
        inputLine = toLowerCase(inputLine); // transform the words to all lowercase
        

        vector<string> words;
        int location = inputLine.find_first_of(" ");


        if(inputLine.find_first_of(" ")==string::npos)
            {
                words.push_back(inputLine);
                words.push_back("");     // in the case where the user only input one word
            }
            //take each word input and put them into a vector (basically split)
        while(location != string::npos)
        {
            string word = inputLine.substr(0,location);
            if(word != "")
            {
                words.push_back(word);
            }
            inputLine = inputLine.substr(location+1);
            location = inputLine.find_first_of(" ");
        }
        words.push_back(inputLine);
        
        return words;
    }
    // take each word and make it lower case
     string Parser::toLowerCase(string inputString)
    {
        string result;
        result = "";
        for(int i = 0; i <inputString.length(); i++)
        {
            result = result + 
                char(tolower(inputString[i]));
        }
       
        return result;

    }
    /**
     * Print out a list of valid command words.
     */
    void Parser::showCommands()
    {
        commands.showAll();
    }

     string Parser::getAnswer() 
    {
        string inputLine;   // will hold the full input line
        string word1 = "";
        string word2 = "";
        reader = getInput(); // read the user's input
        //inputLine = reader;

        if(reader[0] != "")
        {
            word1 = reader[0];
        }
        return word1;
        
    }

