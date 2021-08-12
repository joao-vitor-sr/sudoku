#include "classes/sudoku.cpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

class Game {
  std::string commandList[7] = {
    "exit",
    "edit",
    "add",
    "remove",
    "display board",
    "clear screen",
    "tip"
  };
  Sudoku sudoku;

  private:
  void getTip(void) {
    std::cout << "\n"
              << "*** add square ***" << std::endl;

    std::string inputLine;
    char line;

    std::cout << "Line> ";
    getline(std::cin, inputLine);
    std::stringstream(inputLine) >> line;
    line = std::toupper(line);

    // Square
    std::cout << "\n"
              << "Square> ";
    std::string inputSquare;
    unsigned short square;

    getline(std::cin, inputSquare);
    std::stringstream(inputSquare) >> square;

    if (!sudoku.validateInput(line, square)) {
      std::cout << "Invalid Movement" << std::endl;
    }


    sudoku.getValueFromOriginalBoard(line, square);
    return;
  }

  void addSquare(void)
  {
    std::cout << "\n"
              << "*** add square ***" << std::endl;

    std::string inputLine;
    char line;

    std::cout << "Line> ";
    getline(std::cin, inputLine);
    std::stringstream(inputLine) >> line;
    line = std::toupper(line);

    // Square
    std::cout << "\n"
              << "Square> ";
    std::string inputSquare;
    unsigned short square;

    getline(std::cin, inputSquare);
    std::stringstream(inputSquare) >> square;

    if (!sudoku.validateInput(line, square)) {
      std::cout << "Invalid Movement" << std::endl;
    }

    // value
    std::cout << "\n"
              << "Value> ";
    std::string inputValue;
    unsigned short value;

    getline(std::cin, inputValue);
    std::stringstream(inputValue) >> value;

    if (!sudoku.selectSquare(line, square, value)) {
      std::cout << "\n"
                << "This is square is invalid" << std::endl;
    }

    return;
  }

  void removeSquare()
  {
    std::cout << "\n"
              << "*** remove square ***" << std::endl;

    // Line
    std::string inputLine;
    char line;

    std::cout << "Line> ";
    getline(std::cin, inputLine);
    std::stringstream(inputLine) >> line;
    line = std::toupper(line);

    // Square
    std::cout << "\n"
              << "Square> ";
    std::string inputSquare;
    unsigned short square;

    getline(std::cin, inputSquare);
    std::stringstream(inputSquare) >> square;

    if (sudoku.removeSquare(line, square)) {
      std::cout << "\n"
                << "Invalid movement" << std::endl;
      return;
    }

    return;
  }

  void editSquareAtBoard(void)
  {
    std::cout << "\n"
              << "*** update square ***" << std::endl;

    // Line
    std::string inputLine;
    char line;

    std::cout << "Line> ";
    getline(std::cin, inputLine);
    std::stringstream(inputLine) >> line;
    line = std::toupper(line);

    // Square
    std::cout << "\n"
              << "Square> ";
    std::string inputSquare;
    unsigned short square;

    getline(std::cin, inputSquare);
    std::stringstream(inputSquare) >> square;

    if (sudoku.removeSquare(line, square)) {
      std::cout << "\n"
                << "Invalid movement" << std::endl;
      return;
    }

    // New value
    std::cout << "\n"
              << "Square> ";
    std::string inputNewValue;
    unsigned short value;

    getline(std::cin, inputNewValue);
    std::stringstream(inputNewValue) >> value;

    if (!sudoku.selectSquare(line, square, value)) {
      std::cout << "\n"
                << "Invalid value" << std::endl;
      return;
    }

    return;
  }

  void
  displayCommands(void)
  {
    std::cout << "\n"
              << "*** Commands ***" << std::endl;

    unsigned short alreadyWasFourItems = 0;
    for (unsigned short indexCommands = 0; indexCommands < 7; indexCommands++) {
      std::cout << "  " << indexCommands << ": " << commandList[indexCommands] << "\t";

      if (alreadyWasFourItems == 3) {
        std::cout << "\n";
      }

      alreadyWasFourItems++;
    }
  }

  bool executeAMethodByInput(std::string& input)
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
      addSquare();
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
    case 5:
      std::system("clear");
      return true;
      break;
      break;
    case 6:
      getTip();
      return true;
      break;
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

    sudoku.generateBoard();

    do {
      displayCommands();

      // === Option ===
      std::string optionSelectedInput;
      std::cout << "\n"
                << "What now> ";
      getline(std::cin, optionSelectedInput);

      if (!executeAMethodByInput(optionSelectedInput)) {
        gameIsRunning = false;
        break;
      }

      // validating if the game is ended
      if (sudoku.validateIfGameEnd()) {
        std::cout << "\n"
                  << "Congratulations you win the game" << std::endl;
        gameIsRunning = false;
        break;
      }

    } while (gameIsRunning);
  }
};
