#include "Board.hpp"

int main(){
    bool checkGuessed = false;
    char guess;
    Board board;
    board.startGame();
    while(!board.checkEnd()){
        board.printBoard();
        std::cout << "Enter the letter (or word) you are guessing: ";
        std::cin >> guess;
        checkGuessed = board.checkIfGuessed(guess);
        while(checkGuessed){
            std::cout << "You already guessed that letter! Guess again: ";
            std::cin >> guess;
            checkGuessed = board.checkIfGuessed(guess); 
        }
        board.guessLetter(guess);
    }
    board.printBoard();
    board.printWord();
    if(board.numOfIncorrectGuesses == 6){
        std::cout << "Game Over!\nYou lose!" << std::endl;
    }
    else{
        std::cout << "Game Over!\nYou Win!" << std::endl;
    }
    return 0;
}