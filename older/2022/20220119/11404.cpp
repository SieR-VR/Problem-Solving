#include <iostream>

int cities[100][100] = {0};

int main()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int t1, t2, t3;
        std::cin >> t1 >> t2 >> t3;
        if (cities[t1 - 1][t2 - 1])
            cities[t1 - 1][t2 - 1] = std::min(cities[t1 - 1][t2 - 1], t3);
        else
            cities[t1 - 1][t2 - 1] = t3;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cities[i][k] && cities[k][j])
                    cities[i][j] = cities[i][j] == 0 ? (cities[i][k] + cities[k][j]) : (std::min(cities[i][j], cities[i][k] + cities[k][j]));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                std::cout << 0 << " ";
            else
                std::cout << cities[i][j] << " ";
        }
        std::cout << "\n";
    }
}