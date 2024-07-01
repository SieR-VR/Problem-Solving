#include <stdio.h>
#include <stdlib.h>

typedef struct dp_state {
  int len;
  int curr_max;
} dp_state;

int binary_search(dp_state *table, int low, int high, int to_search) {
  int mid = (low + high) / 2;

  if (table[mid].curr_max < to_search) {
    
  }
}

int main() {
  int N;
  scanf("%d", &N);

  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[N]);
  }

  dp_state dp[N];
  dp[0] = (dp_state){.len = 1, .curr_max = A[0]};

  for (int i = 1; i < N; i++) {
    int low = 0, high = 1;
    int mid = (low + high) / 2;

    if (dp)
  }
}
