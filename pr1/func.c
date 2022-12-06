#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include <readline/readline.h>

/*
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
}*/

char *func(const char *str) {
    char *s = strdup(str);
    int s_len = strlen(s);
    char *res = (char *)calloc((2 * s_len + 1), sizeof(char));
    int len = 0;
    char *word = strtok(s, " \t");
    int w_len = 0;
    while (word != NULL) {
        //printf("Word: \"%s\"\n", word);
        w_len = strlen(word);
        if (w_len > 0) {
            memcpy(res + len, word, (w_len) * sizeof(char));
            len += w_len;
            res[len] = ' ';
            ++len;
            if (w_len % 2 == 0) {
                memcpy(res + len, word, (w_len) * sizeof(char));
                len += w_len;
                res[len] = ' ';
                ++len;
            }
        }
        //printf("Result: \"%s\"\n", res);
        word = strtok(NULL, " \t");
    }
    free(s);
    if (len > 0) {
        --len;
    }
    res[len] = '\0';
    res = realloc(res, (len + 1) * sizeof(char));
    return res;
}
