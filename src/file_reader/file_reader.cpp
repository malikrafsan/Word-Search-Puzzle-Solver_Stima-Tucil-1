#include "file_reader.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool FileReader::readFile(
    std::string fileName,
    std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
    std::vector<std::string> &words_searched) {
  bool isMode1 = true;
  std::string line;

  fin.open(fileName);
  if (!fin.is_open()) {
    std::cout << "File not found" << std::endl;
    return false;
  }

  while (fin) {
    getline(fin, line);

    if (line.length() > 1) {
      if (isMode1) {
        std::vector<std::pair<char, int>> line_vector;
        for (int i = 0; i < line.length(); i++) {
          if (line[i] != ' ') {
            line_vector.push_back({line[i], -1});
          }
        }
        word_puzzle.push_back(line_vector);
      } else {
        words_searched.push_back(line);
      }
    } else {
      if (isMode1) {
        isMode1 = false;
      } else {
        break;
      }
    }
  }
  fin.close();
  return true;
}
