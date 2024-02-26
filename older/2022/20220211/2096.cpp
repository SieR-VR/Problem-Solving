#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int table[n][3];
    for(int i = 0; i < n; i++)
        cin >> table[i][0] >> table[i][1] >> table[i][2];

    if (n == 1) {
        int res_max = max(max(table[0][0], table[0][1]), table[0][2]);
        int res_min = min(min(table[0][0], table[0][1]), table[0][2]);

        cout << res_max << " " << res_min;
        return 0;
    } 

    int dp_max[2][3];
    int dp_min[2][3];

    dp_max[0][0] = table[0][0];
    dp_max[0][1] = table[0][1];
    dp_max[0][2] = table[0][2];

    dp_min[0][0] = table[0][0];
    dp_min[0][1] = table[0][1];
    dp_min[0][2] = table[0][2];

    for(int i = 1; i < n; i++) {
        dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + table[i][0];
        dp_max[1][1] = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]) + table[i][1];
        dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + table[i][2];

        dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + table[i][0];
        dp_min[1][1] = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]) + table[i][1];
        dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + table[i][2];

        for(int i = 0; i < 3; i++) {
            dp_max[0][i] = dp_max[1][i];
            dp_min[0][i] = dp_min[1][i];
        }
    }

    int res_max = max(max(dp_max[1][0], dp_max[1][1]), dp_max[1][2]);
    int res_min = min(min(dp_min[1][0], dp_min[1][1]), dp_min[1][2]);

    cout << res_max << " " << res_min;
}