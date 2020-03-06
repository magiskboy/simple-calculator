/*
 * Stack implemented follow single link list
 */

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 10000

struct Node {
    char* data;
    struct Node* next;
};

struct Stack {
    struct Node* head;
    unsigned size;
};

struct Stack* init_stack(void);

struct Node* push_stack(struct Stack*, char*);  // Add one element into head stack

struct Node* pop_stack(struct Stack*);    // delete element from top stack, return point of Node

struct Node* get_top_stack(struct Stack*);    // get top element stack

unsigned short is_empty_stack(struct Stack*);  // return 1 if stack is empty, else return 0

unsigned short is_full_stack(struct Stack*);   // return 1 if stack is full, else return 0

unsigned get_size_stack(struct Stack*);    // get size of stack

#endif
