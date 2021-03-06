#include "Board.hpp"
#include <ctime>
#include <random>
#include <fstream>
#include <sstream>

Board::~Board(){

}

void Board::printWord(){
    std::cout << "The word was " << this->word << std::endl;
}

void Board::startGame(){
    std::string line;
    int random = 0;
    int numOfLines = 0;
    std::ifstream File("wordlist.txt");

        srand(time(0));
        random = rand() % 235886;

    while(std::getline(File, line))
    {
        ++numOfLines;

        if(numOfLines == random)
        {
            this->word = line;
        }

    }
    for(int i = 0; i < this->word.size(); i++){
        this->correctGuesses += "_";
    }
    std::cout << "You have six wrong guesses. Good luck!" << std::endl;
}

bool Board::guessLetter(char c){
    int checker = 0;
    for(int i = 0; i < this->word.size(); i++){
        if(this->word[i] == c){
            this->correctGuesses[i] = c;
            this->allGuesses += c;
            checker = 1;
        }
    }
    if(checker == 1){
        return true;
    }
    this->allGuesses += c;
    this->incorrectGuesses += c;
    this->numOfIncorrectGuesses++;
    return false;
}

bool Board::checkIfGuessed(char c){
    for(int i = 0; i < this->allGuesses.size(); i++){
        if(this->allGuesses[i] == c){
            return true;
        }
    }
    return false;
}

void Board::printBoard(){
    switch(this->numOfIncorrectGuesses){
        case 0:
            std::cout << "  ____   " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |       " << std::endl;
		    std::cout << " |       " << std::endl;
		    std::cout << " |       " << std::endl;
		    std::cout << "_|___    " << std::endl;
		    std::cout << std::endl;
            break;
        case 1:
            std::cout << "  ____   " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |    O  " << std::endl;
		    std::cout << " |       " << std::endl;
		    std::cout << " |       " << std::endl;
		    std::cout << "_|___    " << std::endl;
		    std::cout << std::endl;
            break;
        case 2:
            std::cout << "  ____   " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |    O  " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |       " << std::endl;
		    std::cout << "_|___    " << std::endl;
		    std::cout << std::endl;
            break;
        case 3:
            std::cout << "  ____   " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |    O_ " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |       " << std::endl;
		    std::cout << "_|___    " << std::endl;
		    std::cout << std::endl;
            break;
        case 4:
            std::cout << "  ____   " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |   _O_ " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |       " << std::endl;
		    std::cout << "_|___    " << std::endl;
		    std::cout << std::endl;
            break;
        case 5:
            std::cout << "  ____   " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |   _O_ " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |   /   " << std::endl;
		    std::cout << "_|___    " << std::endl;
		    std::cout << std::endl;
            break;
        case 6:
            std::cout << "  ____   " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |   _O_ " << std::endl;
		    std::cout << " |    |  " << std::endl;
		    std::cout << " |   / \\ " << std::endl;
		    std::cout << "_|___    " << std::endl;
		    std::cout << std::endl;
            break;
    };
    std::cout << this->correctGuesses << "\n";
    std::cout <<"Incorrect guesses:\n";
    std::cout << this->incorrectGuesses << std::endl;
}

bool Board::checkEnd(){
    if(this->correctGuesses == this->word){
        return true;
    }
    else if(this->numOfIncorrectGuesses == 6){
        return true;
    }
    return false;
}