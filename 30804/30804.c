#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }

  int count[10];
  for (int i = 0; i < 10; i++)
    count[i] = 0;

  count[arr[0]]++;
  int first = 0, last = 1, max = 1, kinds = 1;

  while (first != last && first != (n - 1)) {
    if (kinds <= 2 && last != n) {
      count[arr[last]]++;
      if (count[arr[last]] == 1) {
        kinds++;
      }

      last++;
      if (kinds <= 2) {
        max = MAX(max, last - first);
      }

    } else {
      count[arr[first]]--;
      if (count[arr[first]] == 0) {
        kinds--;
      }

      first++;
      if (kinds <= 2) {
        max = MAX(max, last - first);
      }
    }
  }

  printf("%d\n", max);
}
