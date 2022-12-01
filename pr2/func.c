#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int str_input(char **str) {
    scanf("%80[^\n]", *str);
    return 0;
}

int my_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int str_func(char **str) {
    int len = my_strlen(*str);
    int c, begin, end, t, i = 0;
    while (i < len)  {
        c = 0;
        begin = i;
        while (((*str)[i] != ' ') && (i != len)) {
            c = c + 1;
            i = i + 1;
        }
        if (i == len) {
            t = str_insert(str, ' ', i);
            len = len + 1;
        }
        end = i;
        if ((c % 2 == 0) && (c != 0)) {
            for (int j = end; j >= begin; j--) { 
                t = str_insert(str, (*str)[j], end + 1);
                len = len + 1;
            }
            i = i + end - begin + 1;
        }
        i = i + 1;
    }
}

int str_insert(char **str, char a, int n) {
    int len = my_strlen(*str); 
    char *str1 = (char *)malloc((len + 2) * sizeof(char));
    for (int k = 0; k < len; ++k) {
        str1[k] = (*str)[k];
    }
    free(*str);
    *str = str1;
    len = len + 1;
    for (int j = len - 1; j > n; --j) {
        (*str)[j] = (*str)[j-1];
    }
    (*str)[n] = a;
    return 0;
}
