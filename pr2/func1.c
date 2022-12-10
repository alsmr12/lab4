#include <stdio.h>
#include <stdlib.h>
#include "my_string_func.h"

int my_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

char *my_strtok(char *string, char *delim, int *q) {
    int len_string = my_strlen(string);
    int len_delim = my_strlen(delim);
    char *word = (char *)malloc(len_string * sizeof(char));
    int k = 0;
    int c = 0;
    int i;
    for (i = 0; i < len_delim; i++) {
        if (string[*q] == delim[i]) c = 1;
    }
    while(c == 0) {
        word[i] = string[*q];
        ++i;
        ++q;
        for(i = 0; i < len_delim; i++) {
            if (string[*q] == delim[i]) c = 1;
        }
    }
    word = realloc(word, i);
    return word;
}
