#include <stdio.h>

int main() {
    for (;;) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a == 0 && b == 0 && c == 0)
            break;

        if (a == b && b == c) {
            printf("Equilateral\n");
            continue;
        }
        
        if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
            printf("Invalid\n");
            continue;
        }

        if (a == b || b == c || c == a) {
            printf("Isosceles\n");
            continue;
        }


        printf("Scalene\n");
        continue;
    }
}