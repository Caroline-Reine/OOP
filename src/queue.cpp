#include "queue.h"


queue *queue_create()
{
    queue *q = (queue *) malloc(sizeof(*q));

    if (q) {
        q->size = 0;
        q->head = NULL;
        q->tail = NULL;
    }
    return q;
}

int queue_size(queue *q)
{
    return q->size;
}

void queue_enqueu(queue *q, int val, char *key)
{
    if (q->head == NULL) {
        q->head = listnode_create(val, key);
        q->tail = q->head;
    } else {
        q->tail->next = listnode_create(val, key);
        q->tail = q->tail->next;
    }
    q->size++;
}

listnode *queue_dequeue(queue *q)
{
    if (q->size == 0) return NULL;
    listnode *get = q->head;
    q->head = q->head->next;
    q->size--;
    return get;
}

void queue_free(queue *s)
{
    listnode *del;

    while(s->size) {
        del = queue_dequeue(s);
        free(del->key);
        free(del);
    }
    free(s);
}
