#include <iostream>
#include <string>

bool pd(const std::string &str) {
    for(int i = 0; i < str.length() / 2; i++) {
        if(str.at(i) != str.at(str.length() - 1 - i)) return false;
    }
    return true;
}

int main() {
    for(;;) {
        std::string s;
        std::cin >> s;

        if (s.at(0) == '0') break;

        if (pd(s)) std::cout << "yes\n";
        else std::cout << "no\n";
    }
}