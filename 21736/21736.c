#include <stdio.h>
#include <stdlib.h>

typedef struct deque_node_t {
    int row_index;
    int col_index;

    struct deque_node_t *next;
    struct deque_node_t *prev;
} deque_node_t;

typedef struct deque_t {
    deque_node_t *first;
    deque_node_t *last;

    int size;
} deque_t;

void dq_push_back(deque_t *dq, deque_node_t *node) {
    if (!dq->size) {
        dq->first = node;
        dq->last = node;

        node->prev = NULL;
        node->next = NULL;
        dq->size++;
        return;
    }

    node->next = NULL;
    node->prev = dq->last;

    dq->last->next = node;
    dq->last = node;
    dq->size++;
}

void dq_push_front(deque_t *dq, deque_node_t *node) {
    if (!dq->size) {
        dq->first = node;
        dq->last = node;

        node->prev = NULL;
        node->next = NULL;
        dq->size++;
        return;
    }

    node->prev = NULL;
    node->next = dq->first;

    dq->first->prev = node;
    dq->first = node;
    dq->size++;
}

deque_node_t *dq_pop_back(deque_t *dq) {
    if (dq->size == 0)
        return NULL;

    if (dq->size == 1) {
        deque_node_t *result = dq->first;
        dq->first = NULL;
        dq->last = NULL;
        dq->size = 0;

        return result;
    }

    deque_node_t *result = dq->last;
    dq->last = result->prev;
    dq->last->next = NULL;
    dq->size--;

    return result;
}

deque_node_t *dq_pop_front(deque_t *dq) {
    if (dq->size == 0)
        return NULL;

    if (dq->size == 1) {
        deque_node_t *result = dq->first;
        dq->first = NULL;
        dq->last = NULL;
        dq->size = 0;

        return result;
    }

    deque_node_t *result = dq->first;
    dq->first = result->next;
    dq->first->prev = NULL;
    dq->size--;

    return result;
}

deque_node_t *make(int row_index, int col_index) {
    deque_node_t *result = (deque_node_t *)malloc(sizeof(deque_node_t));
    result->col_index = col_index;
    result->row_index = row_index;

    return result;
}

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    char campus[n][m];
    unsigned char visited[n][m];

    int start_row, start_col;

    for (int i = 0; i < n; i++) {
        char temp[1024]; scanf("%s", temp);
        for (int j = 0; j < m; j++) {
            campus[i][j] = temp[j];
            visited[i][j] = 0;

            if (temp[j] == 'I') {
                start_row = i;
                start_col = j;
            }
        }
    }

    deque_t *dq = malloc(sizeof(deque_t));
    deque_node_t *first_node = make(start_row, start_col);

    first_node->next = NULL;
    first_node->prev = NULL;

    dq->first = first_node;
    dq->last = first_node;
    dq->size = 1;

    visited[start_row][start_col] = 1;

    int moving_matrix[4][2] = {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };

    int meet = 0;

    while (dq->size) {
        deque_node_t *node = dq_pop_front(dq);
        int curr_row = node->row_index;
        int curr_col = node->col_index;

        if (campus[curr_row][curr_col] == 'P')
            meet++;

        for (int i = 0; i < 4; i++) {
            int new_row = curr_row + moving_matrix[i][0];
            int new_col = curr_col + moving_matrix[i][1];

            if (
                0 <= new_row &&
                new_row < n &&
                0 <= new_col &&
                new_col < m &&
                (!visited[new_row][new_col]) &&
                (campus[new_row][new_col] != 'X')
            ) {
                visited[new_row][new_col] = 1;
                dq_push_back(dq, make(new_row, new_col));
            }
        }
    }

    if (meet == 0) {
        printf("TT\n");
    } else {
        printf("%d\n", meet);
    }
}