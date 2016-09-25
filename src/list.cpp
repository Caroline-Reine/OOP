#include "list.h"

listnode *listnode_create(int val, char *key)
{
    listnode *p = new listnode;

    if (!p) return NULL;

    p->val = val;
    p->key = new char[strlen(key)];
    strcpy(p->key, key);

    return p;
}


listnode *listnode_add(listnode *root, int val, char *key)
{
    listnode *node = listnode_create(val, key);
    listnode *p = root;
    if (!node) return NULL;

    // If it's the first listnode
    if (!p) {
        return node;
    }

    // If root has already created
    for ( ; p->next != NULL; p = p->next);

    p->next = node;
    return root;
}


listnode *listnode_add_after(listnode *root, int val, char *key, int k)
{
    if (root == NULL) return listnode_add(root, val, key);

    if (k < 1) return NULL; // wrong index before

    listnode *p = root;

    int i;
    for (i = 1; (i != k) && (p->next != NULL); i++, p = p->next);
    if (i != k) return NULL; // wrong index after

    // if next node is null, then we push new node in the end
    if (p->next == NULL) {
        return root = listnode_add(root, val, key);
    } else { // we push node in mid
        listnode *ptemp = p->next;
        listnode *node = listnode_create(val, key);
        if (!node) return NULL;
        p->next = node;
        p->next->next = ptemp;
    }
    return root;
}

listnode *listnode_delete(listnode *root, int k)
{
    listnode *p = root;
    listnode *prev, *next;
    if (!p) return NULL;
    if (k < 1) return NULL;

    int i;
    for (i = 1; (i != k) && (p->next != NULL); i++, p = p->next) {
        prev = p;
    }

    if (i != k) return NULL;

    if (p == root) {
        root = p->next;
        free(p->key);
        free(p);
    } else if (p->next == NULL) { // end node
        free(p->key);
        free(p);
        prev->next = NULL;
    } else { // middle node
        next = p->next;
        free(p->key);
        free(p);
        prev->next = next;
    }
    return root;
}

listnode *listnode_move(listnode *root, int k, int p)
{
    if (k == p) return root;

    if (k > p) {
        int tmp = p;
        p = k;
        k = tmp;
    }

    if (p > listnode_count(root)) return NULL;

    listnode *node1 = root, *node2 = root, *prev1, *prev2;

    for (int i = 1; k != i; i++, node1 = node1->next) {
        prev1 = node1;
    }
    for (int i = 1; p != i; i++, node2 = node2->next) {
        prev2 = node2;
    }

    if (k == 1 && p == 2) {
        node1->next = node2->next;
        node2->next = node1;
        root = node2;
    } else if (k == 1) {
        listnode *p = node1->next;
        node1->next = node2->next;
        prev2->next = node1;
        node2->next = p;
        root = node2;
    } else if ((k + 1) == p) {
        node1->next = node2->next;
        prev1->next = node2;
        node2->next = node1;
    } else {
        listnode *p = node1->next;
        prev1->next = node2;
        prev2->next = node1;
        node1->next = node2->next;
        node2->next = p;
    }
    return root;
}

int listnode_count(listnode *root)
{
    listnode *p = root;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

void listnode_print(listnode *root)
{
    listnode *p = root;
    while (p) {
        cout << p->key << " " << p->val << endl;
        p = p->next;
    }
}
