#include <iostream>

typedef long long ll;
using namespace std;

int main() {
    ll n, m; cin >> n >> m;

    ll dp[101][101] = { 0 };
    dp[0][0] = 1; dp[1][0] = 1; dp[1][1] = 1;

    for(ll i = 2; i <= n; i++) {
        for(ll j = 0; j <= i; j++) {
            if(j == 0) dp[i][j] = 1;
            else if(j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
        }
    }

    cout << dp[n][m];
}