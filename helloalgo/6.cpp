#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll m, n;
std::vector<ll> arr;

ll is(ll height) {
    ll len = 0;
    for (int i = 0; i < m; i++) {
        if(arr[i] > height) len += (arr[i] - height);
        if (len >= n) return true;
    }

    return false;
}

ll sol() {
    ll left = 0, right = 1000000000;
    ll mid, res;

    while (left <= right) {
        mid = (left + right) / 2;
        if (is(mid)) {
            res = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return res;
}

int main() {
    
    std::cin >> m >> n;
    for(ll i = 0; i < m; i++) {
        ll t; std::cin >> t;
        arr.push_back(t);
    }

    std::sort(arr.begin(), arr.end(), [](ll l1, ll l2) { return l1 > l2; });

    std::cout << sol();
}