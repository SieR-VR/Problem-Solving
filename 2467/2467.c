#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pair_t {
  int first;
  int second;
} pair_t;

int main() {
  int N;
  scanf("%d", &N);

  int arr[N];
  for (int i = 0; i < N; i++)
    scanf("%d", arr + i);

  pair_t smallest = {.first = 1000000001, .second = 1000000001};

  pair_t pivot = {
      .first = 0,
      .second = N - 1,
  };

  while (pivot.first != pivot.second) {
    int smallest_prop = smallest.first + smallest.second;
    int current_prop = arr[pivot.first] + arr[pivot.second];

    if (abs(smallest_prop) > abs(current_prop)) {
      smallest = (pair_t) { .first = arr[pivot.first], .second = arr[pivot.second] };
    }

    if (current_prop < 0) {
      pivot.first++;
    } else {
      pivot.second--;
    }
  }

  printf("%d %d\n", smallest.first, smallest.second);
}
