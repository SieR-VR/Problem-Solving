#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <memory.h>

struct Node
{
    std::set<int> neibor;
};

int n, m, v;
std::vector<Node> *nodes;
bool *visited;

void dfs(int current)
{
    if(visited[current]) return;
    visited[current] = true;
    std::cout << current << " ";

    for (int n : (*nodes)[current].neibor)
        dfs(n);
}

void bfs(int root)
{
    std::deque<int> q;
    visited[root] = true;
    q.push_back(root);

    while(!q.empty()) {
        int current = q.front(); q.pop_front();
        std::cout << current << " ";

        for (int n : (*nodes)[current].neibor) {
            if (!visited[n]) {
                visited[n] = true;
                q.push_back(n);
            }
        }
    }
}

int main()
{
    std::cin >> n >> m >> v;
    nodes = new std::vector<Node>(n + 1);
    visited = new bool[n + 1];
    memset(visited, 0, n + 1);

    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        std::cin >> t1 >> t2;
        (*nodes)[t1].neibor.insert(t2);
        (*nodes)[t2].neibor.insert(t1);
    }

    dfs(v);
    memset(visited, 0, n + 1);
    std::cout << "\n";
    bfs(v);
}