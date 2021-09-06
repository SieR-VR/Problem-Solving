#include <iostream>
#include <vector>

typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    ll N, K;
    std::cin >> N >> K;


    if(K == 0 || N == 1) {
        std::cout << 1;
        return 0;
    }

    ll facN = 1, facK = 1, facNK = 1;

    for(ll i = 1; i <= N; i++) {
        facN = (facN * i) % MOD;
        if(i == K) facK = facN;
        if(i == (N-K)) facNK = facN; 
    }

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
    std::cout << res;
}