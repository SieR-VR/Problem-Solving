#include <stdio.h>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

const int LIMIT = 1000000007;

int main() {
  int commands[100000];

  int temp = 1, idx = 0;
  while (temp) {
    scanf("%d", &temp);
    commands[idx++] = temp;
  }

  int len = idx;
  int dp[len][5][5];

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 5; k++)
        dp[i][j][k] = LIMIT;
  }

  int first = commands[0];
  dp[0][first][0] = 2;
  dp[0][0][first] = 2;

  int table[5][5] = {
      {0, 2, 2, 2, 2}, {0, 1, 3, 4, 3}, {0, 3, 1, 3, 4},
      {0, 4, 3, 1, 3}, {0, 3, 4, 3, 1},
  };

  for (int i = 1; i < len; i++) {
    int curr_command = commands[i];

    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (dp[i - 1][j][k] == LIMIT)
          continue;

        dp[i][j][curr_command] = MIN(dp[i][j][curr_command],
                                     dp[i - 1][j][k] + table[k][curr_command]);
        dp[i][curr_command][k] = MIN(dp[i][curr_command][k],
                                     dp[i - 1][j][k] + table[j][curr_command]);
      }
    }
  }

  int result_min = LIMIT;
  for (int j = 0; j < 5; j++)
    for (int k = 0; k < 5; k++) {
      result_min = MIN(result_min, dp[len - 1][j][k]);
    }

  printf("%d\n", result_min);
}
