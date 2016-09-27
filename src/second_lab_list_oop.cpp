#include <iostream>
#include <cmath>
#include "list.h"
#include "stack.h"
#include "queue.h"
#define n 10

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int *mass = new int[n];
    for (int i = 0; i < n; i++) {
        mass[i] = random() % 50;
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

    stack_push(s, 1, (char *) "lol");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "l23ol");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "l3ol");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "lo4l");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "l5ol");
    cout << "stack push" << endl;
    stack_print(s);
    stack_push(s, 1, (char *) "lo6l");
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

    queue *q = queue_create();
    cout << "Create queue" << endl;
    listnode_print(q->head);

    queue_enqueu(q, 1, (char *) "FUCK");
    cout << "Push queue" << endl;
    listnode_print(q->head);
    queue_enqueu(q, 12, (char *) "Good");
    cout << "Push queue" << endl;
    listnode_print(q->head);

    return 0;
}
