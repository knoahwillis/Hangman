#include <iostream>
#include <string>
#include "Board.hpp"



int main(){
    char guess;
    Board board;
    board.startGame();
    while(!board.checkEnd()){
        board.printBoard();
        std::cout << "Enter the letter you are guessing: ";
        std::cin >> guess;
        board.guessLetter(guess);
    }
    board.printBoard();
    if(board.numOfIncorrectGuesses == 6){
        std::cout << "Game Over!\nYou lose!" << std::endl;
    }
    else{
        std::cout << "Game Over!\nYou Win!" << std::endl;
    }
}