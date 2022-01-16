#include <iostream>

bool cabbage[50][50] = { false };
int m, n, k;

void dfs(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || !cabbage[x][y]) 
        return;

    cabbage[x][y] = false;
    dfs(x-1, y); dfs(x+1, y);
    dfs(x, y-1); dfs(x, y+1);
}

int main() {
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t; std::cin >> t;

    for(int i = 0; i < t; i++) {
        int count = 0;
        std::cin >> m >> n >> k;

        for(int j = 0; j < k; j++) {
            int x_t, y_t; std::cin >> x_t >> y_t;
            cabbage[x_t][y_t] = true;
        }

        for(int y = 0; y < n; y++) {
            for(int x = 0; x < m; x++) {
                if (cabbage[x][y]) {
                    dfs(x, y);
                    count++;
                }
            }
        }

        std::cout << count << "\n";
    }
}