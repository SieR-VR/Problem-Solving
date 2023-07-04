#include <iostream>
#include <deque>

using namespace std;
struct State {
    int cell, count;
};

int ladder_snake[101] = { 0 };
bool visited[101] = { false };

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n + m; i++) {
        int t1, t2; cin >> t1 >> t2;
        ladder_snake[t1] = t2;
    }

    deque<State> dq;
    dq.push_back({ 1, 0 });
    visited[1] = true;

    int res = 0;

    while(dq.size()) {
        auto c = dq.front(); dq.pop_front();

        if (c.cell == 100) {
            res = c.count;
            break;
        }

        for(int i = 1; i <= 6; i++) {
            if (c.cell + i > 100) continue;

            if (ladder_snake[c.cell + i]) {
                dq.push_back({ ladder_snake[c.cell + i], c.count + 1 });
                visited[ladder_snake[c.cell + i]] = true;
            }
            else if (!visited[c.cell + i]) {
                dq.push_back({ c.cell + i, c.count + 1 });
                visited[c.cell + i] = true;
            }
        }
    }

    cout << res;
}