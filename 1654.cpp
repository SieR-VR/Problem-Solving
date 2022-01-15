#include <iostream>

typedef long long ll;

int k, n;
ll *woods;

bool check(ll len) {
    int made = 0;
    for(int i = 0; i < k; i++) 
        made += woods[i] / len;

    return made >= n;
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
    std::cin >> k >> n;
    
    woods = new ll[k];
    for(int i = 0; i < k; i++) std::cin >> woods[i];

    std::cout << solve();
}