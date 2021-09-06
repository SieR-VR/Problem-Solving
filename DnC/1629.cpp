#include <iostream>
#include <vector>

typedef long long ll;

int main()
{
    ll a, b, c;
    std::cin >> a >> b >> c;

    a = a % c;
    ll atemp = a;

    ll pows[31] = {-1};
    int bits = b;

    ll bt = 1;
    pows[0] = a;

    for(int i = 1; bt <= b; i++) {
        bt *= 2;
        pows[i] = pows[i-1] * pows[i-1] % c;
    }

    ll res = 1;

    for(int i = 0; i < 31; i++) {
        if((b >> i) & 0x01) {
            res *= pows[i];
            res %= c;
        }
    }

    std::cout << res;
}