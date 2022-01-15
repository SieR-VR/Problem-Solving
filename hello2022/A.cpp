#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> table;

ll N, d;
ll N_ = 0;
ll res = -1;
bool skip = false;
bool visited[10] = { false };

void dfs(ll level) {
    if(skip) return;

    if (level == -1 && N_ > N) {
        res = N_;
        skip = true;
    }
    else if (level == -1) {
        return;
    }

    for(ll i = 0; i < d; i++) {
        if (level == d - 1 && i == 0) continue;
        if(visited[i]) continue; 
        
        N_ += table[level] * i;
        visited[i] = true;
        dfs(level - 1);
        N_ -= table[level] * i;
        visited[i] = false;
    }
}

int main() {
    cin >> N >> d;

    for(ll i = 0, j = 1; i < d; i++, j *= d)
        table.push_back(j);

    dfs(d - 1);

    cout << res;
}