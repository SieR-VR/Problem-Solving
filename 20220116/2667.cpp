#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

struct Cell
{
    int x, y;
};

int n;
char maze[25][25];

int bfs(int x, int y)
{
    std::deque<Cell> dq;
    dq.push_back({x, y});
    maze[x][y] = 0;
    int homes = 0;

    while (!dq.empty())
    {
        Cell c = dq.front(); dq.pop_front();
        homes++;

        if (c.x > 0 && maze[c.x - 1][c.y] != 0) {
            maze[c.x - 1][c.y] = 0;
            dq.push_back({ c.x - 1, c.y });
        }
        if (c.x < n - 1 && maze[c.x + 1][c.y] != 0) {
            maze[c.x + 1][c.y] = 0;
            dq.push_back({ c.x + 1, c.y });
        }
        if (c.y > 0 && maze[c.x][c.y - 1] != 0) {
            maze[c.x][c.y - 1] = 0;
            dq.push_back({ c.x, c.y - 1 });
        }
        if (c.y < n - 1 && maze[c.x][c.y + 1] != 0) {
            maze[c.x][c.y + 1] = 0;
            dq.push_back({ c.x, c.y + 1 });
        }
    }

    return homes;
}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> maze[i][j];
            maze[i][j] -= '0';
        }
    }

    int cnt = 0;
    std::vector<int> homes;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j])
            {
                homes.push_back(bfs(i, j));
                cnt++;
            }
        }
    }

    std::sort(homes.begin(), homes.end());

    std::cout << cnt << "\n";
    for(int i : homes) {
        std::cout << i << "\n";
    }
}