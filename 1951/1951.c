#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    ll N; scanf("%lld", &N);
    
    ll logN = -1, temp = 1;
    while (temp <= N) {
        temp *= 10;
        logN++;
    }
    
    ll result = 0;
    ll temp_pow = 1;

    for (ll i = 0; i < logN; i++) {
        result += (i + 1) * temp_pow * 9;
        temp_pow *= 10;
        result %= 1234567;
    }

    result += (logN + 1) * (N - temp_pow + 1);
    result %= 1234567;

    printf("%lld\n", result);
}