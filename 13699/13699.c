#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    ll arr[36];
    arr[0] = 1;

    for (int i = 1; i <= 35; i++) {
        arr[i] = 0;

        for (int j = 0; j < i; j++) {
            arr[i] += arr[i - j - 1] * arr[j];
        }
    }

    int n;

    scanf("%d", &n);
    printf("%lld\n", arr[n]);
}
