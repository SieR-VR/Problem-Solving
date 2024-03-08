#include <stdatomic.h>
#include <stdio.h>

#define PRIME_LIMIT 1000000
#define PRIME_COUNT 78498

#define COMPOSITED_PRIME_LIMIT 10000000

int is_prime[PRIME_LIMIT];
int prime_table[PRIME_COUNT];

void init_prime() {
    for (int i = 0; i < PRIME_LIMIT; i++) {
        is_prime[i] = 1;
    }

    is_prime[0] = 0;
    is_prime[1] = 0;

    for (int i = 2; i < PRIME_LIMIT; i++) {
        if (!is_prime[i])
            continue;

        for (int j = i * 2; j < PRIME_LIMIT; j += i)
            is_prime[j] = 0;
    }

    for (int i = 0, p_i = 0; i < PRIME_LIMIT; i++)
        if(is_prime[i])
            prime_table[p_i++] = i;
}

int composited_prime[PRIME_LIMIT];
int composited_prime_count = 0;

int is_composited_number(int n) {
    for(int i = 0; i < PRIME_COUNT && prime_table[i] * prime_table[i] <= n; i++)
        if (((n % prime_table[i]) == 0) && ((n / prime_table[i]) != 1))
            return 1;
    
    return 0;
}

int get_digit_count(int n) {
    int result = 0;

    while (n != 0) {
        result += 1;
        n /= 10;
    }

    return result;
}

int get_pow_10(int n) {
    int result = 1;

    for (int i = 0; i < n; i++)
        result *= 10;

    return result;
}

int check_composited_prime(int candidate) {
    if (!is_composited_number(candidate))
        return 0;

    int digit_count = get_digit_count(candidate);
    int flag = 1;

    for (int i = 1; i < digit_count; i++) {
        for (int j = (i == digit_count - 1) ? 1 : 0; j <= i - 1; j++) {
            int part = (candidate % get_pow_10(i + 1)) / get_pow_10(j);

            if (part == 0)
                continue; 

            if (!is_prime[part]) {
                flag = 0;
                break;
            }
        }

        if (!flag)
            break;
    }

    return flag;
}

void init_composited_prime() {
    for (int i = 0; i < PRIME_LIMIT; i++)
        composited_prime[i] = 0;

    for (int candidate = 100, cp_index = 0; candidate < COMPOSITED_PRIME_LIMIT; candidate++) {
        if (check_composited_prime(candidate)) {
            composited_prime[cp_index++] = candidate;
            composited_prime_count++;
        }
    }
}

int main() {
    init_prime();
    init_composited_prime();

    int T; scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int c; scanf("%d", &c);

        int max = -1;
        for (int j = 0; j < composited_prime_count; j++) {
            if (composited_prime[j] > c) {
                max = (j - 1 != -1) ? composited_prime[j] : -1;
                break; 
            }
        }

        printf("%d\n", max);
    }
}