#include <stdio.h>
#include <stdlib.h>

int main() {
  char list[3][9];

  for (int j = 0; j < 3; j++)
    scanf("%s", list[j]);

  int t, i;
  for (i = 0; i < 3; i++) {
    if (sscanf(list[i], "%d", &t)) break;
  }

  int target = t + (3 - i);

  if (target % 15 == 0) {
    printf("FizzBuzz\n");
  }
  else if (target % 3 == 0) {
    printf("Fizz\n");
  } else if (target % 5 == 0) {
    printf("Buzz\n");
  } else {
    printf("%d\n", target);
  }
}
