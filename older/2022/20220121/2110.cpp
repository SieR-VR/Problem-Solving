#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int n, m;
std::vector<ll> coordinates;

bool check(ll len) {
    int to_install = m;

    for(auto i = coordinates.begin(); i != std::prev(coordinates.end()); i++) {
        
    }
}

ll solve() {
    ll left = 0, right = (ll)INT32_MAX;
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
    
    for(int i = 0; i < n; i++) {
        int t; std::cin >> t;
        coordinates.push_back(t);
    }

    std::sort(coordinates.begin(), coordinates.end());
    std::cout << solve();
}