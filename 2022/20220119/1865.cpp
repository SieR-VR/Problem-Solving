#include <iostream>
#include <vector>
#include <map>

const int INF = 12345678;
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int n, m, w;
        cin >> n >> m >> w;

        vector<int> dist(n + 1, INF);
        dist[1] = 0;

        vector<pair<pair<int, int>, int>> edges;

        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({{s, e}, t});
            edges.push_back({{e, s}, t});
        }

        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({{s, e}, -t});
        }

        for (int i = 1; i <= n - 1; i++)
        {
            for (auto e : edges)
            {
                int from = e.first.first;
                int to = e.first.second;
                int cost = e.second;
                dist[to] = min(dist[to], dist[from] + cost);
            }
        }

        bool flag = false;

        for (auto e : edges)
        {
            int from = e.first.first;
            int to = e.first.second;
            int cost = e.second;

            if (dist[to] > dist[from] + cost) {
                flag = true;
                break;
            }
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}