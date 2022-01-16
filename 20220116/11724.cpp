#include <iostream>
#include <set>
#include <vector>

struct Node
{
    std::set<int> neibor;
};

int n, m;
std::vector<Node> *nodes;
bool *visited;

void dfs(int n) {
    if(visited[n]) return;
    visited[n] = true;

    for(auto ne : (*nodes)[n].neibor) {
        dfs(ne);
    }
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

    int count = 0;
    for(int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    std::cout << count;
}