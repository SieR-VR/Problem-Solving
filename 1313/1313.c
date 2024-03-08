#include <stdio.h>

int composited_prime[] = {
    111, 
    117, 
    119, 
    171, 
    231, 
    237, 
    297, 
    319, 
    371, 
    411, 
    413, 
    417, 
    437, 
    471, 
    473, 
    531, 
    537, 
    597, 
    611, 
    671, 
    679, 
    711, 
    713, 
    717, 
    731, 
    737, 
    831, 
    837, 
    897, 
    973, 
    979, 
    1131, 
    1137, 
    1311, 
    1313, 
    1317, 
    1379, 
    1797, 
    1971, 
    3113, 
    3131, 
    3173, 
    3179, 
    4197, 
    4311, 
    4313, 
    4317, 
    4797, 
    6137, 
    6179, 
    7197, 
    7971, 
    31373, 
};
int composited_prime_count = 53;

int binary_search(int n) {
    if (n < composited_prime[0])
        return -1;

    if (n >= composited_prime[composited_prime_count - 1])
        return composited_prime[composited_prime_count - 1];

    int low = 0, high = composited_prime_count - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (n < composited_prime[mid]) {
            high = mid - 1;
        }
        else if (n > composited_prime[mid]) {
            low = mid + 1;
        } else {
            return composited_prime[mid];
        }
    }

    return composited_prime[high];
}

int main() {
    int T; scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int c; scanf("%d", &c);
        printf("%d\n", binary_search(c));
    }
}
