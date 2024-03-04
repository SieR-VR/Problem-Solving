#include <stdio.h>
#include <stdlib.h>

int compare(const void *left, const void *right) {
    if (*(const int*)left > *(const int*) right) {
        return 1;
    }
    else if (*(const int*)left < *(const int*)right) {
        return -1;
    }
    else {
        return 0;
    }
}

int int_round(int n, int m) {
    return n / m + ((n % m) >= (m / 2));
}

int main() {
    int n; scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int excluded = int_round(n * 15, 100);

    int sum = 0;
    for (int index = excluded; index < n - excluded; index++) {
        sum += arr[index];
    }

    int result = int_round((sum * 10) / (n - (excluded * 2)), 10);
    printf("%d\n", result);
}
