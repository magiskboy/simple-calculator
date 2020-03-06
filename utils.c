#include <stdio.h>
#include <string.h>
#include "utils.h"

char* OPERATORS_STR[] = {"+", "-", "*", "/"};
char* OP_1[] = {"+", "-"};
char* OP_2[] = {"*", "/"};
char* OP_UNARY[] = {};


unsigned short is_in(char* e, char** arr, unsigned n) {
    unsigned i;
    for (i = 0; i < n; ++i) {
        if (strcmp(e, arr[i]) == 0) return 1;
    }
    return 0;
}

unsigned short is_op(char* e) {
    int i;
    for (i = 0; i < 4; ++i) {
        if (strcmp(e, OPERATORS_STR[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


unsigned short get_level_op(char* e) {
    if (is_in(e, OP_1, 2)) {
        return 0;
    }
    else if (is_in(e, OP_1, 2)) {
        return 1;
    }
    else {
        return -1;
    }
}

unsigned short is_unary_op(char* e) {
    if (is_in(e, OP_UNARY, 0)) return 1;
    else return 0;
}
