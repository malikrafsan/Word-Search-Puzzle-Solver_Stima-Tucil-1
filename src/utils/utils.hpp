#pragma once
#include <iostream>
#include <string>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */

class Utils {
private:
  const int codeAmount = 12;
  const std::string colorCode[12] = {
      RED,     GREEN,     YELLOW,     BLUE,     MAGENTA,     CYAN,
      BOLDRED, BOLDGREEN, BOLDYELLOW, BOLDBLUE, BOLDMAGENTA, BOLDCYAN,
  };
  std::string inline getColor(int code) {
    return code == -1 ? RESET : colorCode[code % codeAmount];
  }

public:
  void showOutput(std::vector<std::vector<std::pair<char, int>>> &word_puzzle);
  void
  showCodeColor(std::vector<std::vector<std::pair<char, int>>> &word_puzzle);
};