#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t formula(uint64_t A, uint64_t B, uint64_t A_count, uint64_t B_count) {
    return A * A_count + B * B_count;
}

int main() {
    uint64_t N; // 1 <= N <= 10^7
    scanf("%lu", &N);

    uint64_t A, B, Pa, Pb; // 1 <= A, B <= 10^4 ; 0 <= Pa, Pb <= 10^7
    scanf("%lu %lu %lu %lu", &A, &Pa, &B, &Pb);

    uint64_t max_ = 0;
    uint64_t max_A_count, max_B_count;

    for (uint64_t A_count = 0; A_count * Pa <= N; A_count++) {
        uint64_t A_value = Pa * A_count;
        uint64_t B_value_max = N - A_value;
        
        uint64_t B_count = B_value_max / Pb;
        uint64_t formula_calculated = formula(A, B, A_count, B_count);

        if (max_ < formula_calculated) {
            max_ = formula_calculated;
            max_A_count = A_count;
            max_B_count = B_count;
        }
    }

    printf("%lu %lu\n", max_A_count, max_B_count);
}