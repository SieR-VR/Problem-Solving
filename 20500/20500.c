#include <stdio.h>
#include <stdlib.h>

const int MOD = 1000000007;

int main() {
    int n; scanf("%d", &n);

    long long dp[1516][3];
    for (int i = 0; i < 1516; i++)
        dp[i][0] = 0ll, dp[i][1] = 0ll, dp[i][2] = 0ll;

    dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
    dp[1][0] = 0, dp[1][1] = 0, dp[1][2] = 1;
    dp[2][0] = 1, dp[2][1] = 1, dp[2][2] = 0;

    for (int i = 3; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    printf("%lld\n", dp[n][0]);
}
