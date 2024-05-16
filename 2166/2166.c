#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct dot_t {
  ll x;
  ll y;
} dot_t;


int main() {
  int n;
  scanf("%d", &n);

  dot_t *dots = malloc(sizeof(dot_t) * n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &dots[i].x, &dots[i].y);
  }

  ll sum = 0;
  for (int k = 1; k + 1 < n; k++) {
    dot_t v1, v2;
    v1.x = dots[k].x - dots[0].x;
    v1.y = dots[k].y - dots[0].y;

    v2.x = dots[k + 1].x - dots[0].x;
    v2.y = dots[k + 1].y - dots[0].y;

    ll area = v1.x * v2.y - v2.x * v1.y;
    sum += area;
  }

  printf("%lld%s\n", llabs(sum >> 1), sum & 0x1 ? ".5" : ".0");
}
