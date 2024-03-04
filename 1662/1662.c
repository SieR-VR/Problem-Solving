#include <stdio.h>
#include <stdlib.h>

int length(const char *s, int *pos, int end) {
    int result = 0;

    while (s[*pos + 1] != '\0' && s[*pos + 1] != '(') {
        result++;
        (*pos)++;
    }

    if (s[*pos + 1] == '\0')
        return result;

    if (s[*pos + 1] == '(') {
        int repeat = s[*pos] - '0';
        (*pos)++; (*pos)++;

        result += repeat * length(s, pos);
        (*pos)++; // ignore ')' checking
    }

    if (s[*pos + 1] == '\0')
        return result;
    else 
        return result + length(s, pos);
}
 
int main() {
    char s[64]; scanf("%s", s);

    int pos = 0;
    int result = length(s, &pos);

    printf("%d\n", result);
}
