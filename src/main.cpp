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
}