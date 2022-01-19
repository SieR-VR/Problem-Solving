#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        int stickers[n][2] = { 0 };

        for(int i = 0; i < n; i++)
            cin >> stickers[i][0];
        for(int i = 0; i < n; i++)
            cin >> stickers[i][1];

        int dp[n][2] = { 0 };
        dp[0][0] = stickers[0][0];
        dp[0][1] = stickers[0][1];
        dp[1][0] = dp[0][1] + stickers[1][0];
        dp[1][1] = dp[0][0] + stickers[1][1];

        for(int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + stickers[i][0];
            dp[i][1] = max(dp[i-1][0], dp[i-2][0]) + stickers[i][1];
        }

        std::cout << max(dp[n-1][0], dp[n-1][1]) << "\n";
    }
}