#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

extern int errno;


struct Stack* init_stack() {
    struct Stack* new_stack = malloc(sizeof(struct Stack));
    new_stack->head = NULL;
    new_stack->size = 0;

    return new_stack;
}


struct Node* push_stack(struct Stack* s, char* data) {
    if (is_full_stack(s)) {
        perror("Stack is fully");
        return NULL;
    }
    struct Node* new_node = NULL;
    new_node = malloc(sizeof(struct Node) * 1);
    if (new_node == NULL) {
        perror("New node allocate failure");
    }

    // Initial new node
    new_node->data = data;
    new_node->next = s->head;
    s->head = new_node;
    ++s->size;

    return new_node;
}


struct Node* pop_stack(struct Stack* s) {
    if (is_empty_stack(s)) return NULL;

    struct Node* remove_node = s->head;
    s->head = s->head->next;
    --s->size;
    return remove_node;
}


struct Node* get_top_stack(struct Stack* s) {
    return s->head;
}


unsigned short is_empty_stack(struct Stack* s) {
    return s->head == NULL;
}


unsigned short is_full_stack(struct Stack* s) {
    return s->size == STACK_MAX_SIZE - 1;
}


unsigned get_size_stack(struct Stack* s) {
    return s->size;
}
