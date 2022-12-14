#include <stdio.h>
#include <stdlib.h>
#include "func1.h"

char *func(const char *str) {
    char *s = my_strdup(str);
    int s_len = my_strlen(s);
    char *res = (char *)calloc((2 * (s_len + 1)), sizeof(char));
    int len = 0, q = 0; // q - для strtok
    char *word = my_strtok(s, " \t", &q);
    int w_len = 0;
    while (word != NULL) {
        w_len = my_strlen(word);	
        if (w_len > 0) {
            my_memcpy(res + len, word, w_len * sizeof(char));
            len += w_len;
            res[len] = ' ';
            ++len;
            if (w_len % 2 == 0) {
                my_memcpy(res + len, word, w_len * sizeof(char));
                len += w_len;
                res[len] = ' ';
                ++len;
            }
        }
        word = my_strtok(s, " \t", &q);
    }
    free(s);
    if (len > 0) {
        --len;
    }
    res[len] = '\0';
    res = (char *)realloc(res, (len + 1) * sizeof(char));
    return res;
}
