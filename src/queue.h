#include <stdlib.h>
#include "list.h"

typedef struct queue {
    struct listnode *head;
    struct listnode *tail;
    int size;
}queue;


queue *queue_create();
int queue_size(queue *q);
void queue_enqueu(queue *s, int val, char *key);
void queue_free(queue *s);
listnode *queue_dequeue(queue *q);
