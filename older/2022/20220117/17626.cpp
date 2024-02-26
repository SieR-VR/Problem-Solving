#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int dp[50001] { 0 };
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        int min_ = INT32_MAX;
        for(int j = 1; j * j <= i; j++) {
            min_ = std::min(min_, dp[i - j * j]);
        }
        dp[i] = min_ + 1;
    }

    std::cout << dp[n];
}