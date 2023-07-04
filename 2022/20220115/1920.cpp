#include <iostream>
#include <set>

int main() {
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::set<int> s;
    int n; std::cin >> n;
    for(int i = 0; i < n; i++) {
        int t; std::cin >> t;
        s.insert(t);
    }

    int m; std::cin >> m;
    for(int i = 0; i < m; i++) {
        int t; std::cin >> t;
        if (s.find(t) == s.end()) 
            std::cout << "0\n";
        else    
            std::cout << "1\n";
    }
}