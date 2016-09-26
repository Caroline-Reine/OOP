#include <iostream>
#include "list.h"

int main(int argc, char const *argv[])
{
    listnode *p = listnode_add(p, 10, (char*) "test");
    listnode_add(p, 1, (char*) "mooor");
    listnode_add_after(p, 3, (char *) "wolf", 2);
    p = listnode_move(p, 1, 3);
    p = listnode_add_after(p, 3, (char *) "listnode_delete", 2);
    listnode_print(p);
    cout << endl << "\t\tStack" << endl;
    printStack(p);
    return 0;
}
