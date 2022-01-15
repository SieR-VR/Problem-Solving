#include <stdio.h>

typedef long long ll;

int main() {
    ll table[50];
    for(ll i = 0, r = 1; i < 50; i++, r *= 31) {
        r %= 1234567891;
        table[i] = r;
    }

    ll n; scanf("%d", &n);
    ll num = 0;
    char c; scanf("%c", &c);

    for(int i = 0; i < n; i++) {
        char c; scanf("%c", &c);
        num += (ll)((c - 96) * table[i]);
        num %= 1234567891;
    }

    printf("%lld", num);
}