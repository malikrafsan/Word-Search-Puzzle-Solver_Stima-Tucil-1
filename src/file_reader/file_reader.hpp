#pragma once
#include <fstream>
#include <string>
#include <vector>

class FileReader {
private:
  std::ifstream fin;

public:
  bool readFile(std::string fileName,
                std::vector<std::vector<std::pair<char, int>>> &word_puzzle,
                std::vector<std::string> &words_searched);
};