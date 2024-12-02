#include <cstdlib>
#include <iostream>
#include <algorithm>

#include <deque>
#include <limits>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

__int128 gcd(__int128 a, __int128 b) {
  a = std::abs(a);
  b = std::abs(b);

  __int128 r;
  if (a < b)
    std::swap(a, b);

  while (b) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

bool miller_rabin(ll n, ll a) {
  static const auto modpq = [](ll p, ll q, ll mod) {
    p %= mod;
    q %= mod;
    ull r = 0, w = p;

    while (q) {
      if (q % 2)
        r = (r + w) % mod;
      w = (2 * w) % mod;
      q >>= 1;
    }

    return (ll)r;
  };

  static const auto powmod = [](ll a, ll m, ll p) {
    ll res = 1;
    a %= p;

    while (m) {
      if (m % 2)
        res = modpq(res, a, p);
      a = modpq(a, a, p);
      m >>= 1;
    }

    return res;
  };

  ll k = n - 1;

  while (true) {
    ll d = powmod(a, k, n);
    if (k % 2)
      return (d == 1 || d == n - 1);
    if (d == n - 1)
      return true;
    k >>= 1;
  }
}

bool isPrime(ll n) {
  static const std::vector<ll> primes = {2,  3,  5,  7,  11, 13, 17,
                                         19, 23, 29, 31, 37, 41};

  if (n == 1)
    return false;

  for (ll prime : primes) {
    if (n == prime)
      return true;
    if (n % prime == 0)
      return false;
    if (!miller_rabin(n, prime))
      return false;
  }

  return true;
}

__int128 hypo(__int128 x, __int128 a, __int128 n) { return (x * x % n + a) % n; }

bool pollard_rho(__int128 n, std::vector<ll> &vec) {
  if (n == 1)
    return false;

  if (isPrime(n)) {
    vec.push_back(n);
    return false;
  }

  while (true) {
    __int128 a = rand() % 20 + 1;
    __int128 x = rand() % (n - 2) + 2;
    __int128 y = x;

    __int128 g = 1;

    while (g == 1) {
      x = hypo(x, a, n);
      y = hypo(hypo(y, a, n), a, n);
      g = gcd(n, std::abs(x - y));
    }

    if (g == n) {
      continue;
    }

    return pollard_rho(g, vec) || pollard_rho(n / g, vec);
  }
}

int main() {
  ll n;
  std::cin >> n;

  std::vector<ll> ans;

  while (!(n & 0x01)) {
    ans.push_back(2);
    n >>= 1;
  }

  pollard_rho(n, ans);
  std::sort(ans.begin(), ans.end());

  for (auto a : ans) {
    printf("%lld\n", a);
  }
}
