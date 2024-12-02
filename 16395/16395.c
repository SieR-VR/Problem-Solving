#include <stdio.h>
#include <stdlib.h>

int main() {
    int dp[31][31];

    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 31; j++)
            dp[i][j] = 0;

    dp[0][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i < 31; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    int n, k; scanf("%d %d", &n, &k);
    printf("%d\n", dp[n][k]);
}
