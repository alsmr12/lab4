#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "func.h"

char *func(const char *str) {
    char *s = strdup(str);
    int s_len = strlen(s);
    char *res = (char *)malloc((2 * s_len + 2) * sizeof(char));
    int len = 0, w_len = 0;
    char *word = strtok(s, " \t");
    int q;
    while (word != NULL) {
        w_len = strlen(word);
        if (w_len % 2 == 0) q = 2;
        else q = 1;
	    for (int i = 0; i < q; i++) {
            memcpy(res + len, word, w_len * sizeof(char));
            len += w_len;
            res[len] = ' ';
            ++len;
	    }
        word = strtok(NULL, " \t");
    }
    free(s);
    if (len > 0) {
        --len;
    }
    res[len] = '\0';
    res = (char *)realloc(res, (len + 1) * sizeof(char));
    return res;
}
