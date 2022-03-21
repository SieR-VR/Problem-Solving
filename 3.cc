#include <iostream>
#include <vector>

using namespace std;

int table_tetris[][4] = {
    {15, 0, 0, 0},
    {0, 15, 0, 0},
    {0, 0, 15, 0},
    {0, 0, 0, 15},
    {1, 1, 1, 1},
    {2, 2, 2, 2},
    {4, 4, 4, 4},
    {8, 8, 8, 8}, // ㅁㅁㅁㅁ
    {3, 3, 0, 0},
    {0, 3, 3, 0},
    {0, 0, 3, 3},
    {6, 6, 0, 0},
    {0, 6, 6, 0},
    {0, 0, 6, 6},
    {12, 12, 0, 0},
    {0, 12, 12, 0}, // ㅁㅁ
    {0, 0, 12, 12}, // ㅁㅁ
    {3, 2, 2, 0},
    {0, 3, 2, 2},
    {6, 4, 4, 0},
    {0, 6, 4, 4},
    {12, 8, 8, 0},
    {0, 12, 8, 8},
    {7, 1, 0, 0},
    {0, 7, 1, 0},
    {0, 0, 7, 1},
    {14, 2, 0, 0},
    {0, 14, 2, 0},
    {0, 0, 14, 2},
    {1, 1, 3, 0},
    {0, 1, 1, 3},
    {2, 2, 6, 0},
    {0, 2, 2, 6},
    {4, 4, 12, 0},
    {0, 4, 4, 12},
    {4, 7, 0, 0},
    {0, 4, 7, 0},
    {0, 0, 4, 7},
    {8, 14, 0, 0}, //   ㅁ
    {0, 8, 14, 0}, //   ㅁ
    {0, 0, 8, 14}, // ㅁㅁ
    {2, 2, 3, 0},
    {0, 2, 2, 3},
    {4, 4, 6, 0},
    {0, 4, 4, 6},
    {8, 8, 12, 0},
    {0, 8, 8, 12},
    {7, 4, 0, 0},
    {0, 7, 4, 0},
    {0, 0, 7, 4},
    {14, 8, 0, 0},
    {0, 14, 8, 0},
    {0, 0, 14, 8},
    {3, 1, 1, 0},
    {0, 3, 1, 1},
    {6, 2, 2, 0},
    {0, 6, 2, 2},
    {12, 4, 4, 0},
    {0, 12, 4, 4},
    {1, 7, 0, 0},
    {0, 1, 7, 0},
    {0, 0, 1, 7},
    {2, 14, 0, 0}, // ㅁㅁ
    {0, 2, 14, 0}, //   ㅁ
    {0, 0, 2, 14}, //   ㅁ
    {2, 3, 1, 0},
    {0, 2, 3, 1},
    {4, 6, 2, 0},
    {0, 4, 6, 2},
    {8, 12, 4, 0},
    {0, 8, 12, 4},
    {3, 6, 0, 0},
    {0, 3, 6, 0},
    {0, 0, 3, 6},
    {6, 12, 0, 0}, // ㅁ
    {0, 6, 12, 0}, // ㅁㅁ
    {0, 0, 6, 12}, //   ㅁ
    {1, 3, 2, 0},
    {0, 1, 3, 2},
    {2, 6, 4, 0},
    {0, 2, 6, 4},
    {4, 12, 8, 0},
    {0, 4, 12, 8},
    {6, 3, 0, 0},
    {0, 6, 3, 0},
    {0, 0, 6, 3},
    {12, 6, 0, 0}, //   ㅁ
    {0, 12, 6, 0}, // ㅁㅁ
    {0, 0, 12, 6}, // ㅁ
    {2, 3, 2, 0},
    {0, 2, 3, 2},
    {4, 6, 4, 0},
    {0, 4, 6, 4},
    {8, 12, 8, 0},
    {0, 8, 12, 8},
    {7, 4, 0, 0},
    {0, 7, 4, 0},
    {0, 0, 7, 4},
    {14, 8, 0, 0},
    {0, 14, 8, 0},
    {0, 0, 8, 14},
    {1, 3, 1, 0},
    {0, 1, 3, 1},
    {2, 6, 2, 0},
    {0, 2, 6, 2},
    {4, 12, 4, 0},
    {0, 4, 12, 4},
    {4, 7, 0, 0},
    {0, 4, 7, 0},
    {0, 0, 4, 7},
    {8, 14, 0, 0}, //   ㅁ
    {0, 8, 14, 0}, // ㅁㅁ
    {0, 0, 8, 14}, //  ㅁ
};

