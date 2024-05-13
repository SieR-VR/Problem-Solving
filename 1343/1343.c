#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main() {
    char board[64]; scanf("%s", board);
    char buf[64];

    int len = strlen(board);

    int x_stroke = 0, dot_stroke = 0, flag = 0, pivot = 0;
    for (int i = 0; i <= len; i++) {
        if (board[i] == '.') {
            if (x_stroke) {
                if (x_stroke & 0x01) {
                    flag = 1;
                    break;
                }

                for (int j = 0; j < (x_stroke - (x_stroke % 4)); j++) {
                    buf[pivot++] = 'A';
                }

                if (x_stroke % 4) {
                    buf[pivot++] = 'B';
                    buf[pivot++] = 'B';
                }

                x_stroke = 0;
            }

            dot_stroke++;
        }
        else if (board[i] == 'X') {
            if (dot_stroke) {
                for (int j = 0; j < dot_stroke; j++) {
                    buf[pivot++] = '.';
                }

                dot_stroke = 0;
            }

            x_stroke++;
        } else if (board[i] == '\0') {
            if (dot_stroke) {
                for (int j = 0; j < dot_stroke; j++) {
                    buf[pivot++] = '.';
                }

                dot_stroke = 0;
            }
            if (x_stroke) {
                if (x_stroke & 0x01) {
                    flag = 1;
                    break;
                }

                for (int j = 0; j < (x_stroke - (x_stroke % 4)); j++) {
                    buf[pivot++] = 'A';
                }

                if (x_stroke % 4) {
                    buf[pivot++] = 'B';
                    buf[pivot++] = 'B';
                }

                x_stroke = 0;
            }
        }
    }


    if (flag) {
        printf("-1\n");
    } else {
        buf[pivot] = '\0';
        printf("%s\n", buf);
    }
}