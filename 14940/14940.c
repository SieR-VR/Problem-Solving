#include <stdio.h>
#include <stdlib.h>

int n, m;
int start_h, start_v;

int *ref_matrix(int *map, int h, int v) {
    return &map[h * m + v];
}

typedef struct deque_node_t {
    int dist;
    int h_index;
    int v_index;

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

deque_node_t *make(int dist, int h_index, int v_index) {
    deque_node_t *result = (deque_node_t *)malloc(sizeof(deque_node_t));
    result->dist = dist;
    result->h_index = h_index;
    result->v_index = v_index;

    return result;
}

int check(int *map, int *visited_map, int dist, int h_index, int v_index) {
    if (h_index < 0 || h_index >= n)
        return 0;
    
    if (v_index < 0 || v_index >= m)
        return 0;

    if (*ref_matrix(map, h_index, v_index) == 0)
        return 0;

    if (*ref_matrix(visited_map, h_index, v_index) <= dist)
        return 0;

    return 1;
}

int main() {
    scanf("%d %d", &n, &m);

    int *map = (int *)malloc(sizeof(int) * m * n);
    int *visited_map = (int *)malloc(sizeof(int) * m * n);

    for (int i = 0; i < n * m; i++)
        visited_map[i] = 2000000;

    for (int h_index = 0; h_index < n; h_index++) {
        for (int v_index = 0; v_index < m; v_index++) {
            scanf("%d", ref_matrix(map, h_index, v_index));
            if (*ref_matrix(map, h_index, v_index) == 2) {
                start_h = h_index;
                start_v = v_index;
            }
            if (*ref_matrix(map, h_index, v_index) == 0) {
                *ref_matrix(visited_map, h_index, v_index) = 0;
            }
        }
    }

    deque_t *dq = (deque_t *)malloc(sizeof(deque_t));
    deque_node_t *first_node = (deque_node_t *)malloc(sizeof(deque_node_t));

    first_node->dist = 0;
    first_node->v_index = start_v;
    first_node->h_index = start_h;

    first_node->next = NULL;
    first_node->prev = NULL;
    
    dq->first = first_node;
    dq->last = first_node;
    dq->size = 1;
    *ref_matrix(visited_map, start_h, start_v) = 0;

    int move_matrix[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
    while (dq->size)
    {
        deque_node_t *curr = dq_pop_front(dq);
        int curr_dist = curr->dist;
        int curr_v = curr->v_index;
        int curr_h = curr->h_index;

        free(curr);

        for (int move_index = 0; move_index < 4; move_index++) {
            int new_h = curr_h + move_matrix[move_index][0];
            int new_v = curr_v + move_matrix[move_index][1];

            if (check(
                map, 
                visited_map, 
                curr_dist + 1, 
                new_h,
                new_v
            )) {
                *ref_matrix(visited_map, new_h, new_v) = curr_dist + 1;

                dq_push_back(
                    dq, 
                    make(
                        curr_dist + 1,
                        new_h,
                        new_v
                    )
                );
            }
        }
    }

    for (int h_index = 0; h_index < n; h_index++) {
        for (int v_index = 0; v_index < m; v_index++) {
            int result = *ref_matrix(visited_map, h_index, v_index);
            printf("%d ", result == 2000000 ? -1 : result);
        }
        printf("\n");
    }
}
