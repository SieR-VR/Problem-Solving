#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> stable;
std::vector<int> current;
std::vector<int> pow_10;
int n, m;
int res = INT32_MAX, current_digit = 1;

std::pair<int, int> get() {
    int res = 0;
    for(int i = 0; i < current.size(); i++)
        res += current[i] * pow_10[current.size() - i - 1];

    return { res, current.size() };
}

void bfs(int level) {
    if (level > 0) { 
        auto res_count = get();
        res = std::min(res, res_count.second + std::abs(res_count.first - n));
    }
    if (level == 6) return;
    for(int i = 0; i < stable.size(); i++) {
        current.push_back(stable[i]);
        bfs(level + 1);
        current.pop_back();
    }
}

int main() {
    std::cin >> n >> m;

    if (m == 10) {
        std::cout << std::abs(n - 100);
        return 0;
    }

    int broken[10] = { 0 };

    for(int i = 0; i < m; i++) {
        int t; std::cin >> t;
        broken[t] = 1;
    }

    pow_10.push_back(1);
    for(int i = 0; i < 10; i++) {
        if(!broken[i]) stable.push_back(i);
        if(i > 0) pow_10.push_back(pow_10[i-1] * 10);
    }

    bfs(0);
    if (n == 100) res = 0;
    if (n == 101 || n == 99) res = 1;
    if (n == 102 || n == 98) res = 2;
    res = std::min(res, std::abs(n - 100));

    std::cout << res;
}