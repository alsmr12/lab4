#include <stdio.h>
#include <stdlib.h>
//#include "func.h"
#include "func1.h"

int main() {	
    int t;
    char *str = (char *)malloc(80 * sizeof(char));
    scanf("%80[^\n]", str);
    int len_str = my_strlen(str);
    int q = 0;
    char *word;
    while(q != len_str) {
        word = my_strtok(str, " \t", &q);
        printf("\n   %s", word);
    }
    printf("\n\n Программа завершена\n\n");
    free(str);
    return 0;
}
