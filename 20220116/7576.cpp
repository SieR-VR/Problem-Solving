#include <iostream>
#include <deque>

struct Tomato
{
    int x, y;
    int days;
};

int main()
{
    int m, n;
    std::cin >> m >> n;

    std::deque<Tomato> dq;
    int max_days = 0;

    int box[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> box[j][i];
            if (box[j][i] == 1)
                dq.push_back(Tomato({j, i, 0}));
        }
    }

    while (!dq.empty())
    {
        auto current = dq.front();
        dq.pop_front();

        if (current.x > 0 && box[current.x - 1][current.y] == 0)
        {
            dq.push_back(Tomato({current.x - 1, current.y, current.days + 1}));
            box[current.x - 1][current.y] = true;
            max_days = std::max(max_days, current.days + 1);
        }
        if (current.x < m - 1 && box[current.x + 1][current.y] == 0)
        {
            dq.push_back(Tomato({current.x + 1, current.y, current.days + 1}));
            box[current.x + 1][current.y] = true;
            max_days = std::max(max_days, current.days + 1);
        }
        if (current.y > 0 && box[current.x][current.y - 1] == 0)
        {
            dq.push_back(Tomato({current.x, current.y - 1, current.days + 1}));
            box[current.x][current.y - 1] = true;
            max_days = std::max(max_days, current.days + 1);
        }
        if (current.y < n - 1 && box[current.x][current.y + 1] == 0)
        {
            dq.push_back(Tomato({current.x, current.y + 1, current.days + 1}));
            box[current.x][current.y + 1] = true;
            max_days = std::max(max_days, current.days + 1);
        }
    }

    bool flag = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (box[j][i] == 0)
                flag = false;

    if (flag) {
        std::cout << max_days;
    }
    else {
        std::cout << -1;
    }
}