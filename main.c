#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bc.h"

int main(int argc, char** argv) {
    char* expression = malloc(sizeof(char) * 100);
    char* result = malloc(sizeof(char) * 30);
    scanf("%s", expression);
    cal(expression, result);
    printf("%s\n", result);
    
    return 0;
}
