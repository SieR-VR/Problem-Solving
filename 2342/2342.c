#include <stdio.h>

int main() {
    int commands[100000];

    int temp = 1, idx = 0;
    while (temp) {
        scanf("%d", &temp);
        commands[idx++] = temp;
    }

    int len = idx;
    int dp[len][25];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 25; j++)
            dp[i][j] = 0;
    }
}