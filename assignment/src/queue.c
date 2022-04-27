#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

int empty(struct queue_t *q) { return (q->size == 0); }

void enqueue(struct queue_t *q, struct pcb_t *proc) {
  /* TODO: put a new process to queue [q] */
  if (q->size == MAX_QUEUE_SIZE) {
    return;
  }
  q->proc[q->size++] = proc;
}

struct pcb_t *dequeue(struct queue_t *q) {
  /* TODO: return a pcb whose prioprity is the highest
   * in the queue [q] and remember to remove it from q
   * */
  if (empty(q))
    return NULL;
  uint32_t max_priority = q->proc[0]->priority;
  int index = 0;
  for (int i = 0; i < q->size; i++) {
    if (max_priority < q->proc[i]->priority) {
      max_priority = q->proc[i]->priority;
      index = i;
    }
  }
  struct pcb_t *highest_priority_process = q->proc[index];
  for (int i = index; i < q->size - 1; i++) {
    q->proc[i] = q->proc[i + 1];
  }
  q->size--;
  return highest_priority_process;
}
