#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "str.h"

char *my_readline(const char *prompt) {
    printf("%s", prompt);
    char buf[81]; 
    char *str = NULL;
    int len = 0, t;
    do {
        t = scanf("%80[^\n]", buf);
        if (t == -1) {
            return NULL;
        }
        else if (t == 0) scanf("%*c");
        else {
            int len_buf = my_strlen(buf);
            str = (char *)realloc(str, (len + len_buf + 1) * sizeof(char));
            my_memcpy(str + len, buf, len + len_buf);
            len = len + len_buf;
        }
    } while (t > 0);
    if (len == 0) str = (char *)malloc(1 * sizeof(char));
    str[len] = '\0';
    return str;
}

size_t my_strlen(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

char *my_strchr(const char *s, int c) {
    int q = 0;    
    while ((int)s[q] != c) {
        if (s[q] == '\0') break;
        ++q;
    }
    if ((s[q] != '\0') || ((char)c == '\0')) {
        char *res = (char *)s + q;
        return res;
    }
    return NULL;
}

char *my_strtok(char *str, const char *delim) {
    static char *ptr;
    if (str != NULL) {
        ptr = str;
    }
    while ((my_strchr(delim, *ptr) != NULL) && (*ptr != '\0')) {
            ++ptr;  
    } 
    if (*ptr == '\0')
        return NULL;
    str = ptr;
    while ((*ptr != '\0') && (my_strchr(delim, *ptr)) == NULL) {
        ++ptr;
    }
    if (*ptr != '\0') *ptr++ = '\0';
    return str;
}

char *my_strdup(const char *s) {
    int len_s = my_strlen(s);
    char *new_s = (char *)malloc((len_s + 1) * sizeof(char));
    my_memcpy(new_s, s, len_s + 1);
    return new_s;
}

void *my_memcpy(void *dest, const void *src, size_t n) {
    int i;
    for (i = 0; i < n; i++) {
        ((char*)dest)[i] = ((char*)src)[i];
    }
    return dest;
}
