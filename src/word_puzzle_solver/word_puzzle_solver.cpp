#include "word_puzzle_solver.hpp"
#include <exception>

void WordPuzzleSolver::solve(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::vector<std::string> &words_searched) {
  for (int i = 0; i < words_searched.size(); i++) {
    std::string word_searched = words_searched[i];
    idxWord = i;
    if (!solvePerWord(word_puzzle, word_searched)) {
      std::cout << "No solution for " << word_searched << std::endl;
    }
  }
}
bool WordPuzzleSolver::solvePerWord(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched) {
  return solveHorizontal(word_puzzle, word_searched, false) ||
         solveHorizontal(word_puzzle, word_searched, true) ||
         solveVertical(word_puzzle, word_searched, false) ||
         solveVertical(word_puzzle, word_searched, true) ||
         solveMainDiagonal(word_puzzle, word_searched) ||
         solveCrossDiagonal(word_puzzle, word_searched);
}
bool WordPuzzleSolver::solveHorizontal(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched, bool isReversed) {
  bool found = false;
  int col = word_puzzle[0].size() - word_searched.length() + 2;

  for (int i = 0; i < word_puzzle.size(); i++) {
    for (int j = 0; j < col; j++) {
      found = true;
      for (int k = 0; k < (word_searched.length() - 1); k++) {
        comparisons++;
        if (word_searched[calcIndexWord(isReversed, k,
                                        word_searched.length())] !=
            word_puzzle[i][j + k].first) {
          found = false;
          break;
        }
      }
      // found = checkHorizontal(word_puzzle, word_searched, i, j, false) ||
      //         checkHorizontal(word_puzzle, word_searched, i, j, true);
      if (found) {
        addColor(word_puzzle, i, j, word_searched.length() - 1, 'H');
        break;
      }
    }
    if (found) {
      break;
    }
  }
  return found;
}
bool WordPuzzleSolver::solveVertical(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched, bool isReversed) {
  bool found = false;
  int row = word_puzzle.size() - word_searched.length() + 2;

  for (int i = 0; i < word_puzzle[0].size(); i++) {
    for (int j = 0; j < row; j++) {
      found = true;
      for (int k = 0; k < (word_searched.length() - 1); k++) {
        comparisons++;
        if (word_searched[calcIndexWord(isReversed, k,
                                        word_searched.length())] !=
            word_puzzle[j + k][i].first) {
          found = false;
          break;
        }
      }
      // found = checkVertical(word_puzzle, word_searched, i, j, false) ||
      //         checkVertical(word_puzzle, word_searched, i, j, true);
      if (found) {
        addColor(word_puzzle, j, i, word_searched.length() - 1, 'V');
        break;
      }
    }
    if (found) {
      break;
    }
  }
  return found;
}
bool WordPuzzleSolver::solveMainDiagonal(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched) {
  for (int i = 0; i < word_puzzle.size(); i++) {
    if (checkMainDiagonal(word_puzzle, word_searched, i, 0, false) ||
        checkMainDiagonal(word_puzzle, word_searched, i, 0, true)) {
      return true;
    }
  }
  if (word_puzzle[0].size() > 1) {
    for (int i = 1; i < word_puzzle[0].size(); i++) {
      if (checkMainDiagonal(word_puzzle, word_searched, 0, i, false) ||
          checkMainDiagonal(word_puzzle, word_searched, 0, i, true)) {
        return true;
      }
    }
  }
  return false;
}
bool WordPuzzleSolver::solveCrossDiagonal(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched) {
  for (int i = 0; i < word_puzzle.size(); i++) {
    if (checkCrossDiagonal(word_puzzle, word_searched, i, 0, false) ||
        checkCrossDiagonal(word_puzzle, word_searched, i, 0, true)) {
      return true;
    }
  }
  if (word_puzzle[0].size() > 1) {
    for (int i = 1; i < word_puzzle[0].size(); i++) {
      if (checkCrossDiagonal(word_puzzle, word_searched, word_puzzle.size() - 1,
                             i, false) ||
          checkCrossDiagonal(word_puzzle, word_searched, word_puzzle.size() - 1,
                             i, true)) {
        return true;
      }
    }
  }
  return false;
}
bool WordPuzzleSolver::checkHorizontal(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched, int row, int col, bool isReversed) {
  bool found = true;
  for (int i = 0; i < (word_searched.length() - 1); i++) {
    comparisons++;
    if (word_searched[calcIndexWord(isReversed, i, word_searched.length())] !=
        word_puzzle[row][col + i].first) {
      found = false;
      break;
    }
  }
  return found;
}
bool WordPuzzleSolver::checkVertical(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched, int row, int col, bool isReversed) {
  bool found = true;
  for (int i = 0; i < (word_searched.length() - 1); i++) {
    comparisons++;
    if (word_searched[calcIndexWord(isReversed, i, word_searched.length())] !=
        word_puzzle[row + i][col].first) {
      found = false;
      break;
    }
  }
  return found;
}
bool WordPuzzleSolver::checkMainDiagonal(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched, int rowStart, int colStart, bool isReversed) {
  bool found = false;

  for (int i = 0;
       (i + rowStart + word_searched.length() - 2) < word_puzzle.size() &&
       (i + colStart + word_searched.length() - 2) < word_puzzle[0].size();
       i++) {
    found = true;
    for (int j = 0; j < (word_searched.length() - 1); j++) {
      comparisons++;
      if (word_puzzle[i + j + rowStart][i + j + colStart].first !=
          word_searched[calcIndexWord(isReversed, j, word_searched.length())]) {
        found = false;
        break;
      }
    }
    if (found) {
      addColor(word_puzzle, i + rowStart, i + colStart,
               word_searched.length() - 1, 'M');
      break;
    }
  }
  return found;
}
bool WordPuzzleSolver::checkCrossDiagonal(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::string &word_searched, int rowStart, int colStart, bool isReversed) {
  bool found = false;

  for (int i = 0;
       (int(rowStart - word_searched.length() + 2 - i) >= 0 &&
        colStart + word_searched.length() - 2 + i < word_puzzle[0].size());
       i++) {
    found = true;
    for (int j = 0; j < (word_searched.length() - 1); j++) {
      comparisons++;
      if (word_puzzle[rowStart - i - j][colStart + i + j].first !=
          word_searched[calcIndexWord(isReversed, j, word_searched.length())]) {
        found = false;
        break;
      }
    }
    if (found) {
      addColor(word_puzzle, rowStart - i, colStart + i,
               word_searched.length() - 1, 'C');
      break;
    }
  }
  return found;
}

void WordPuzzleSolver::addColor(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle, const int row,
    const int col, const int len, const char mode) {
  switch (mode) {
  case 'H':
    for (int i = 0; i < len; i++) {
      word_puzzle[row][col + i].second = idxWord;
    }
    break;
  case 'V':
    for (int i = 0; i < len; i++) {
      word_puzzle[row + i][col].second = idxWord;
    }
    break;
  case 'M':
    for (int i = 0; i < len; i++) {
      word_puzzle[row + i][col + i].second = idxWord;
    }
    break;
  case 'C':
    for (int i = 0; i < len; i++) {
      word_puzzle[row - i][col + i].second = idxWord;
    }
    break;
  }
}