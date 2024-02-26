#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

struct Cell
{
    int x, y;
};

int n;
int maze[2][100][100];

void bfs(int x, int y, int maze_num)
{
    std::deque<Cell> dq;
    dq.push_back({x, y});
    int color = maze[maze_num][x][y];
    maze[maze_num][x][y] = 0;

    while (!dq.empty())
    {
        Cell c = dq.front(); dq.pop_front();

        if (c.x > 0 && maze[maze_num][c.x - 1][c.y] == color) {
            maze[maze_num][c.x - 1][c.y] = 0;
            dq.push_back({ c.x - 1, c.y });
        }
        if (c.x < n - 1 && maze[maze_num][c.x + 1][c.y] == color) {
            maze[maze_num][c.x + 1][c.y] = 0;
            dq.push_back({ c.x + 1, c.y });
        }
        if (c.y > 0 && maze[maze_num][c.x][c.y - 1] == color) {
            maze[maze_num][c.x][c.y - 1] = 0;
            dq.push_back({ c.x, c.y - 1 });
        }
        if (c.y < n - 1 && maze[maze_num][c.x][c.y + 1] == color) {
            maze[maze_num][c.x][c.y + 1] = 0;
            dq.push_back({ c.x, c.y + 1 });
        }
    }
}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c; std::cin >> c;
            if (c == 'R') {
                maze[0][i][j] = 1;
                maze[1][i][j] = 1;
            }
            else if (c == 'G') {
                maze[0][i][j] = 2;
                maze[1][i][j] = 1;
            }
            else {
                maze[0][i][j] = 3;
                maze[1][i][j] = 2;
            }
        }
    }

    int count_stable = 0;
    int count_blind = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (maze[0][i][j]) {
                bfs(i, j, 0);
                count_stable++;
            }
            if (maze[1][i][j]) {
                bfs(i, j, 1);
                count_blind++;
            }
        }
    }

    std::cout << count_stable << " " << count_blind;
}