#include <iostream>
#include <set>
#include <vector>
#include <memory.h>

struct Node
{
    std::set<int> neibor;
};

int n, m;
std::vector<Node> *nodes;
bool *visited;

int res = 0;

void dfs(int current) {
    if (visited[current]) return;
    visited[current] = true;
    res++;

    for(int n : (*nodes)[current].neibor) {
        dfs(n);
    }
}

int main() {
    std::cin >> n >> m;
    nodes = new std::vector<Node>(n + 1);
    visited = new bool[n + 1];
    memset(visited, 0, n + 1);

    for(int i = 0; i < m; i++) {
        int t1, t2; std::cin >> t1 >> t2;
        (*nodes)[t2].neibor.insert(t1);
        (*nodes)[t1].neibor.insert(t2);
    }

    dfs(1);
    std::cout << res - 1;
}