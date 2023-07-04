#include <iostream>
#include <deque>

struct Cell
{
    int x, y;
    int count;
};


int main() {
    int n, m; std::cin >> n >> m;
    char maze[100][100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> maze[i][j];
            maze[i][j] -= '0';
        }
    }

    std::deque<Cell> dq;
    dq.push_back({ 0, 0, 1 });
    maze[0][0] = 0;

    int res = 0;

    while (dq.size())
    {
        Cell current = dq.front(); dq.pop_front();
        
        if (current.x == n - 1 && current.y == m - 1) {
            res = current.count;
            break;
        }

        if (current.x > 0 && maze[current.x - 1][current.y] != 0) {
            maze[current.x - 1][current.y] = 0;
            dq.push_back({ current.x - 1, current.y, current.count + 1 });
        }
        if (current.x < n - 1 && maze[current.x + 1][current.y] != 0) {
            maze[current.x + 1][current.y] = 0;
            dq.push_back({ current.x + 1, current.y, current.count + 1 });
        }
        if (current.y > 0 && maze[current.x][current.y - 1] != 0) {
            maze[current.x][current.y - 1] = 0;
            dq.push_back({ current.x, current.y - 1, current.count + 1 });
        }
        if (current.y < m - 1 && maze[current.x][current.y + 1] != 0) {
            maze[current.x][current.y + 1] = 0;
            dq.push_back({ current.x, current.y + 1, current.count + 1 });
        }
    }
    
    std::cout << res;
}