// Hangman Honors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

int main()
{ //start screen
    char gameStart{};



    cout << "     Hangman     " << endl;
    cout << "By Ali Mohammadiasl" << endl;
    cout << "_____________   " << endl;
    cout << "|       }     " << endl;
    cout << "|       O     " << endl;
    cout << "|       |     " << endl;
    cout << "|     / | \\  " << endl;
    cout << "|    /  |  \\ " << endl;
    cout << "|      / \\    " << endl;
    cout << "|     /   \\   " << endl;
    cout << "\nPress any key and then press ENTER to start!\n";
    cin >> gameStart;
    //GAME
            //variables used throughout the game
    int tries{ 6 }; //Number of guesses
    char guess; //Letter guessed
    bool CorrectGuess = false;
    string Word; //Word the player has to guess
    string WordList[99];// array of 100 words


    srand(time(NULL)); //creates a random seed which i used to get a random word from the array WordList

    ifstream RandomWord; //Get random, reads variable from the word list
    RandomWord.open("WordsList.txt"); //reads in the list of words


    for (int i = 0; i < 99; i++) {
        RandomWord >> WordList[i];
    }

    int RandNum = rand() % 100; //Returns a random number between 0 and 99
    Word = WordList[RandNum];
    cout << Word << endl; //testing
    RandomWord.close();

    //Make word a msytery

    string Mystery(Word.length(), '*'); //replaces each letter of the word with a * and sves it in Mystery

   


    while (tries >= 0) {
        CorrectGuess = false;

        cout << "The Word is:\n\n";
        cout << Mystery << endl;
        cout << "\nThere are " << Mystery.length() << " letters in the word\n\n";
        cout << "You have " << tries << " guesses left\n";

        cout << "\nGuess a letter: ";
        cin >> guess;

        //check if guess is correct
        for (int i = 0; i < Mystery.length(); i++) { //for the length of the word
        
            if (Word[i] == guess) {
                Mystery[i] = guess;
                cout << "Congrats! " << guess << " is one of the letters!" << endl;
                CorrectGuess = true;
            }
        }
        if (Word == Mystery) {
            cout << "\n\nCongrats! You have guesed the word: " << Mystery << endl;
            break;
        }
        if (CorrectGuess == false) {
            tries--;
            cout << "Woops, " << guess << " is not a part of the word" << endl;
        }
        else {
            cout << "Congrats! " << guess << " is one of the letters!" << endl;
        }
        
        switch (tries)
        {
        case 6: {
            cout << "_____________   " << endl;
            cout << "|       }       " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            break;
        }
        case 5: {
            cout << "_____________   " << endl;
            cout << "|       }       " << endl;
            cout << "|       O       " << endl;
            cout << "|              " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            break;
        }
        case 4: {
            cout << "_____________   " << endl;
            cout << "|       }       " << endl;
            cout << "|       O       " << endl;
            cout << "|       |       " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            break;
        }
        case 3: {
            cout << "_____________   " << endl;
            cout << "|       }       " << endl;
            cout << "|       O       " << endl;
            cout << "|       |       " << endl;
            cout << "|     / |       " << endl;
            cout << "|    /  |       " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            break;
        }
        case 2: {
            cout << "_____________   " << endl;
            cout << "|       }       " << endl;
            cout << "|       O       " << endl;
            cout << "|       |       " << endl;
            cout << "|     / | \\    " << endl;
            cout << "|    /  |  \\   " << endl;
            cout << "|               " << endl;
            cout << "|               " << endl;
            break;
        }
        case 1: {
            cout << "_____________   " << endl;
            cout << "|       }       " << endl;
            cout << "|       O       " << endl;
            cout << "|       |       " << endl;
            cout << "|     / | \\    " << endl;
            cout << "|    /  |  \\   " << endl;
            cout << "|      /        " << endl;
            cout << "|     /         " << endl;
            break;
        }
        case 0: {
            cout << "_____________   " << endl;
            cout << "|       }       " << endl;
            cout << "|       O       " << endl;
            cout << "|       |       " << endl;
            cout << "|     / | \\    " << endl;
            cout << "|    /  |  \\   " << endl;
            cout << "|      / \\     " << endl;
            cout << "|     /   \\    " << endl;
            cout << "\nGAME OVER! The word was: " << Word << endl;
            tries = -1;
            break;
        }

        }



        
    }
    return 0;
}
