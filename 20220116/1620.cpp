#include <iostream>
#include <map>
#include <string>

int main() {
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::map<int, std::string> dogam_int;
    std::map<std::string, int> dogam_string;

    for(int i = 1; i <= n; i++) {
        std::string t; std::cin >> t;
        dogam_int.insert({ i, t });
        dogam_string.insert({ t, i });
    }

    for(int i = 0; i < m; i++) {
        std::string t; std::cin >> t;
        if(t.at(0) >= '1' && t.at(0) <= '9')
            std::cout << dogam_int.find(std::stoi(t))->second << "\n";
        else
            std::cout << dogam_string.find(t)->second << "\n";
    }
}