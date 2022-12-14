#define my_strfunc_h
#ifdef my_strfunc_h

int my_strlen(const char *str);
char *my_strtok(char *string, char *delim, int *q);
char *my_strdup(const char *s);
char *my_strncpy(char *dest, const char *src, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);

#endif
