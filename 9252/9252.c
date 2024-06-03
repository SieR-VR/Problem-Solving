#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef enum transition_kind_t {
  LEFT,
  RIGHT,
  BOTH,
} transition_kind_t;

typedef struct memo_state_t {
  int length;
  transition_kind_t transition_kind;
} memo_state_t;

typedef struct ctx_t {
  memo_state_t memo[1001][1001];
  const char *s1, *s2;
} ctx_t;

int count = 0;

int lcs(int left, int right, ctx_t *context) {
  if (left == -1 || right == -1) {
    return 0;
  }

  if (context->memo[left][right].length != -1) {
    return context->memo[left][right].length;
  }

  if (context->s1[left] == context->s2[right]) {
    context->memo[left][right] = (memo_state_t) {
      .length = lcs(left - 1, right - 1, context) + 1,
      .transition_kind = BOTH
    };
  }
  else {
    context->memo[left][right] = (memo_state_t) {
      .length = MAX(lcs(left-1, right, context), lcs(left, right-1, context)),
      .transition_kind = lcs(left-1, right, context) > lcs(left, right-1, context) ? LEFT : RIGHT,
    };
  }

  return context->memo[left][right].length;
}

int main() {
  ctx_t ctx;
  for (int i = 0; i < 1001 * 1001; i++)
    ctx.memo[i / 1001][i % 1001] = (memo_state_t) { .length = -1, .transition_kind = 0 };

  char s1[1024], s2[1024];
  scanf("%s %s", s1, s2);

  ctx.s1 = s1, ctx.s2 = s2;
  int s1_len = strlen(s1), s2_len = strlen(s2);

  int final_state = lcs(s1_len - 1, s2_len - 1, &ctx);

  int pivot = final_state, pivot_s1 = s1_len - 1, pivot_s2 = s2_len - 1;
  char result[1024]; result[pivot] = '\0';

  while (pivot) {
    memo_state_t current_state = ctx.memo[pivot_s1][pivot_s2];

    switch (current_state.transition_kind) {
      case BOTH:
        result[pivot - 1] = s1[pivot_s1];
        pivot_s1--, pivot_s2--;

        pivot--;
        continue;
      case LEFT:
        pivot_s1--;
        continue;
      case RIGHT:
        pivot_s2--;
        continue;
    }
  }

  if (final_state) {
    printf("%d\n%s\n", final_state, result);
  } else {
    printf("0\n");
  }
}
