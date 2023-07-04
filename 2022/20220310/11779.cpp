#include <iostream>
#include <map>
#include <vector>
#include <queue>

const int INF = 87654321;

using namespace std;

int n, m;
int city_start, city_end;

vector<map<int, int>> edges;
vector<int> dist;
vector<int> passthrough;
vector<int> visited;
vector<int> result_route;


void djikstra() {
    priority_queue<pair<int, int>> pq;
    dist[city_start] = 0;
    result_route[city_start] = 0;
    pq.push({ 0, city_start });

    while(pq.size()) {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (!visited[current]) visited[current] = true;
        else continue;

        for(auto &e : edges[current]) {
            if (dist[e.first] > cost + e.second) {
                passthrough[e.first] = current;
                dist[e.first] = cost + e.second;
                pq.push({ -dist[e.first], e.first });
            }
        }
    }

    int vert = city_end;
    while(vert) {
        result_route.insert(result_route.begin(), vert);
        vert = passthrough[vert];
    }
}

int main() {
    cin >> n >> m;
    edges.resize(n + 1, map<int, int>());
    dist.resize(n + 1, INF);
    passthrough.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    result_route.resize(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;

        if (edges[s].find(e) == edges[s].end()) edges[s][e] = w;
        else edges[s][e] = min(edges[s][e], w); 
    }
    cin >> city_start >> city_end;

    if (city_start == city_end) {
        cout << "0\n1\n" << city_start;
        return 0;
    }

    djikstra();

    cout << dist[city_end] << "\n";
    cout << result_route.size() << "\n";

    for(int i : result_route) {
        cout << i << " ";
    }
}