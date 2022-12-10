#include <stdio.h>
#include <stdlib.h>
//#include "func.h"
#include "my_string_func.h"

int main() {
    int t;
    char *str = (char *)malloc(80 * sizeof(char));
    scanf("%80[^\n]", str);
    printf("len = %d", my_strlen(str));
    int q = 0;
    char *word = my_strtok(str, " \t", &q);
    printf("\n%s", word);
    free(str);
    return 0;
}
