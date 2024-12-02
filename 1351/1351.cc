#include <stdio.h>
#include <stdlib.h>
#include <map>

typedef long long ll;
ll N, P, Q;

ll solve(ll i, std::map<ll, ll> &context) {
    if (!i) return 1;

    if (context[i]) {
        return context[i];
    }

    context[i] = solve(i / P, context) + solve(i / Q, context);
    return context[i];
}

int main() {
    std::map<ll, ll> context;

    scanf("%lld %lld %lld", &N, &P, &Q);
    printf("%lld\n", solve(N, context));
}

