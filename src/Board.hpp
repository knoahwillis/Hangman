#pragma once
#include <string>
#include <iostream>


class Board{
    std::string word = "";              // string that contains the word to guess
    std::string incorrectGuesses;       // string that contains all of the incorrect guesses
    std::string correctGuesses;         // string that contains all of the correct guesses
    std::string allGuesses = "";        // string that contains all of the guesses

public:
    int numOfIncorrectGuesses = 0;      // int that conatins the number of incorrect guesses

    ~Board();

    void printWord();                   // prints out the word
    
    void startGame();                   // starts the game by randomly picking a word

    bool guessLetter(char);             // allows the player to guess a letter

    bool checkIfGuessed(char);          // checks if the letter has already been guessed

    void printBoard();                  // prints out the board

    bool checkEnd();                    // checks if the player has won the game
};