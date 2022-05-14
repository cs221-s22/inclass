#include <stdio.h>
#include <stdlib.h>

struct foo {
    int i;
    char buf[32];
    struct foo *next; // singly linked list
};

int main(int argc, char *argv[]) {
    struct foo *head = malloc(sizeof(struct foo));
    if (!head) {
        printf("malloc failed\n");
        exit(-1);
    }

    head->i = 0;
    head->next  = malloc(sizeof(struct foo));
    head->next->i = 99;
    head->next->next = NULL;

    struct foo *new_node = malloc(sizeof(struct foo));
    struct foo *prev = head;

    new_node->next = prev->next;
    prev->next = new_node;
    
    return 0;    
}

