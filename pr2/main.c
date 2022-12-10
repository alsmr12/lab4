#include <stdio.h>
#include <stdlib.h>
//#include "func.h"
#include "func1.h"

int main() {
    int t;
    char *str = (char *)malloc(80 * sizeof(char));
    scanf("%80[^\n]", str);
    int q = 0;
    char *word = my_strtok(str, " \t", &q);
    printf("\n 1  %s", word);
    word = my_strtok(str, " \t", &q);
    printf("\n 2  %s", word);
    word = my_strtok(str, " \t", &q);
    printf("\n 3  %s", word);
    free(str);
    return 0;
}
