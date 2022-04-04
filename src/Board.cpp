#include "Board.hpp"

bool Board::guessLetter(char c){
    for(int i = 0; i < this->word.size(); i++){
        if(this->word[i] == c){
            this->correctGuesses += c;
            this->allGuesses += c;
            return true;
        }
    }
    this->incorrectGuesses++;
    this->incorrectGuesses += c;
    this->allGuesses += c;
    return false;
};

bool Board::checkIfGuessed(char c){
    for(int i = 0; i < this->word.size(); i++){
        if(this->word[i] == c){
            return true;
        }
    }
    return false;
};

void Board::printBoard(){

};

bool Board::checkWin(){
    if(correctGuesses == word){
        return true;
    }
    return false;
};