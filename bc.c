#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bc.h"
#include "stack.h"
#include "utils.h"


void __to_polish_notation(char* expression, char** result, unsigned int* n) {
    char* tok;
    struct Stack* temp_st = init_stack();
    int i = 0;

    tok = strtok(expression, " ");
    while (tok != NULL) {
        if (is_op(tok)) {
            struct Node* o = get_top_stack(temp_st);
            if (o != NULL) {
                if (get_level_op(o->data) >= get_level_op(tok)) {
                    result[i] = malloc(sizeof(char) * 50);
                    strcpy(result[i++], o->data);
                    pop_stack(temp_st);
                }
            }
            push_stack(temp_st, tok);
        }
        else if (strcmp(tok, "(") == 0) {
            push_stack(temp_st, tok);
        }
        else if (strcmp(tok, ")") == 0) {
            while (!is_empty_stack(temp_st)) {
                if (strcmp(get_top_stack(temp_st)->data, "(") != 0) {
                    result[i] = malloc(sizeof(char) * 50);
                    strcpy(result[i++], pop_stack(temp_st)->data);
                }
            }
            pop_stack(temp_st);
        }
        else {
            result[i] = malloc(sizeof(char) * 50);
            strcpy(result[i++], tok);
        }
        tok = strtok(NULL, " ");
    }
    while (!is_empty_stack(temp_st)) {
        struct Node* o = pop_stack(temp_st);
        if (o != NULL) {
            result[i] = malloc(sizeof(char) * 50);
            strcpy(result[i++], o->data);
        }
    }
    *n = i;
}


void cal(char* expression, char* result) {
    unsigned n = 0, i = 0;
    char* polish_no[100];
    struct Stack* temp_st = malloc(sizeof(struct Stack));
    double first, second;
    

    __to_polish_notation(expression, polish_no, &n);
    for (i = 0; i < n; ++i) {
        if (is_op(polish_no[i])) {
            if (is_unary_op(polish_no[i])) {
                first = atof(pop_stack(temp_st)->data);
            }  
            else {
                second = atof(pop_stack(temp_st)->data);
                first = atof(pop_stack(temp_st)->data);
                double r = 0.f;
                char str_r[50];
                if (strcmp(polish_no[i], "+") == 0) {
                    r = first + second;
                }
                else if (strcmp(polish_no[i], "-") == 0) {
                    r = first - second;
                }
                else if (strcmp(polish_no[i], "*") == 0) {
                    r = first * second;
                }
                else if (strcmp(polish_no[i], "/") == 0) {
                    r = first / second;
                }
                snprintf(str_r, 50, "%f", r);
                push_stack(temp_st, str_r);
            }
        }
        else {
            push_stack(temp_st, polish_no[i]);
        }
    }
    strcpy(result, pop_stack(temp_st)->data);
    double r = atof(result);
    if (r - (int)r == 0) {
        snprintf(result, 50, "%d", (int)r);    
    }
}
