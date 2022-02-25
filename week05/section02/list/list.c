#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void print_nodes(struct node *pnode) {
    while (pnode) {
        printf("node: %p, value: %d\n", pnode, pnode->value);
        pnode = pnode->next;
    }
}

int main(int argc, char *argv[]) {
    struct node *head = NULL;
    struct node *prev = NULL;
    
    for (int i = 0; i < 5; i++) {
        struct node *pnode = malloc(sizeof(struct node));
        pnode->value = i;
        if (prev) {
            prev->next = pnode;
        } else {
            head = pnode;
        }
        prev = pnode;
    }

    print_nodes(head);

    while (head) {
        // save next ptr out of the block we're about to free
        struct node *next = head->next;

        // free one node struct
        free(head);

        // set up next ptr for loop iteration
        head = next;
    }
    
    return 0;
}
