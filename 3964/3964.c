#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(x, y) ((x < y) ? (x) : (y))

typedef long long ll;

ll prime_table[1000001];
ll prime_count = 0;

ll get_prime_count(ll n, ll m) {
    ll result = 0;
    for (ll c = n; c >= m; c /= m) {
        result += c / m;
    }

    return result;
}

void init_prime_table() {
    for (ll i = 0; i <= 1000000; i++)
        prime_table[i] = 0;

    ll prime_sieve[1000001];
    for (ll i = 0; i <= 1000000; i++)
        prime_sieve[i] = 1;
    
    prime_sieve[1] = 0;
    for (ll i = 2; i <= 1000000; i++) {
        if (!prime_sieve[i])
            continue;

        for (ll j = i * 2; j <= 1000000; j += i) {
            prime_sieve[j] = 0;
        }
    }

    for (ll i = 2, table_index = 0; i <= 1000000; i++)
        if (prime_sieve[i])
            prime_table[table_index++] = i;
    
    for (ll i = 0; i <= 1000000; i++)
        if (!prime_table[i]) {
            prime_count = i;
            break;
        }
}

int main() {
    init_prime_table();

    ll T; scanf("%lld", &T);
    for (ll tk = 0; tk < T; tk++) {
        ll N, K; scanf("%lld %lld", &N, &K);
        ll *factorization_table = malloc(prime_count * sizeof(ll));
        for (ll i = 0; i < prime_count; i++)
            factorization_table[i] = 0;

        for (ll i = 0; i < prime_count; i++) {
            while (K % prime_table[i] == 0) {
                factorization_table[i]++;
                K /= prime_table[i];
            }

            if (K == 1)
                break;
        }

        ll result_max = __LONG_LONG_MAX__;

        for (ll i = 0; i < prime_count; i++) {
            if (factorization_table[i]) {
                result_max = MIN(result_max, (get_prime_count(N, prime_table[i]) / factorization_table[i]));
            }
        }

        if (K != 1) {
            result_max = MIN(result_max, (get_prime_count(N, K)));
        }

        printf("%lld\n", result_max);
        free(factorization_table);
    }    
}