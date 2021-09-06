#include <iostream>
#include <vector>

typedef long long ll;
const ll MOD = 1000000007;

typedef std::vector<std::vector<ll>> vec2d;

ll N = 2;
vec2d A[64];

vec2d dot(const vec2d &a, const vec2d &b)
{
    vec2d res;
    for (int i = 0; i < N; i++)
    {
        std::vector<ll> temp1;
        for (int j = 0; j < N; j++)
        {
            ll temp2 = 0;
            for (int k = 0; k < N; k++)
            {
                temp2 += a[i][k] * b[k][j];
            }
            temp1.push_back(temp2 % MOD);
        }
        res.push_back(temp1);
    }

    return res;
}


int main() {
    ll n;
    std::cin >> n;

    A[0].push_back({1, 1});
    A[0].push_back({1, 0});

    for(int i = 1; i < 64; i++) {
        A[i] = dot(A[i-1], A[i-1]);
    }

    vec2d res;
    res.push_back({1, 0});
    res.push_back({0, 1});

    for(int i = 0; i < 64; i++) {
        if((n >> i) & 0x01) res = dot(res, A[i]);
    }

    std::cout << res[1][0];
}