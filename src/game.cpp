#include "classes/sudoku.cpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

class Game {
  private:
  void displayHowToPlay(void)
  {
  }

  public:
  void startGame(void)
  {
    bool gameIsRunning = true;

    Sudoku sudokuGame;

    std::cout << "Welcome to the sudoku based in command line interface" << std::endl;

    do {
      sudokuGame.displayBoard();

      // === Line ===
      std::string inputOfUserLine;
      char lineSelected;
      std::cout << "\n"
                << "The line letter : ";
      getline(std::cin, inputOfUserLine);
      std::stringstream(inputOfUserLine) >> lineSelected;
      lineSelected = std::toupper(lineSelected);

      // === Column ===
      unsigned short squareSelected;
      std::string inputOfUserSquare;
      std::cout << "\n"
                << "The square number : ";
      getline(std::cin, inputOfUserSquare);
      std::stringstream(inputOfUserSquare) >> squareSelected;

      // validating if all inputs are right
      if (!sudokuGame.validateInput(lineSelected, squareSelected)) {
        std::cout << "\n"
                  << "Invalid input" << std::endl;
        break;
      }

      // === Value ===
      unsigned short valueOfSquare;
      std::string inputOfUserSquareValue;
      std::cout << "\n"
                << "The value : ";
      getline(std::cin, inputOfUserSquareValue);
      std::stringstream(inputOfUserSquareValue) >> valueOfSquare;

      if (!sudokuGame.selectSquare(lineSelected, squareSelected, valueOfSquare)) {
        std::cout << "Invalid movement" << std::endl;
        gameIsRunning = false;
        break;
      }

      if (sudokuGame.validateIfGameEnd()) {
        std::cout << "Congratulations you win the game" << std::endl;
        break;
      }

      system("clear");
    } while (gameIsRunning);
  }
};
