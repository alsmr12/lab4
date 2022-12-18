#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#include "func.h"

int main() { 
    char *input = readline("> ");
    char *output;
    while (input != NULL) {
        printf("\"%s\"\n", input);
        output = func(input);
        printf("\"%s\"\n", output);
        free(input);
        free(output);
        input = readline("> ");
    }
    return 0;
}
