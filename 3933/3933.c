#include <stdio.h>
#include <stdlib.h>

int main() {
  int dp[2 << 15][5];

  for (int i = 0; i < (2 << 15); i++)
    for (int j = 0; j < 5; j++)
      dp[i][j] = 0;

  for (int i = 1; (i * i) < (2 << 15); i++) {
    dp[i * i][1] += 1;

    for (int k = i * i; k < (2 << 15); k++) {
      dp[k][2] += dp[k - i * i][1];
      dp[k][3] += dp[k - i * i][2];
      dp[k][4] += dp[k - i * i][3];
    }
  }

  while (1) {
    int buf = 1;
    scanf("%d", &buf);

    if (!buf) break;

    printf("%d\n", dp[buf][1] + dp[buf][2] + dp[buf][3] + dp[buf][4]);
  }
}
