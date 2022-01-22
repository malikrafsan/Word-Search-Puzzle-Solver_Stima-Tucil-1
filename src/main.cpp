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
  fileReader.readFile(std::string("./tests/") + argv[1], word_puzzle,
                      words_searched);

  std::chrono::time_point<std::chrono::system_clock> start, end;

  start = std::chrono::system_clock::now();

  WordPuzzleSolver wps = WordPuzzleSolver();
  wps.solve(word_puzzle, words_searched);

  Utils utils = Utils();
  utils.showOutput(word_puzzle);
  // utils.showCodeColor(word_puzzle);

  std::cout << "COMPARISONS:" << wps.getComparisons() << std::endl;

  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "finished computation at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() * 1000000
            << "microseconds\n";

  return 0;
}
