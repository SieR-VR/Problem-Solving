#include <iostream>

using namespace std;

int table[1025][1025] = {0};
int dp[1025][1025] = {0};
int n, m;

int main()
{
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> table[i][j];
            dp[i][j] = table[i][j];

            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
            if (i > 0 && j > 0)
                dp[i][j] -= dp[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int res = dp[x2][y2];
        if (x1 > 0)
            res -= dp[x1 - 1][y2];
        if (y1 > 0)
            res -= dp[x2][y1 - 1];
        if (x1 > 0 && y1 > 0)
            res += dp[x1 - 1][y1 - 1];

        std::cout << res << "\n";
    }
}