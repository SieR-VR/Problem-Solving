#include <iostream>

typedef long long ll;

ll f(ll i) {
    ll r = 0;
    for (ll b = 0; ((ll)1 << b) <= i; b++) {
        if (b == 0) {
            r += i;
        }
        else {
            r += ((i / ((ll)1 << b)) * ((ll)1 << (b - 1)));
        }
    }

    return r;
}

int main() {
    ll a, b;
    std::cin >> a >> b;

    std::cout << f(b) - f(a-1);
}