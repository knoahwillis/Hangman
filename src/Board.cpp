#include "Board.hpp"

void Board::startGame(){
    srand(time(0));
    this->word = this->words[rand() % 26];
    for(int i = 0; i < this->word.size(); i++){
        this->correctGuesses += "_";
    }
    std::cout << "You have six wrong guesses. Good luck!" << std::endl;
};

bool Board::guessLetter(char c){
    int checker = 0;
    for(int i = 0; i < this->word.size(); i++){
        if(this->word[i] == c){
            this->correctGuesses[i] = c;
            this->allGuesses += c;
            checker = 1;
        }
    }
    this->numOfIncorrectGuesses++;
    this->incorrectGuesses += c;
    this->allGuesses += c;
    if(checker == 1){
        return true;
    }
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
    std::cout << this->correctGuesses << std::endl;
};

bool Board::checkEnd(){
    if(this->correctGuesses == this->word){
        return true;
    }
    else if(this->numOfIncorrectGuesses == 5){
        return true;
    }
    return false;
};