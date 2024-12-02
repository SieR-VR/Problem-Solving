#include <stdio.h>
#include <stdlib.h>

int main() {
  char a, b;
  scanf("%c%c", &a, &b);

  if (a == b) {
    printf("1");
  } else {
    printf("0");
  }
}
