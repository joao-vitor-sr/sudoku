#include "classes/sudoku.cpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

class Game {
  std::string commandList[5] = {
    "exit",
    "edit",
    "add",
    "remove",
    "display board"
  };
  Sudoku sudoku;

  private:
  void
  displayCommands(void)
  {
    std::cout << "\n"
              << "*** Commands ***" << std::endl;

    unsigned short alreadyWasFourItems = 0;
    for (unsigned short indexCommands = 0; indexCommands < 5; indexCommands++) {
      std::cout << "  " << indexCommands << ": " << commandList[indexCommands] << "\t";

      if (alreadyWasFourItems == 3) {
        std::cout << "\n";
      }

      alreadyWasFourItems++;
    }
  }

  bool executeAMethodByINput(std::string& input)
  {
    unsigned short optionSelected;
    std::stringstream(input) >> optionSelected;

    switch (optionSelected) {
    case 0:
      return false;
      break;
    case 1:
      editSquareAtBoard();
      return true;
      break;
    case 2:
      return true;
      break;
    case 3:
      removeSquare();
      return true;
      break;
    case 4:
      std::cout << std::endl;
      sudoku.displayBoard();
      return true;
      break;
    default:
      return false;
      break;
    }
  }

  public:
  void startGame(void)
  {
    bool gameIsRunning = true;

    do {
      displayCommands();

      // === Option ===
      std::string optionSelectedInput;
      std::cout << "\n"
                << "What now> ";
      getline(std::cin, optionSelectedInput);

      if (!executeAMethodByINput(optionSelectedInput)) {
        gameIsRunning = false;
        break;
      }

    } while (gameIsRunning);
  }
};
