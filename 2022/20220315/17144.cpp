#include <iostream>

using namespace std;

int map[50][50];
int diffuse_map[50][50];

int main()
{
    int r, c, t;
    cin >> r >> c >> t;

    bool first_purifier = true;
    int p_i, p_j;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (first_purifier && map[i][j] == -1)
            {
                p_i = i;
                p_j = j;
                first_purifier = false;
            }
        }
    }

    for (int u = 0; u < t; u++)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (map[i][j] > 0)
                {
                    int k = map[i][j] / 5;

                    if (i - 1 >= 0 && map[i - 1][j] != -1)
                    {
                        diffuse_map[i - 1][j] += k;
                        map[i][j] -= k;
                    }
                    if (i + 1 < r && map[i + 1][j] != -1)
                    {
                        diffuse_map[i + 1][j] += k;
                        map[i][j] -= k;
                    }
                    if (j - 1 >= 0 && map[i][j - 1] != -1)
                    {
                        diffuse_map[i][j - 1] += k;
                        map[i][j] -= k;
                    }
                    if (j + 1 < c)
                    {
                        diffuse_map[i][j + 1] += k;
                        map[i][j] -= k;
                    }
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                map[i][j] += diffuse_map[i][j];
                diffuse_map[i][j] = 0;
            }
        }

        for (int i = p_i - 2; i >= 0; i--)
        {
            map[i + 1][0] = map[i][0];
            map[i][0] = 0;
        }
        for (int i = p_i + 3; i < r; i++)
        {
            map[i - 1][0] = map[i][0];
            map[i][0] = 0;
        }

        for(int j = 1; j < c; j++) {
            map[0][j-1] = map[0][j];
            map[0][j] = 0;

            map[r-1][j-1] = map[r-1][j];
            map[r-1][j] = 0;
        }

        for (int i = 0; i <= p_i; i++)
        {
            map[i-1][c-1] = map[i][c-1];
            map[i][c-1] = 0;
        }
        for (int i = r-1; i >= p_i + 1; i--)
        {
            map[i+1][c-1] = map[i][c-1];
            map[i][c-1] = 0;
        }

        for(int j = c-2; j >= 1; j--) {
            map[p_i][j+1] = map[p_i][j];
            map[p_i][j] = 0;

            map[p_i+1][j+1] = map[p_i+1][j];
            map[p_i+1][j] = 0;
        }
    }

    int res = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] > 0) res += map[i][j];
        }
    }


    cout << res;
}