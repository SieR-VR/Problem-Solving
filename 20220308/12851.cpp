#include <iostream>
#include <deque>

int n, k;
bool visited[250000] = {0};

std::pair<int, int> bfs()
{
    if (n == k)
        return { 0, 1 };

    std::deque<std::pair<int, int>> q;
    q.push_back({n, 0});

    visited[n] = true;
    bool found = false;
    int found_count = 0;
    int res = 0;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop_front();
        visited[current.first] = true;

        if (current.first == k)
        {
            if (!found) {
                res = current.second;
                found = true;
            }
            
            if (res == current.second)
                found_count++;
        }

        if (found && current.second > res)
            break;

        if (current.first > 0)
        {
            if (!visited[current.first - 1])
            {
                q.push_back({current.first - 1, current.second + 1});
            }
        }
        if (current.first < 100000)
        {
            if (!visited[current.first + 1])
            {
                q.push_back({current.first + 1, current.second + 1});
            }
        }
        if (current.first != 0 && current.first <= 100000)
        {
            if (!visited[current.first * 2])
            {
                q.push_back({current.first * 2, current.second + 1});
            }
        }
    }

    return { res, found_count };
}

int main()
{
    std::cin >> n >> k;
    auto r = bfs();
    std::cout << r.first << "\n" << r.second;
}