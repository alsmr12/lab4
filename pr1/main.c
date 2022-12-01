#include <stdio.h>
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
}
