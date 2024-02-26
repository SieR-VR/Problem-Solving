#include <iostream>
using namespace std;

int n, m;

int table[100][100] = { 0 };
bool visited[100][100] = { 0 };

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y) {
    if (!check(x, y) || visited[x][y]) return;

    if (table[x][y]) {
        table[x][y]++;
        return;
    }
    else {
        visited[x][y] = 1;
        dfs(x-1, y);
        dfs(x, y-1);
        dfs(x+1, y);
        dfs(x, y+1);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> table[i][j];

    int cnt = 0;

    for(;;) {
        dfs(0, 0);
        bool flag = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (table[i][j] >= 3) {
                    flag = false;
                    table[i][j] = 0;
                }
                else if (table[i][j] == 2) {
                    flag = false;
                    table[i][j] = 1;
                }
                visited[i][j] = false;
            }
        }

        if (flag) break;
        else cnt++;
    }

    cout << cnt;
}