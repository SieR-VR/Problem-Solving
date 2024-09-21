#include <stdio.h>
#include <stdlib.h>

int main() {
  int N; scanf("%d", &N);

  int counts[6];
  for (int *p = counts; p < counts + 6; p++) {
    scanf("%d", p);
  }

  int T, P; scanf("%d %d", &T, &P);

  int sum = 0;
  for (int *p = counts; p < counts + 6; p++) {
    sum += (*p % T) == 0 ? (*p / T) : (*p / T) + 1;
  }

  printf("%d\n%d %d\n", sum, N / P, N % P);
}
