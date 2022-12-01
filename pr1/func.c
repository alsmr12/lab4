#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include <readline/readline.h>

//int str_input(char **str) {
//    *str = readline("> ");
//    while (*str == NULL) {
//        printf("Некорректно. Повторите.\n");
//        free(*str);
//        *str = readline("> ");
//    }
//    return 0;
//}

int str_func(char **str) {
    int c, begin, end, t, i = 0;
    while (i < strlen(*str))  {
        c = 0;
        begin = i;
        while (((*str)[i] != ' ') && (i != strlen(*str))) {
            c = c + 1;
            i = i + 1;
        }
        if (i == strlen(*str)) {
            t = str_insert(str, ' ', i);
        }
        end = i;
        if ((c % 2 == 0) && (c != 0)) {
            for (int j = end; j >= begin; j--) {
                t = str_insert(str, (*str)[j], end + 1);
            }
            i = i + end - begin + 1;
        }
        i = i + 1;
    }
}

int str_insert(char **str, char a, int n) {
    char *str1 = (char *)malloc((strlen(*str) + 2) * sizeof(char));
   // for (int k = 0; k <= strlen(*str); ++k) {
   //     str1[k] = (*str)[k];
   // }
    str1 = strcpy(str1, *str);
    free(*str);
    *str = str1;
    for (int j = strlen(*str) + 1; j > n; --j) {
        (*str)[j] = (*str)[j-1];
    }
    (*str)[n] = a;
    return 0;
}
