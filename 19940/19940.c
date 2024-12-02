#include <stdio.h>
#include <stdlib.h>

typedef struct deque_node_t {
  int addh, addt, mint, addo, mino;
  int count, pos;

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

deque_node_t *make(int addh, int addt, int mint, int addo, int mino, int pos) {
  deque_node_t *result = (deque_node_t *)malloc(sizeof(deque_node_t));
  result->addh = addh;
  result->addt = addt;
  result->mint = mint;
  result->addo = addo;
  result->mino = mino;

  result->pos = pos;
  result->count = addh + addt + mint + addo + mino;
  return result;
}

int main() {
  int T; scanf("%d", &T);

  for (int it = 0; it < T; it++) {
    int N; scanf("%d", &N);
    int visited[3600];

    for (int i = 0; i < 3600; i++) {
      visited[i] = 0;
    }

    int min_addh = N / 60;
    int correction = min_addh * 60 - 1800;

    deque_t *dq = (deque_t *)malloc(sizeof(deque_t));
    deque_node_t *first_node = make(min_addh, 0, 0, 0, 0, min_addh * 60);

    first_node->next = NULL;
    first_node->prev = NULL;

    dq->first = first_node;
    dq->last = first_node;
    dq->size = 1;

    int addh, addt, mint, addo, mino;
    while (1) {
      deque_node_t *curr = dq_pop_front(dq);
      addh = curr->addh;
      addt = curr->addt;
      mint = curr->mint;
      addo = curr->addo;
      mino = curr->mino;

      if (curr->pos == N) {
        break;
      }

      if (!visited[curr->pos - correction + 60]) {
        dq_push_back(dq, make(addh + 1, addt, mint, addo, mino, curr->pos + 60));
      }
      if (!visited[curr->pos - correction + 10]) {
        dq_push_back(dq, make(addh, addt + 1, mint, addo, mino, curr->pos + 10));
      }
      if (!visited[curr->pos - correction - 10]) {
        dq_push_back(dq, make(addh, addt, mint + 1, addo, mino, curr->pos - 10));
      }
      if (!visited[curr->pos - correction + 1]) {
        dq_push_back(dq, make(addh, addt, mint, addo + 1, mino, curr->pos + 1));
      }
      if (!visited[curr->pos - correction - 1]) {
        dq_push_back(dq, make(addh, addt, mint, addo, mino + 1, curr->pos - 1));
      }
    }

    printf("%d %d %d %d %d\n", addh, addt, mint, addo, mino);
  }
}
