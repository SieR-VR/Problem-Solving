#include <stdio.h>
#define MIN(x, y) (((x) > (y)) ? (y) : (x))

int bit_count(int i) {
    i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
    i = (i & 0x00FF00FF) + ((i >> 8) & 0x00FF00FF);
    i = (i & 0x0000FFFF) + ((i >> 16) & 0x0000FFFF);

    return i;
}

int main() {
    int dist_table[1 << 4][1 << 4];
    for (int first = 0; first < (1 << 4); first++) {
        for (int second = 0; second < (1 << 4); second++) {
            dist_table[first][second] = bit_count(first ^ second);
        }
    }

    int t; scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n; scanf("%d", &n);
        
        int people[n];
        for (int p_i = 0; p_i < n; p_i++) {
            char temp[5]; scanf("%s", temp);
            people[p_i] =
                (temp[0] == 'E') << 3 |
                (temp[1] == 'S') << 2 |
                (temp[2] == 'T') << 1 |
                (temp[3] == 'J') << 0;
        }

        if (n > 32) {
            printf("0\n");
            continue;
        }

        int dist_max = 16;

        for (int first = 0; first < n; first++) {
            for (int second = first + 1; second < n; second++) {
                for (int third = second + 1; third < n; third++) {
                    dist_max = MIN(dist_max, 
                        dist_table[people[first]][people[second]] +
                        dist_table[people[second]][people[third]] +
                        dist_table[people[third]][people[first]]
                    );
                }
            }
        }

        printf("%d\n", dist_max);
    }
}
