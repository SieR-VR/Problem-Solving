#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
ll mu[1111111] = { 0 };

ll k;

void build_mu() {
    mu[1] = 1;
    for(ll i = 1; i <= 1000000; i++) {
        if(!mu[i]) continue;
        for(ll j = i + i; j <= 1000000; j += i) {
            mu[j] -= mu[i];
        }
    }
}

ll cal(ll a) {
    ll count = 0;

    for(ll i = 1; i * i <= a; i++) {
        count += mu[i] * (a / (i * i));
    }

    return count;
}

ll solve() {
    ll start = 1, end = 3 * k, mid = (start + end) / 2;

    while(true) {
        ll k_ = cal(mid);

        if (k_ > k) {
            end = mid + 1;
            mid = (start + end) / 2;
        }
        else if(k_ < k) {
            start = mid - 1;
            mid = (end + start) / 2;
        }
        else break;

        if (start + 16 > end) break;
    }

    for(ll i = start; i <= end; i++) {
        if (cal(i) == k) return i;
    }
}

int main() {
    build_mu();

    cin >> k;    
    cout << solve();
}