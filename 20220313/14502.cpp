#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, nm;
vector<vector<int>> map;

int mov[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

bool check(int i, int j, vector<vector<int>> &map) {
    return (i >= 0) && (i < n) && (j >= 0) && (j <= m) && (!map[i][j]);
}

void bfs(int i, int j, vector<vector<int>>& map) {
    queue<pair<int, int>> q;
    q.push({ i, j });

    while (q.size())
    {
        auto top = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            if (check(top.first + mov[k][0], top.second + mov[k][1], map)) {
                map[top.first + mov[k][0]][top.second + mov[k][1]] = 2;
                q.push({ top.first + mov[k][0], top.second + mov[k][1] });
            }
        }
    }
    
}

int count(vector<vector<int>>& map) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (map[i][j] == 2) bfs(i, j, map);
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (map[i][j] == 0) cnt++;
        }
    }
    
    return cnt;
}

int main() {
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    nm = n * m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int res_max = 0;

    for(int i = 0; i < nm; i++) {
        if (map[i / m][i % m]) continue;
        for(int j = i + 1; j < nm; j++) {
            if (map[j / m][j % m]) continue;
            for(int k = j + 1; k < nm; k++) {
                if (map[k / m][k % m]) continue;
                vector<vector<int>> temp_map = map;
                temp_map[i / m][i % m] = 1;
                temp_map[j / m][j % m] = 1;
                temp_map[k / m][k % m] = 1;

                res_max = max(res_max, count(temp_map));
            }
        }
    }

    cout << res_max;
}