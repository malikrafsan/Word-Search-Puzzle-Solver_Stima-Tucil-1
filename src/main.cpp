#include "file_reader/file_reader.hpp"
#include "utils/utils.hpp"
#include "word_puzzle_solver/word_puzzle_solver.hpp"
#include <array>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char **argv) {
  std::vector<std::vector<std::pair<char, int>>> word_puzzle;
  std::vector<std::string> words_searched;

  if (argc < 2) {
    std::cout << "Please add arguments for file name" << std::endl;
    return 0;
  }

  FileReader fileReader = FileReader();
  if (!fileReader.readFile(std::string("./test/") + argv[1], word_puzzle,
                           words_searched)) {
    return 0;
  }

  auto start = std::chrono::high_resolution_clock::now();
  WordPuzzleSolver wps = WordPuzzleSolver();
  wps.solve(word_puzzle, words_searched);
  auto stop = std::chrono::high_resolution_clock::now();

  Utils utils = Utils();
  utils.showOutput(word_puzzle);
  std::cout << "COMPARISONS: " << wps.getComparisons() << std::endl;

  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  std::cout << "Time taken by function: " << duration.count() << " nanoseconds"
            << std::endl;

  return 0;
}
