#include <iostream>
#include <deque>

int n, k;
bool visited[250000] = {0};

int bfs()
{
    if (n == k)
        return 0;

    std::deque<std::pair<int, int>> q;
    q.push_back({n, 0});

    visited[n] = true;
    int res = 0;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop_front();

        if (current.first == k)
        {
            res = current.second;
            break;
        }

        if (current.first > 0)
        {
            if (!visited[current.first - 1])
            {
                visited[current.first - 1] = true;
                q.push_back({current.first - 1, current.second + 1});
            }
        }
        if (current.first < 100000)
        {
            if (!visited[current.first + 1])
            {
                visited[current.first + 1] = true;
                q.push_back({current.first + 1, current.second + 1});
            }
        }
        if (current.first != 0 && current.first <= 100000)
        {
            if (!visited[current.first * 2])
            {
                visited[current.first * 2] = true;
                q.push_back({current.first * 2, current.second + 1});
            }
        }
    }

    return res;
}

int main()
{
    std::cin >> n >> k;
    std::cout << bfs();
}