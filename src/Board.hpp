#pragma once
#include <string>

class Board{
    std::string word;                   // string that contains the word to guess
    std::string incorrectGuesses;       // string that contains all of the incorrect guesses
    std::string correctGuesses;         // string that contains all of the correct guesses
    std::string allGuesses;             // string that contains all guesses
    int incorrectGuesses;               // string that conatins the number of incorrect guesses

public:
    bool guessLetter(char);

    bool checkIfGuessed(char);

    void printBoard();

    bool checkWin();
};