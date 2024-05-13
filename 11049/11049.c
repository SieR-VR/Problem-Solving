#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

int main() {
  ll n;
  scanf("%lld", &n);

  ll size_list[n + 1];
  scanf("%lld", &size_list[0]);

  for (ll i = 1, t; i < n; i++) {
    scanf("%lld %lld", &t, &size_list[i]);
  }

  scanf("%lld", &size_list[n]);

  ll dp[500][500];
  for (ll i = 0; i < 500; i++)
    for (ll j = 0; j < 500; j++)
      dp[i][j] = (ll)1 << 32;

  for (ll i = 0; i < 500; i++)
    dp[i][i] = 0;

  for (ll count = 2; count <= n; count++) {
    for (ll start = 0; start + count - 1 < n; start++) {
      ll end = start + count - 1;

      for (ll sep = start; sep < end; sep++) {
        dp[start][end] =
            MIN(dp[start][end],
                dp[start][sep] + dp[sep + 1][end] +
                    size_list[start] * size_list[sep+1] * size_list[end+1]);
      }
    }
  }

  printf("%lld\n", dp[0][n-1]);
}
