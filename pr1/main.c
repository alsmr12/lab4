/*#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
#include <readline/readline.h>

int main() {
    int t;
    char *str = readline("> ");
    t = str_func(&str);
//  t = str_insert(&str, '0', 0);
    printf("\n%s", str);
    free(str);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <readline/readline.h>

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
