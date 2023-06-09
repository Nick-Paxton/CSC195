#include <iostream>
#include "vector.h"
#include "myInput.h"

int main()
{
    // make two vectors
    // one for the word player is guessing
    // one for every letter in the alphabet
    nc::vector<char> word{ 'i','n','f','r','a','s','t','r','u','c','t','u','r','e' };
    nc::vector<char> blankWord{ '_','_','_','_','_','_','_','_','_','_','_','_','_','_' };
    nc::vector<char> alphabet{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    const int MAX_INCORRECT = 7;
    myInput input;
    int iChoice = 0;

    while (iChoice != 2) {
        cout << "\n\n Enter Menu option: ";
        cout << "\n 1) Start a new game";
        cout << "\n 2) Quit";
        iChoice = input.GetUserInt(1, 2);
        switch (iChoice) {
        case 1:
            cout << "\n ---------------- Starting a new game ---------------- ";
            bool playing = true;
            char currentGuess = ' ';
            int position = -1;
            int incorrect = 0;
            while (playing) {
                cout << "\n Current Incorrect Guesses: " << incorrect << "\n";
                for (int iCount = 0; iCount < word.size(); iCount++){
                    cout << blankWord[iCount] << " ";
                }
                cout << "\n";
                while (true) {
                    currentGuess = input.GetUserChar();
                    position = (int)currentGuess - 97;
                    if (position < 0 || position > 25) {
                        cout << "Invalid guess!";
                        continue;
                    }
                    else if (alphabet[position] == '_') {
                        cout << "Already guessed that character!";
                        continue;
                    }
                    else break;
                }
                bool correctGuess = false;
                bool allGuessed = true;
                alphabet[position] = '_';
                for (int iCount = 0; iCount < word.size(); iCount++) {
                    if (word[iCount] == currentGuess) {
                        blankWord[iCount] = word[iCount];
                        correctGuess = true;
                    }
                    if (blankWord[iCount] == '_') allGuessed = false;
                }
                if (!correctGuess) incorrect++;
                if (incorrect >= 7) {
                    playing = false;
                    cout << "You lose! :(";
                    iChoice = 2;
                }
                if (allGuessed) {
                    playing = false;
                    cout << "You win! :)";
                    iChoice = 2;
                }
                
            }
            break;
        }
    }
}