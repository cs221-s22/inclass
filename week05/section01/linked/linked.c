#include <stdio.h>
#include <stdlib.h>

// linked list example node

struct node {
    int value;
    struct node *next;
};

void print_nodes(struct node *pnode) {
    while (pnode) {
        // walk the list, printing each node's value
        printf("node: %p, value: %d\n", pnode, pnode->value);
        pnode = pnode->next;
    }
}

int main(int argc, char **argv) {
    struct node *prev = NULL;
    struct node *head = NULL;
    
    for (int i = 0; i < 5; i++) {
        struct node *pnode = malloc(sizeof(struct node));
        pnode->value = i;
        if (prev) {
            // second node or later
            prev->next = pnode;
        } else {
            // first node is the head of the list
            head = pnode;
        }
        prev = pnode;  // keep prev to fill in its next
    }

    print_nodes(head);
}
