#include <iostream>
#include <queue>

using namespace std;

bool map[1000][1000] = {0};
bool visited[2][1000][1000] = {0};
int n, m;

bool check(int i, int j)
{
    return (i >= 0) && (i < n) && (j >= 0) && (j < m);
}

bool check_map(int i, int j)
{
    return (i >= 0) && (i < n) && (j >= 0) && (j < m) && (!map[i][j]);
}

struct State
{
    int i, j;
    int dist;
    bool crashed;
};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c; cin >> c;
            map[i][j] = c - '0';
        }
    }

    int res = -1;
    queue<State> q;
    q.push({0, 0, 1, false});
    visited[0][0][0] = true;
    visited[1][0][0] = true;

    while (!q.empty())
    {
        State c = q.front();
        q.pop();

        if (c.i == n - 1 && c.j == m - 1)
        {
            res = c.dist;
            break;
        }

        if (!c.crashed)
        {
            if (check_map(c.i + 1, c.j) && !visited[0][c.i + 1][c.j])
            {
                q.push({c.i + 1, c.j, c.dist + 1, false});
                visited[0][c.i + 1][c.j] = true;
                visited[1][c.i + 1][c.j] = true;
            }
            else if (check(c.i + 1, c.j) && !visited[0][c.i + 1][c.j] && !visited[1][c.i + 1][c.j])
            {
                q.push({c.i + 1, c.j, c.dist + 1, true});
                visited[1][c.i + 1][c.j] = true;
            }

            if (check_map(c.i - 1, c.j) && !visited[0][c.i - 1][c.j])
            {
                q.push({c.i - 1, c.j, c.dist + 1, false});
                visited[0][c.i - 1][c.j] = true;
                visited[1][c.i - 1][c.j] = true;
            }
            else if (check(c.i - 1, c.j) && !visited[0][c.i - 1][c.j] && !visited[1][c.i - 1][c.j])
            {
                q.push({c.i - 1, c.j, c.dist + 1, true});
                visited[1][c.i - 1][c.j] = true;
            }

            if (check_map(c.i, c.j + 1) && !visited[0][c.i][c.j + 1])
            {
                q.push({c.i, c.j + 1, c.dist + 1, false});
                visited[0][c.i][c.j + 1] = true;
                visited[1][c.i][c.j + 1] = true;
            }
            else if (check(c.i, c.j + 1) && !visited[0][c.i][c.j + 1] && !visited[1][c.i][c.j + 1])
            {
                q.push({c.i, c.j + 1, c.dist + 1, true});
                visited[1][c.i][c.j + 1] = true;
            }

            if (check_map(c.i, c.j - 1) && !visited[0][c.i][c.j - 1])
            {
                q.push({c.i, c.j - 1, c.dist + 1, false});
                visited[0][c.i][c.j - 1] = true;
                visited[1][c.i][c.j - 1] = true;
            }
            else if (check(c.i, c.j - 1) && !visited[0][c.i][c.j - 1] && !visited[1][c.i][c.j - 1])
            {
                q.push({c.i, c.j - 1, c.dist + 1, true});
                visited[1][c.i][c.j - 1] = true;
            }
        }
        else
        {
            if (check_map(c.i + 1, c.j) && !visited[0][c.i + 1][c.j] && !visited[1][c.i + 1][c.j])
            {
                q.push({c.i + 1, c.j, c.dist + 1, true});
                visited[1][c.i + 1][c.j] = true;
            }

            if (check_map(c.i - 1, c.j) && !visited[0][c.i - 1][c.j] && !visited[1][c.i - 1][c.j])
            {
                q.push({c.i - 1, c.j, c.dist + 1, true});
                visited[1][c.i - 1][c.j] = true;
            }

            if (check_map(c.i, c.j + 1) && !visited[0][c.i][c.j + 1] && !visited[1][c.i][c.j + 1])
            {
                q.push({c.i, c.j + 1, c.dist + 1, true});
                visited[1][c.i][c.j + 1] = true;
            }

            if (check_map(c.i, c.j - 1) && !visited[0][c.i][c.j - 1] && !visited[1][c.i][c.j - 1])
            {
                q.push({c.i, c.j - 1, c.dist + 1, true});
                visited[1][c.i][c.j - 1] = true;
            }
        }
    }

    std::cout << res;
}