#ifndef my_strfunc_h
#define my_strfunc_h

size_t my_strlen(const char *str);
char *my_readline (const char *prompt);
char *my_strchr(const char *s, int c);
char *my_strtok(char *string, const char *delim);
char *my_strdup(const char *s);
void *my_memcpy(void *dest, const void *src, size_t n);

#endif
