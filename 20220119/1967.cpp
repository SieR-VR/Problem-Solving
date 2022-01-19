#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    vector<pair<int, int>> lines;
};

int n;
int res_max = 0;
Node nodes[100001];
bool visited[100001] = { false };

int dfs(int node_num) {
    visited[node_num] = true;

    Node c = nodes[node_num];
    vector<int> lengths;

    for(auto l : c.lines) {
        if (!visited[l.first])
            lengths.push_back(dfs(l.first) + l.second);
    }

    sort(lengths.begin(), lengths.end());

    if (lengths.size() >= 2)
        res_max = max(res_max, (*prev(lengths.end())) + (*prev(prev(lengths.end()))));
    if (lengths.size()) {
        res_max = max(res_max, *prev(lengths.end()));
        return *prev(lengths.end());
    }
    else return 0;
}

int main() {
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int t1; cin >> t1;
        int t2, t3; cin >> t2 >> t3;

        nodes[t1].lines.push_back({ t2, t3 });
        nodes[t2].lines.push_back({ t1, t3 });
    }

    int res = dfs(1);
    cout << max(res, res_max);
}