#include <iostream>
#include <regex>
#include <string>

int main() {
    std::regex test("(100+1+|01)+");

    std::string s;
    std::cin >> s;

    if (std::regex_match(s, test)) std::cout << "SUBMARINE\n";
    else std::cout << "NOISE\n";
}