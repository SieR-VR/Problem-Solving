#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define INF 987654321

map<int, int> adj[20001];
int dist[20001];

int main() {
    int v, e; cin >> v >> e;
    int k; cin >> k;

    for (int i = 1; i <= v; i++)
        dist[i] = INF;
    dist[k] = 0;

    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (adj[u].find(v) != adj[u].end())
            adj[u].find(v)->second = min(adj[u].find(v)->second, w);
        else
            adj[u].insert({ v, w });
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, k });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for(auto e : adj[current]) {
            int next = e.first;
            int new_cost = cost + e.second;

            if (new_cost < dist[next]) {
                dist[next] = new_cost;
                pq.push({ -new_cost, next });
            }
        }
    }

    for(int i = 1; i <= v; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else 
            cout << dist[i] << "\n";
    }
}