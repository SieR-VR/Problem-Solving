#include <iostream>
#include <string>

int main() {
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    bool zip[21] = { 0 };
    int m; std::cin >> m;

    for(int i = 0; i < m; i++) {
        int t; std::string s;
        std::cin >> s;

        if (s == "add") {
            std::cin >> t;
            zip[t] = true;
        }
        if (s == "remove") {
            std::cin >> t;
            zip[t] = false;
        }
        if (s == "check") {
            std::cin >> t;
            std::cout << zip[t] << "\n";
        }
        if (s == "toggle") {
            std::cin >> t;
            zip[t] = !zip[t];
        }
        if (s == "all") {
            for(int i = 1; i <= 20; i++) 
                zip[i] = true;
        }
        if (s == "empty") {
            for(int i = 1; i <= 20; i++)
                zip[i] = false;
        }
    }
}