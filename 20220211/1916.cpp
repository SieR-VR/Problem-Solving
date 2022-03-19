#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int INF = 987654321;
int n, m;

map<int, int> edges[1001];

int distances[1001];

void djikstra(int start) {
    for(int i = 1; i <= n; i++)
        distances[i] = INF;

    distances[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ start, 0 });

    while(pq.size()) {
        int c = pq.top().first;
        int d = -pq.top().second;
        pq.pop();

        if (distances[c] < d) continue;

        for(auto edge : edges[c]) {
            int next = edge.first;
            int next_d = d + edge.second;

            if (next_d < distances[next]) {
                distances[next] = next_d;
                pq.push({ next, -next_d });
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;

        if (edges[s].find(e) == edges[s].end())
            edges[s].insert({e, w});
        else edges[s][e] = std::min(edges[s][e], w);
    }

    int s, e;
    cin >> s >> e;

    djikstra(s);

    cout << distances[e]; 
}