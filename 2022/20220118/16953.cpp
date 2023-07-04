#include <iostream>
#include <queue>

typedef long long ll;
typedef std::pair<ll, ll> P;

int main() {
    ll a, b;
    std::cin >> a >> b;

    std::priority_queue<P, std::vector<P>, std::greater<P>> dq;
    dq.push({ a, 1 });

    ll res = -1;

    while(dq.size()) {
        auto f = dq.top();
        dq.pop();

        if (f.first == b) {
            res = f.second;
            break;
        }
        else if (f.first > b)
            break;

        dq.push({ f.first * 2, f.second + 1 });
        dq.push({ f.first * 10 + 1, f.second + 1 });
    }

    std::cout << res;
}