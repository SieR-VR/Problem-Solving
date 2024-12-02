#include <stdio.h>
#include <stdlib.h>

int exist_table[1000001];
int score_table[1000001];

int main() {
  int N;
  scanf("%d", &N);

  int arr[N];
  for (int *it = arr; it < arr + N; it++) {
    scanf("%d", it);
    exist_table[*it] = 1;
  }

  for (int *it = arr; it < arr + N; it++) {
    int x_i = *it;

    for (int target = x_i * 2; target <= 1000000; target += x_i) {
      if (exist_table[target]) {
        score_table[x_i]++;
        score_table[target]--;
      }
    }
  }

  for (int *it = arr; it < arr + N; it++) {
    printf("%d ", score_table[*it]);
  }
}
