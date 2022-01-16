#include <iostream>
#include <set>
#include <string>

int main() {
    int n, m; std::cin >> n >> m;

    std::set<std::string> s;
    for(int i = 0; i < n; i++) {
        std::string str; std::cin >> str;
        s.insert(str);
    }

    std::set<std::string> res;
    int count = 0;

    for(int i = 0; i < m; i++) {
        std::string str; std::cin >> str;
        if (s.find(str) != s.end()) {
            res.insert(str);
            count++;
        }
    }

    std::cout << count << "\n";
    for(auto name : res) {
        std::cout << name << "\n";
    }
}