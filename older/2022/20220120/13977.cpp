#include <iostream>
#include <vector>

typedef long long ll;

const ll MOD = 1000000007;
ll fac[4000001] = { 1, };

int main()
{
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for(ll i = 1; i <= 4000000; i++)
        fac[i] = fac[i-1] * i % MOD;

    ll m; std::cin >> m;
    for(int i = 0; i < m; i++) {
        ll N, K;
        std::cin >> N >> K;

        if(K == 0 || N == 1) {
            std::cout << "1\n";
            continue;
        }

        ll facN = fac[N], facK = fac[K], facNK = fac[N-K];
        ll facKNK = facK * facNK % MOD;

        int bitflag = MOD - 2;

        ll pows[32];
        pows[0] = facKNK;

        for(int i = 1; i < 32; i++)
            pows[i] = pows[i-1] * pows[i-1] % MOD;

        ll powKNK = 1;

        for(int i = 0; i < 32; i++)
            if((bitflag >> i) & 0x01) powKNK = powKNK * pows[i] % MOD;

        ll res = powKNK * facN % MOD;
        std::cout << res << "\n";
    }
}