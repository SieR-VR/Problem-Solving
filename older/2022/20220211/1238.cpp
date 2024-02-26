#include <iostream>
#include <queue>

using namespace std;

const int INF = 87654321;
int n, m, x;

int weight[1001][1001] = { 0 };
vector<pair<int, int>> edges[1001];

int main() {
    cin >> n >> m >> x;

    for(int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;

        edges[s].push_back({ e, w });
        weight[s][e] = w;
    }

    vector<int> result(n+1, 0);

    for(int i = 1; i <= n; i++) {
        vector<int> d(n+1, INF);

        d[i] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({ i, 0 });

        while(pq.size()) {
            int c = pq.top().first;
            int distance = -pq.top().second;

            pq.pop();
            if (d[c] < distance) continue;

            for (int j = 0; j < edges[c].size(); j++) {
                int next = edges[c][j].first;
                int next_d = distance + edges[c][j].second;

                if (next_d < d[next]) {
                    d[next] = next_d;
                    pq.push({ next, -next_d });
                }
            }
        }

        if (i != x) {
            result[i] += d[x];
        }
        else {
            for(int i = 1; i <= n; i++) {
                result[i] += d[i]; 
            }
        }
    }

    int max = 0;
    for(int i = 1; i <= n; i++) {
        max = std::max(result[i], max);
    }

    cout << max;
}