bool check(int table_row, int n, int n_1, int n_2, int n_3)
{
    if (n_3 & table_tetris[table_row][0])
        return false;
    if (n_2 & table_tetris[table_row][1])
        return false;
    if (n_1 & table_tetris[table_row][2])
        return false;
    if (n & table_tetris[table_row][3])
        return false;

    else
        return true;
}

int main()
{
    int n;
    cin >> n;

    int table[4][n];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }

    int dp[n][16][16][16][16];
    for (int i = 0; i < n; i++)
    {
        for (int a0 = 0; a0 < 16; a0++)
        {
            for (int a1 = 0; a1 < 16; a1++)
            {
                for (int a2 = 0; a2 < 16; a2++)
                {
                    for (int a3 = 0; a3 < 16; a3++)
                        dp[i][a0][a1][a2][a3] = 0;
                }
            }
        }
    }

    dp[0][15][15][15][15] = table[0][0] * table[1][0] * table[2][0] * table[3][0];
    if (n == 1)
    {
        cout << dp[0][15][15][15][15];
        return 0;
    }

    for (int a0 = 0; a0 < 16; a0++)
        dp[1][a0][15][15][15] = dp[0][15][15][15][15];
    int max_res = 0;

    for (int a0 = 0; a0 < 16; a0++)
    {
        for (int a1 = 0; a1 < 16; a1++)
        {
            for (int table_row = 0; table_row < 113; table_row++)
            {
                if (!check(table_row, a0, a1, 15, 15))
                    continue;

                int num = 1;
                for (int i = 0; i < 4; i++)
                    if ((table_tetris[table_row][3] >> i) & 1)
                        num *= table[i][1];
                for (int i = 0; i < 4; i++)
                    if ((table_tetris[table_row][2] >> i) & 1)
                        num *= table[i][0];

                int new_a0 = a0 + table_tetris[table_row][3];
                int new_a1 = a1 + table_tetris[table_row][2];

                dp[1][new_a0][new_a1][15][15] = max(dp[1][new_a0][new_a1][15][15], dp[1][a0][a1][15][15] + num);
                max_res = max(max_res, dp[1][new_a0][new_a1][15][15]);
            }
        }
    }

    if (n == 2)
    {
        cout << max_res;
        return 0;
    }

    for (int a0 = 0; a0 < 16; a0++)
        for (int a1 = 0; a1 < 16; a1++)
            dp[2][0][a0][a1][15] = dp[1][a0][a1][15][15];

    for (int a0 = 0; a0 < 16; a0++)
    {
        for (int a1 = 0; a1 < 16; a1++)
        {
            for (int a2 = 0; a2 < 16; a2++)
            {
                for (int table_row = 0; table_row < 113; table_row++)
                {
                    if (!check(table_row, a0, a1, a2, 15))
                        continue;

                    int num = 1;
                    for (int i = 0; i < 4; i++)
                        if ((table_tetris[table_row][3] >> i) & 1)
                            num *= table[i][2];
                    for (int i = 0; i < 4; i++)
                        if ((table_tetris[table_row][2] >> i) & 1)
                            num *= table[i][1];
                    for (int i = 0; i < 4; i++)
                        if ((table_tetris[table_row][1] >> i) & 1)
                            num *= table[i][0];

                    int new_a0 = a0 + table_tetris[table_row][3];
                    int new_a1 = a1 + table_tetris[table_row][2];
                    int new_a2 = a2 + table_tetris[table_row][1];

                    dp[2][new_a0][new_a1][new_a2][15] = max(dp[2][new_a0][new_a1][new_a2][15], dp[2][a0][a1][a2][15] + num);
                    max_res = max(max_res, dp[2][new_a0][new_a1][new_a2][15]);
                }
            }
        }
    }

    if (n == 3)
    {
        cout << max_res;
        return 0;
    }

    for (int a0 = 0; a0 < 16; a0++)
        for (int a1 = 0; a1 < 16; a1++)
            for (int a2 = 0; a2 < 16; a2++)
                dp[3][0][a0][a1][a2] = dp[2][a0][a1][a2][15];

    for (int a0 = 0; a0 < 16; a0++)
    {
        for (int a1 = 0; a1 < 16; a1++)
        {
            for (int a2 = 0; a2 < 16; a2++)
            {
                for (int a3 = 0; a3 < 16; a3++)
                {
                    for (int table_row = 0; table_row < 113; table_row++)
                    {
                        if (!check(table_row, a0, a1, a2, a3))
                            continue;

                        int num = 1;
                        for (int i = 0; i < 4; i++)
                            if ((table_tetris[table_row][3] >> i) & 1)
                                num *= table[i][3];
                        for (int i = 0; i < 4; i++)
                            if ((table_tetris[table_row][2] >> i) & 1)
                                num *= table[i][2];
                        for (int i = 0; i < 4; i++)
                            if ((table_tetris[table_row][1] >> i) & 1)
                                num *= table[i][1];
                        for (int i = 0; i < 4; i++)
                            if ((table_tetris[table_row][0] >> i) & 1)
                                num *= table[i][0];

                        int new_a0 = a0 + table_tetris[table_row][3];
                        int new_a1 = a1 + table_tetris[table_row][2];
                        int new_a2 = a2 + table_tetris[table_row][1];
                        int new_a3 = a3 + table_tetris[table_row][0];

                        dp[3][new_a0][new_a1][new_a2][new_a3] = max(dp[3][new_a0][new_a1][new_a2][new_a3], dp[3][a0][a1][a2][a3] + num);
                        max_res = max(max_res, dp[3][new_a0][new_a1][new_a2][new_a3]);
                    }
                }
            }
        }
    }

    if (n == 4)
    {
        cout << max_res;
        return 0;
    }

    for (int i = 4; i < n; i++)
    {
        for (int a0 = 0; a0 < 16; a0++)
            for (int a1 = 0; a1 < 16; a1++)
                for (int a2 = 0; a2 < 16; a2++)
                    for (int a3 = 0; a3 < 16; a3++)
                        dp[i][0][a0][a1][a2] = max(dp[i][0][a0][a1][a2], dp[i - 1][a0][a1][a2][a3]);

        for (int a0 = 0; a0 < 16; a0++)
        {
            for (int a1 = 0; a1 < 16; a1++)
            {
                for (int a2 = 0; a2 < 16; a2++)
                {
                    for (int a3 = 0; a3 < 16; a3++)
                    {
                        for (int table_row = 0; table_row < 113; table_row++)
                        {
                            if (!check(table_row, a0, a1, a2, a3))
                                continue;

                            int num = 1;
                            for (int j = 0; j < 4; j++)
                                if ((table_tetris[table_row][3] >> j) & 1)
                                    num *= table[j][i];
                            for (int j = 0; j < 4; j++)
                                if ((table_tetris[table_row][2] >> j) & 1)
                                    num *= table[j][i - 1];
                            for (int j = 0; j < 4; j++)
                                if ((table_tetris[table_row][1] >> j) & 1)
                                    num *= table[j][i - 2];
                            for (int j = 0; j < 4; j++)
                                if ((table_tetris[table_row][0] >> j) & 1)
                                    num *= table[j][i - 3];

                            int new_a0 = a0 + table_tetris[table_row][3];
                            int new_a1 = a1 + table_tetris[table_row][2];
                            int new_a2 = a2 + table_tetris[table_row][1];
                            int new_a3 = a3 + table_tetris[table_row][0];

                            dp[i][new_a0][new_a1][new_a2][new_a3] = max(dp[i][new_a0][new_a1][new_a2][new_a3], dp[i][a0][a1][a2][a3] + num);
                            max_res = max(max_res, dp[i][new_a0][new_a1][new_a2][new_a3]);
                        }
                    }
                }
            }
        }
    }

    cout << max_res;
}