#include <stdio.h>
#include <stdlib.h>

#define MAX_POSITION 150000
int min_time[MAX_POSITION];

typedef struct deque_node_t {
    int time;
    int position;

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

deque_node_t *make(int time, int position) {
    deque_node_t *result = (deque_node_t *)malloc(sizeof(deque_node_t));
    result->time = time;
    result->position = position;

    return result;
}

int check(int position) {
    if (0 > position || position >= MAX_POSITION)
        return 0;

    if (min_time[position] != -1)
        return 0;

    return 1;
}

int main() {
    for (int i = 0; i < MAX_POSITION; i++)
        min_time[i] = -1;

    int n, k; scanf("%d %d", &n, &k);

    deque_t *dq = (deque_t *)malloc(sizeof(deque_t));
    deque_node_t *first_node = (deque_node_t *)malloc(sizeof(deque_node_t));

    first_node->time = 0;
    first_node->position = n;

    first_node->next = NULL;
    first_node->prev = NULL;
    
    dq->first = first_node;
    dq->last = first_node;
    dq->size = 1;

    int curr_time = 0, curr_pos = -1;
    while (1) {
        deque_node_t *curr = dq_pop_front(dq);

        curr_time = curr->time;
        curr_pos = curr->position;
        free(curr);

        if (curr_pos == k) {
            break;
        }

        if (check(curr_pos * 2)) {
            min_time[curr_pos * 2] = curr_time;
            dq_push_front(dq, make(curr_time, curr_pos * 2));
        }
        if (check(curr_pos - 1)) {
            min_time[curr_pos - 1] = curr_time + 1;
            dq_push_back(dq, make(curr_time + 1, curr_pos - 1));
        }
        if (check(curr_pos + 1)) {
            min_time[curr_pos + 1] = curr_time + 1;
            dq_push_back(dq, make(curr_time + 1, curr_pos + 1));
        }
    }

    printf("%d\n", curr_time);
}