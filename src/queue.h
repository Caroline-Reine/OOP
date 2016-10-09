#include <stdlib.h>
#include <stdio.h>
#define QMAX 100

struct queue {
  int qu[QMAX];
  int rear, frnt;
};

void init(struct queue *q);
void insert(struct queue *q, int x);
int isempty(struct queue *q);
void print(struct queue *q);
int removex(struct queue *q);
