#include <iostream>
#include "vector.h"
#include "myInput.h"

int main()
{
    // make two vectors
    // one for the word player is guessing
    // one for every letter in the alphabet
    nc::vector<char> word{ 'i','n','f','r','a','s','t','r','u','c','t','u','r','e' };
    nc::vector<char> alphabet{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    const int MAX_INCORRECT = 7;
    myInput input;
    int iChoice = 0;

    while (iChoice != 2) {
        cout << "\n\n Enter Menu option: ";
        cout << "\n 1) Start a new game";
        cout << "\n 2) Quit";
        int iChoice = input.GetUserInt(1, 2);
        switch (iChoice) {
        case 1:
            cout << "\n ---------------- Starting a new game ---------------- ";
            bool playing = true;
            char currentGuess = ' ';
            int position = -1;
            while (playing) {
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
                
            }
            break;
        }
    }
}