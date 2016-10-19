#include <iostream>
#include <cmath>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include <cstdlib>
#include <ctime>

#define n 10


using namespace std;

int main(int argc, char const *argv[])
{
	system("chcp 1251 > nul");
    srand(time(NULL));
    int *mass = new int[n];
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 50;
        std::cout << mass[i] << endl;
    }
    std::cout << "\n";

    listnode *pl = NULL;

    for (int i = 0; i < n; i++) {
        pl = listnode_add_after(pl, mass[i], (char *) ("Luke, I'm your father"), i);
    }

    listnode *loop = pl;
    for (int i = 0; (i < n); i++, loop = loop->next) {
        listnode *node = listnode_find(loop->next, loop->val);
        if (node) listnode_delete_node(loop, node);
        if (loop->next == NULL) break;

    }

    stack *s = stack_create();
    stack_print(s);
    cout << "Stack is created" << endl;

    stack_push(s, 1, (char *) "p1");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "p2");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "p3");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "p4");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "p5");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "p6");
    cout << "stack push" << endl;
    stack_print(s);
    stack_pop(s);
    cout << "stack pop" << endl;
    stack_print(s);
    stack_pop(s);
    cout << "stack pop" << endl;
    stack_print(s);
    stack_pop(s);
    cout << "stack pop" << endl;
    stack_print(s);
    stack_pop(s);
    cout << "stack pop" << endl;
    stack_print(s);
    stack_free(s);

    struct queue *q;
    int a;
    q = (queue*) malloc(sizeof(queue));
    init(q);
    print(q);
    for(int i=0;i<8;i++) {
        printf("\nadd %d\n", i);
        insert(q, i);
        printf("Queue: ");
        print(q);
    }
    printf("\n");
    print(q);
    while(q->frnt <= q->rear) {
    a = removex(q);
    printf("\nDel. elem %d\n", a);
    print(q);
    }

    return 0;
}
