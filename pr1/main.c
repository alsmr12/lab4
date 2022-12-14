#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <readline/readline.h>

int main() { 
    char *input = readline("> ");	
    char *input = "qw erty ui iop"; 
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
