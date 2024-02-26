#include <iostream>
#include <deque>

struct Tomato
{
    int x, y, z;
    int days;
};

int main()
{
    int m, n, h;
    std::cin >> m >> n >> h;

    std::deque<Tomato> dq;
    int max_days = 0;

    int box[100][100][100];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++) {
                std::cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                    dq.push_back({k, j, i, 0});
            }
        }
    }

    while (!dq.empty())
    {
        auto c = dq.front();
        dq.pop_front();

        if (c.x > 0 && box[c.z][c.y][c.x - 1] == 0)
        {
            dq.push_back({c.x - 1, c.y, c.z, c.days + 1});
            box[c.z][c.y][c.x - 1] = true;
            max_days = std::max(max_days, c.days + 1);
        }
        if (c.x < m - 1 && box[c.z][c.y][c.x + 1] == 0)
        {
            dq.push_back({c.x + 1, c.y, c.z, c.days + 1});
            box[c.z][c.y][c.x + 1] = true;
            max_days = std::max(max_days, c.days + 1);
        }
        if (c.y > 0 && box[c.z][c.y - 1][c.x] == 0)
        {
            dq.push_back({c.x, c.y - 1, c.z, c.days + 1});
            box[c.z][c.y - 1][c.x] = true;
            max_days = std::max(max_days, c.days + 1);
        }
        if (c.y < n - 1 && box[c.z][c.y + 1][c.x] == 0)
        {
            dq.push_back({c.x, c.y + 1, c.z, c.days + 1});
            box[c.z][c.y + 1][c.x] = true;
            max_days = std::max(max_days, c.days + 1);
        }
        if (c.z > 0 && box[c.z - 1][c.y][c.x] == 0)
        {
            dq.push_back({c.x, c.y, c.z - 1, c.days + 1});
            box[c.z - 1][c.y][c.x] = true;
            max_days = std::max(max_days, c.days + 1);
        }
        if (c.z < h - 1 && box[c.z + 1][c.y][c.x] == 0)
        {
            dq.push_back({c.x, c.y, c.z + 1, c.days + 1});
            box[c.z + 1][c.y][c.x] = true;
            max_days = std::max(max_days, c.days + 1);
        }
    }

    bool flag = true;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
                if (box[i][j][k] == 0)
                    flag = false;

    if (flag) {
        std::cout << max_days;
    }
    else {
        std::cout << -1;
    }
}