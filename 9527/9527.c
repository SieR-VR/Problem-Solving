#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll pow_table[61];

void init_pow_table() {
  pow_table[0] = 0;
  pow_table[1] = 1;

  for (ll i = 2; i <= 60; i++) {
    pow_table[i] = (pow_table[i-1] << 1ll) + (1ll << (i - 1ll));
  }
}

ll bit_count(ll x) {
  if (x == 0ll)
    return 0ll;
  else if (x == 1ll)
    return 1ll;

  ll pow_log = 0;
  for (; x >= ((1ll << (pow_log + 1ll))); pow_log++)
    ;

  ll diff = x & ~(1ll << (pow_log));
  return pow_table[pow_log] + (diff + 1) + bit_count(diff);
}

int main() {
  init_pow_table();

  ll a, b;
  scanf("%lld %lld", &a, &b);

  printf("%lld\n", bit_count(b) - bit_count(a - 1));
}
