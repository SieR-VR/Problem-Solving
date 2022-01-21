#include <iostream>
#include <math.h>

typedef long long ll;
ll dp[1500001] = { 0 };

int main() {
    ll n; std::cin >> n;
    dp[0] = 0; dp[1] = 1;

    for(int i = 2; i <= (n % 1500000); i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
    }

    std::cout << dp[n%1500000];
}