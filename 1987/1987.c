#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct {
  int row;
  int column;
} pos_t;

int r, c;
int moving_matrix[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

int max_len = 0;

void recurse(char board[21][21], int visited[26], pos_t *pos, int dist_length) {
  visited[board[pos->row][pos->column] - 'A'] = 1;
  if (dist_length > max_len) max_len = dist_length;

  for (int i = 0; i < 4; i++) {
    pos->row += moving_matrix[i][0];
    pos->column += moving_matrix[i][1];

    if (
        (0 <= pos->row && pos->row < r) &&
        (0 <= pos->column && pos->column < c) &&
        (!visited[board[pos->row][pos->column] - 'A'])
    ) {
        recurse(board, visited, pos, dist_length + 1);
    }
    
    pos->row -= moving_matrix[i][0];
    pos->column -= moving_matrix[i][1];
  }

  visited[board[pos->row][pos->column] - 'A'] = 0;
}

int main() {
  scanf("%d %d", &r, &c);

  char board[21][21];
  int visited[26];

  for (int i = 0; i < r; i++)
    scanf("%s", board[i]);

  for (int i = 0; i < 26; i++)
    visited[i] = 0;

  pos_t pos = {0, 0};
  recurse(board, visited, &pos, 1);
  printf("%d\n", max_len);
}
