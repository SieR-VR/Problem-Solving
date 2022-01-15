#include <iostream>

typedef long long ll;

int n, m;
ll *woods;

bool check(ll len) {
    ll sum = 0;
    for(int i = 0; i < n; i++) 
        if (woods[i] > len) sum += (woods[i] - len);

    return m <= sum;
}

ll solve() {
    ll left = 0, right = (ll)INT32_MAX + 10;
    ll mid;
    for(;;) {
        mid = ((left + right) / 2);
        if (check(mid)) left = mid - 1;
        else right = mid + 1;

        if (right - left < 32) break;
    }

    ll res;
    for(ll i = left; i != right + 1; i++) {
        if (i == 0) continue;
        if (!check(i)) {
            res = i - 1;
            break;
        }
    }

    return res;
}

int main() {
    std::cin >> n >> m;
    
    woods = new ll[n];
    for(int i = 0; i < n; i++) std::cin >> woods[i];

    std::cout << solve();
}