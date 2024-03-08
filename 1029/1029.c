#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) { return ((x < y) ? (x) : (y)); }
int max(int x, int y) { return ((x > y) ? (x) : (y)); }

int count_bits(int n) {
    int result = 0;
    for (size_t i = 0; i < sizeof(int) * 8; i++)
        if (n & (1 << i))
            result++;

    return result;
}

int main() {
    int N; scanf("%d", &N);
    int weight_matrix[N][N];
    
    for (int i = 0; i != N * N;) {
        char temp; scanf("%c", &temp);
        if (temp == '\n' || temp == '\r')
            continue;

        weight_matrix[i / N][i % N] = (int)temp - '0';
        i++;
    }

    int dp[1 << N][N];
    for (int i = 0; i < (1 << (N)); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 255;
        }
    }

    int count_max = -1;
    dp[1 << 0][0] = 0;
    for (int i = 1; i < (1 << (N - 1)); i++) {
        int curr_bitmask = i << 1 | 1;

        for (int j = 1; j < N; j++) {
            if (!((1 << j) & curr_bitmask))
                continue;

            for (int k = 0; k < N; k++)
                if (dp[curr_bitmask - (1 << j)][k] != 255) {
                    if (weight_matrix[k][j] < dp[curr_bitmask - (1 << j)][k])
                        continue;

                    dp[curr_bitmask][j] = min(dp[curr_bitmask][j], weight_matrix[k][j]);
                    count_max = max(count_max, count_bits(curr_bitmask));
                }
        }
    }

    printf("%d\n", count_max);
}