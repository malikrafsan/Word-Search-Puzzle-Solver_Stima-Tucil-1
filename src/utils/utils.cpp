#include "utils.hpp"

void Utils::showOutput(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle) {
  for (int i = 0; i < word_puzzle.size(); i++) {
    for (int j = 0; j < word_puzzle[i].size(); j++) {
      std::cout << getColor(word_puzzle[i][j].second) << word_puzzle[i][j].first
                << " ";
    }
    std::cout << std::endl;
  }
  std::cout << RESET;
}

void Utils::showCodeColor(
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle) {
  for (int i = 0; i < word_puzzle.size(); i++) {
    for (int j = 0; j < word_puzzle[i].size(); j++) {
      std::cout << word_puzzle[i][j].second << " ";
    }
    std::cout << std::endl;
  }
}