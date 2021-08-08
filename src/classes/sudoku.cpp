#include <iostream>

class Sudoku {
  char linesCharacters[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
  unsigned short board[9][9] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
    { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
    { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
    { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
    { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
    { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
    { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
    { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
    { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

  private:
  unsigned short returnIndexOfCharacter(char character)
  {
    for (unsigned short index = 0; index < 9; index++) {
      if (character == linesCharacters[index]) {
        return index;
      }
    }

    return 0;
  }

  bool validateIfSquareIsPossible(unsigned short indexLine, unsigned short squareIndex, unsigned short number)
  {
    // validating line
    for (unsigned short index = 0; index < 9; index++) {
      if (board[indexLine][index] == number) {
        return false;
      }

      if (board[index][squareIndex] == number) {
        return false;
      }
    }

    unsigned short lineIndexZero = (indexLine / 3) * 3;
    unsigned short squareIndexZero = (squareIndex / 3) * 3;

    for (unsigned short indexLine = 0; indexLine < 3; indexLine++) {
      for (unsigned short indexColumn = 0; indexColumn < 3; indexColumn++) {
        if (board[lineIndexZero + indexLine][squareIndexZero + indexColumn] == number) {
          return false;
        }
      }
    }

    return true;
  }

  public:
  bool removeSquare(char lineCharacrter, unsigned short squareIndex)
  {
    unsigned short lineIndex = returnIndexOfCharacter(lineCharacrter);

    // validating if the input is valid
    if (squareIndex >= 9) {
      return true;
    }

    // removing the squareIndex
    board[lineIndex][squareIndex] = 0;

    return false;
  }

  bool validateIfGameEnd(void)
  {

    for (unsigned short indexLine = 0; indexLine < 9; indexLine++) {
      for (unsigned short indexColumn = 0; indexColumn < 9; indexColumn++) {
        if (board[indexLine][indexColumn] == 0) {
          return false;
        }
      }
    }

    return true;
  }

  bool validateInput(char lineCharacrter, unsigned short squareIndex)
  {
    if (squareIndex < 9) {
      return true;
    }

    for (unsigned short index = 0; index < 9; index++) {
      if (linesCharacters[index] == lineCharacrter) {
        return true;
        break;
      }
    }

    return false;
  }

  bool selectSquare(char lineCharacrter, unsigned short squareIndex, unsigned short value)
  {

    unsigned short lineIndex = returnIndexOfCharacter(lineCharacrter);
    if (!validateIfSquareIsPossible(lineIndex, squareIndex, value)) {
      return false;
    }

    board[lineIndex][squareIndex] = value;

    return true;
  }

  void displayBoard(void)
  {
    std::cout << "    0 1 2  3 4 5  6 7 8\n"
              << std::endl;

    unsigned short blockSquare = 0;
    unsigned short lineBlock = 0;

    for (unsigned short indexLine = 0; indexLine < 9; indexLine++) {

      std::cout << linesCharacters[indexLine] << "  ";

      for (unsigned short indexSqure = 0; indexSqure < 9; indexSqure++) {
        if (blockSquare == 2) {
          std::cout << " " << board[indexLine][indexSqure] << " ";
          blockSquare = 0;
          continue;
        }

        blockSquare = blockSquare + 1;
        std::cout << " " << board[indexLine][indexSqure];
      }

      if (lineBlock == 2) {
        std::cout << "\n\n";
        lineBlock = 0;
        continue;
      }

      lineBlock = lineBlock + 1;
      std::cout << "\n";
    }
  }
};
