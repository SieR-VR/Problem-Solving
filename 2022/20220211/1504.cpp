#include <iostream>
#include <queue>
#include <map>

using namespace std;

const int INF = 87654321;
int n, e;

map<int, int> edges[801];

int distances[801];

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

int main()
{
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;

        if (edges[s].find(e) == edges[s].end())
        {
            edges[s].insert({e, w});
            edges[e].insert({s, w});
        }
        else {
            edges[s][e] = std::min(edges[s][e], w);
            edges[e][s] = std::min(edges[e][s], w);
        }
    }

    int v1, v2;
    cin >> v1 >> v2;

    djikstra(1);
    int tov1 = distances[v1];
    int tov2 = distances[v2];

    djikstra(v1);
    int v1v2 = distances[v2];
    int v1n = distances[n];

    djikstra(v2);
    int v2n = distances[n];

    int res = std::min(tov1 + v1v2 + v2n, tov2 + v1v2 + v1n);
    if (res >= INF) cout << -1;
    else cout << res;
}