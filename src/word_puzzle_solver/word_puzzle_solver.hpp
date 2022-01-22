#include <iostream>
#include <string>
#include <vector>

class WordPuzzleSolver {
private:
  int idxWord;
  long long comparisons = 0;

  bool solvePerWord(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                    std::string &word_searched);
  int inline calcIndexWord(bool isReversed, int idx, int word_length) {
    return isReversed ? word_length - idx - 2 : idx;
  }
  bool
  solveHorizontal(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                  std::string &word_searched, bool isReversed);
  bool
  solveVertical(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                std::string &word_searched, bool isReversed);
  bool
  solveMainDiagonal(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                    std::string &word_searched);
  bool solveCrossDiagonal(
      std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
      std::string &word_searched);
  bool
  checkHorizontal(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                  std::string &word_searched, int row, int col,
                  bool isReversed);
  bool
  checkVertical(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                std::string &word_searched, int row, int col, bool isReversed);
  bool
  checkMainDiagonal(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                    std::string &word_searched, int rowStart, int colStart,
                    bool isReversed);
  bool checkCrossDiagonal(
      std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
      std::string &word_searched, int rowStart, int colStart, bool isReversed);
  void addColor(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                const int row, const int col, const int len, const char mode);

public:
  void solve(std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
             std::vector<std::string> &words_searched);
  long long inline getComparisons() { return comparisons; }
};