#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  std::string res = "";
  for(char i : s) {
    std::string ch = "";
    if (i == 'A') ch = "a";
    if (i == 'B') ch = "v";
    if (i == 'E') ch = "ye";
    if (i == 'H') ch = "n";
    if (i == 'K') ch = "k";
    if (i == 'P') ch = "r";
    if (i == 'C') ch = "s";
    if (i == 'Y') ch = "u";
    if (i == 'X') ch = "h";
    if (i == 'M') ch = "m";
    if (i == 'O') ch = "o";
    if (i == 'T') ch = "t";

    res += ch;
  }

  std::cout << res;
}