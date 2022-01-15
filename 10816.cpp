#include <iostream>
#include <set>

int n, m;
int cards[20000001] = { 0 };

int main() {
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int t; std::cin >> t;
        cards[t + 10000000]++;
    }

    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int t; std::cin >> t;
        std::cout << cards[t + 10000000] << " ";
    }
}