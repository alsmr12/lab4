#include <stdio.h>
#include <stdlib.h>
#include "func1.h"

int my_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

char *my_strtok(char *str, char *delim, int *q) {
    int len_delim = my_strlen(delim);
    int y = *q;
    int c = 0, i;
    while (c == 0) {
        for (i = 0; i < len_delim; i++) {
            if (str[*q] == delim[i]) c = 1;
	}
	if (c == 1) str[*q] = '\0';
	++(*q);
	if (str[*q] == '\0') c = 1;
    }
    if (str[*q] != '\0') {
	    while (c == 1) {
		c = 0;    
	        for (i = 0; i < len_delim; i++) {
                    if (str[*q] == delim[i]) c = 1;
		}
		++(*q);
	    }
	    --(*q);
    }
    return str + y; 
}
