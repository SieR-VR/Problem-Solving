#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <memory.h>

struct Node
{
    std::set<int> neibor;
};

int n, m;
std::vector<Node> *nodes;
bool *visited;

int bfs(int g) {
    int bacon = 0;
    std::deque<std::pair<int, int>> dq;
    dq.push_back({g, 0});
    visited[g] = true;

    while (!dq.empty())
    {
        auto curr = dq.front();
        dq.pop_front();

        for(int n : (*nodes)[curr.first].neibor) {
            if(!visited[n]) {
                visited[n] = true;
                bacon += curr.second + 1;
                dq.push_back({ n, curr.second + 1 });
            }
        }
    }
    
    return bacon;
}

int main() {
    std::cin >> n >> m;
    nodes = new std::vector<Node>(n + 1);
    visited = new bool[n + 1];

    for(int i = 0; i < m; i++) {
        int t1, t2; std::cin >> t1 >> t2;
        (*nodes)[t1].neibor.insert(t2);
        (*nodes)[t2].neibor.insert(t1);
    }

    int bacon_min = INT32_MAX;
    int person = 0;
   
    for(int i = 1; i <= n; i++) {
        memset(visited, 0, n+1);
        int bacon = bfs(i);

        if (bacon < bacon_min) {
            bacon_min = bacon;
            person = i;
        }
    }

    std::cout << person;
}