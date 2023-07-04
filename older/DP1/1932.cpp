#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if(n == 1) {
        std::cin >> n;
        std::cout << n;

        return 0;
    }

    int DP[501][501] = {0};
    int input[501][501] = {0};

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cin >> input[i][j];
        }
    }

    int max = -1;

    DP[0][0] = input[0][0];

    for(int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) DP[i][0] = DP[i-1][0] + input[i][0];
            else if(j == i) DP[i][i] = DP[i-1][i-1] + input[i][i];
            else DP[i][j] = std::max(DP[i-1][j-1], DP[i-1][j]) + input[i][j];

            max = std::max(max, DP[i][j]);
        }
    }

    std::cout << max;
}