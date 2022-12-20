#include <stdio.h>
#include <stdlib.h>

#include "func.h"
#include "func1.h"

int main() {
    char *input = my_readline("> ");
    char *output;
    while (input != NULL) {
        printf("\"%s\"\n", input);
        output = func(input);
        printf("\"%s\"\n", output);
        free(input);
        free(output);
        input = my_readline("> ");
    }
    return 0;
}
