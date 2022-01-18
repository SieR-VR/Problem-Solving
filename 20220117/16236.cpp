#include <iostream>
#include <deque>
#include <set>

using namespace std;

int space[20][20];
int n;

struct State
{
    int size, ate;
    int x, y;
    int seconds;
};

struct State_find
{
    int x, y;
    int dist;
};

struct Compare {
    bool operator()(const State_find &lhs, const State_find &rhs) {
        if (lhs.dist != rhs.dist) return lhs.dist < rhs.dist;
        if (lhs.x != rhs.x) return lhs.x < rhs.x;
        return lhs.y < rhs.y; 
    }
};

bool check(int x, int y)
{
    return (x >= 0) && (x < n) && (y >= 0) && (y < n);
}

State_find bfs(int x, int y, int size)
{
    bool visited[20][20] = {false};

    set<State_find, Compare> st;
    deque<State_find> dq;
    dq.push_back({x, y, 0});

    while (dq.size())
    {
        auto sf = dq.front();
        dq.pop_front();

        if (space[sf.x][sf.y] < size && space[sf.x][sf.y] != 0) {
            st.insert(sf);
        }

        if (check(sf.x + 1, sf.y) && !visited[sf.x + 1][sf.y] && space[sf.x + 1][sf.y] <= size)
        {
            visited[sf.x + 1][sf.y] = true;
            dq.push_back({ sf.x + 1, sf.y, sf.dist + 1 });
        }
        if (check(sf.x, sf.y - 1) && !visited[sf.x][sf.y - 1] && space[sf.x][sf.y - 1] <= size)
        {
            visited[sf.x][sf.y - 1] = true;
            dq.push_back({ sf.x, sf.y - 1, sf.dist + 1 });
        }
        if (check(sf.x, sf.y + 1) && !visited[sf.x][sf.y + 1] && space[sf.x][sf.y + 1] <= size)
        {
            visited[sf.x][sf.y + 1] = true;
            dq.push_back({ sf.x, sf.y + 1, sf.dist + 1 });
        }
        if (check(sf.x - 1, sf.y) && !visited[sf.x - 1][sf.y] && space[sf.x - 1][sf.y] <= size)
        {
            visited[sf.x - 1][sf.y] = true;
            dq.push_back({ sf.x - 1, sf.y, sf.dist + 1 });
        }
    }

    if (!st.empty()) {
        return (*st.begin());
    }
    else {
        return { -1, -1, -1 };
    }
}

int main()
{
    deque<State> dq;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> space[i][j];
            if (space[i][j] == 9)
                dq.push_back({2, 0, i, j, 0});
        }
    }

    int max_seconds = 0;

    while (dq.size())
    {
        State s = dq.front();
        dq.pop_front();

        max_seconds = std::max(s.seconds, max_seconds);
        auto food = bfs(s.x, s.y, s.size);

        if (food.dist == -1) break;
        else if (s.size - 1 == s.ate) {
            dq.push_back({ s.size + 1, 0, food.x, food.y, s.seconds + food.dist });
            space[food.x][food.y] = 9;
            space[s.x][s.y] = 0;
        }
        else {
            dq.push_back({ s.size, s.ate + 1, food.x, food.y, s.seconds + food.dist });
            space[food.x][food.y] = 9;
            space[s.x][s.y] = 0;
        }
    }

    std::cout << max_seconds;
}