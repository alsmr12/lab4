#include <stdio.h>
#include <stdlib.h>

#include "str.h"

char *func(const char *str) {
    char *s = my_strdup(str);
    int s_len = my_strlen(s);
    char *res = (char *)malloc((2 * s_len + 2) * sizeof(char));
    int len = 0, w_len = 0;
    char *word = my_strtok(s, " \t");
    int q;
    while (word != NULL) {
        w_len = my_strlen(word);
        if (w_len % 2 == 0) q = 2;
        else q = 1;
	for (int i = 0; i < q; i++) {
            my_memcpy(res + len, word, w_len * sizeof(char));
            len += w_len;
            res[len] = ' ';
            ++len;
	}
        word = my_strtok(NULL, " \t");
    }
    free(s);
    if (len > 0) {
        --len;
    }
    res[len] = '\0';
    res = (char *)realloc(res, (len + 1) * sizeof(char));
    return res;
}
