#include <stdio.h>

int main() {
    int n; scanf("%d", &n);

    char files[n][64];
    for (int i = 0; i < n; i++) {
        scanf("%s", files[i]);
    }

    int len = 0;
    for (;files[0][len] != '\0'; len++);

    char result[64];
    result[len] = '\0';

    for (int i = 0; i < len; i++) {
        char common = files[0][i];
        result[i] = common;

        for (int j = 1; j < n; j++) {
            if (common != files[j][i]) {
                result[i] = '?';
                break;
            }
        }
    }

    printf("%s\n", result);
}
