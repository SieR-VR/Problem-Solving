#include <iostream>
#include <string>
#include <regex>

const std::regex test("(100+1+|01)+");
int N;

int main() {
    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;

        bool res = std::regex_match(s, test);
        if (res) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}