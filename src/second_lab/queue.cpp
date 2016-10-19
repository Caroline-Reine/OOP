#include "queue.h"

void init(struct queue *q) {
  q->frnt = 1;
  q->rear = 0;
  return;
}

void insert(struct queue *q, int x) {
  if(q->rear < QMAX-1) {
    q->rear++;
    q->qu[q->rear]=x;
  }
  else
    printf("Queue is FULL\n");
  return;
}

int isempty(struct queue *q) {
  if(q->rear < q->frnt)    return(1);
  else  return(0);
}

void print(struct queue *q) {
  int h;
  if(isempty(q)==1) {
    printf("Queue is empty\n");
    return;
  }
  for(h = q->frnt; h<= q->rear; h++)
    printf("%d ",q->qu[h]);
  return;
}

int removex(struct queue *q) {
  int x, h;
  if(isempty(q)==1) {
    printf("Queue is empty\n");
    return(0);
  }
  x = q->qu[q->frnt];
  for(h = q->frnt; h < q->rear; h++) {
    q->qu[h] = q->qu[h+1];
  }
  q->rear--;
  return(x);
}
