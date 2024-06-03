#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main() {
  int N; int S;
  scanf("%d %d", &N, &S);

  int arr[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", arr + i);
  }

  int pivot_left = 0, pivot_right = 1, acc_sum = *arr;
  int shortest_length = 1000000;

  while (pivot_left < N && pivot_right <= N) {
    if (acc_sum >= S) {
      shortest_length = MIN(shortest_length, pivot_right - pivot_left);

      acc_sum -= arr[pivot_left];
      pivot_left++;
    }
    else {
      acc_sum += arr[pivot_right];
      pivot_right++;
    }
  }

  printf("%d\n", shortest_length == 1000000 ? 0 : shortest_length);
}
