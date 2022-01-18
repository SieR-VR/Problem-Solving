#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int dp[1001] = { 0 };
    dp[0] = 0; dp[1] = 1; dp[2] = 3;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }

    std::cout << dp[n];
}