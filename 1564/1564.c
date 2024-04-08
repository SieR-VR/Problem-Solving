#include <stdio.h>

const int MOD = 100000;


int main() {
    int fac[25];
    fac[0] = 1;
    for (int i = 1; i < 25; i++)
        fac[i] = (fac[i-1] * i) % MOD;

    printf("int answer_list[24] = {\n");
    for (int i = 1; i < 25; i++) {
        printf("%d, ", fac[i]);
    }
    printf("\n};\n");
}
