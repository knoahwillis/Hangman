#include <iostream>
#include <string>
#include "Board.hpp"



int main(){
    char guess;
    Board board;
    board.startGame();
    board.printBoard();
    while(!board.checkEnd()){
        std::cout << "Enter the letter you are guessing: ";
        std::cin >> guess;
        board.guessLetter(guess);
        board.printBoard();
    }
    board.printBoard();
}