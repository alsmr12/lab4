#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "func1.h"

int my_strlen(const char *str) {
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
    if (str[*q] == '\0') {
	    return NULL;
    }
    while (c == 0) {
        // strchr
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

char *my_strdup(const char *s) {
	int len_s = my_strlen(s);
	char *new_s = (char *)malloc((len_s + 1) * sizeof(char));
	for (int i = 0; i <= len_s; i++) {
		new_s[i] = s[i];
	}
	return new_s;
}

char *my_strncpy(char *dest, const char *src, size_t n) {
    int i;
	for (i = 0; i < n && src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
        for (i; i < n; i++) {
                dest[i] = '\0';
	}
    return dest;
}

void *my_memcpy(void *dest, const void *src, size_t n) {
	int i;
	for (i = 0; i < n; i++) {
		((char*)dest)[i] = ((char*)src)[i];
	}
	return dest;
}

