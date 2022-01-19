#include <iostream>
#include <deque>

using namespace std;
const int POS_MAX = 222222;
bool visited[POS_MAX + 1] = { 0 };

int main() {
    int n, k;
    cin >> n >> k;

    deque<pair<int, int>> dq;
    dq.push_back({ n, 0 });

    int res = INT32_MAX;

    while(dq.size()) {
        auto c = dq.front();
        dq.pop_front();

        if (c.first == k) {
            res = c.second;
            break;
        }

        int t = c.first * 2;
        if (t != 0 && t < POS_MAX && !visited[t]) {
            dq.push_front({ t, c.second });
            visited[t] = true;
        }

        t = c.first + 1;
        if (t < POS_MAX && !visited[t]) {
            dq.push_back({ t, c.second + 1});
            visited[t] = true;
        }

        t = c.first - 1;
        if (t >= 0 && !visited[t]) {
            dq.push_back({ t, c.second + 1});
            visited[t] = true;
        }
    }

    cout << res;
}