#include <iostream>

int n, m, b;
int blocks[500][500];

int main()
{
    std::cin >> n >> m >> b;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> blocks[i][j];
        }
    }

    int min_time = INT32_MAX;
    int max_height = 0;

    for (int i = 0; i <= 256; i++)
    {
        int time = 0, block = 0;

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (blocks[y][x] > i) {
                    block += (blocks[y][x] - i);
                    time += (blocks[y][x] - i) * 2;
                }
                else if (blocks[y][x] < i) {
                    block -= (i - blocks[y][x]);
                    time += (i - blocks[y][x]);
                }
            }
        }

        if ((-block) > b) {
            break;
        }

        if (time <= min_time) {
            min_time = time;
            max_height = i;
        }
    }

    std::cout << min_time << " " << max_height;
}