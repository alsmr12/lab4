#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
    int t;
    char *str = (char *)malloc(80 * sizeof(char));
    //str[0] = '0';
    //str[0] = '0';
    t = str_input(&str);
    t = str_func(&str);
    //t = str_insert(&str, '0', 0);
    //t = my_strlen(str);
    //printf("%d\n", t);
    printf("%s", str);
    //printf("\n");
    free(str);
    return 0;
}
