#include <iostream>

class Sudoku {
  private:
  char getCharacterOfLine(unsigned short indexLine)
  {
    char characterLines[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

    return characterLines[indexLine];
  }

  public:
  unsigned short board[9][9] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
    { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
    { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
    { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
    { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
    { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
    { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
    { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
    { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

  void displayBoard(void)
  {
    std::cout << "  0 1 2 3 4 5 6 7 8" << std::endl;
    for (unsigned short indexLine = 0; indexLine < 9; indexLine++) {
      std::cout << "  - - - - - - - - -" << std::endl;
      std::cout << getCharacterOfLine(indexLine) << " ";
      for (unsigned short indexSqure = 0; indexSqure < 9; indexSqure++) {
        if (board[indexLine][indexSqure] == 0) {
          std::cout << "| ";
          continue;
        }
        std::cout << "|" << board[indexLine][indexSqure];
      }
      std::cout << "\n";
    }
  }
};
