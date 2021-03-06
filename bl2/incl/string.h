
typedef unsigned long size_t;

void *memset(void *m, int c, size_t count);
void *memcpy(void *dest, const void *src, size_t n);
int   memcmp(const void *s1, const void *s2, size_t n);
int ffs(long int i);
int ffsl(long int i);

size_t	strlen(const char *s);
size_t	strnlen(const char *s, size_t n);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
unsigned long int strtoul(char *str, char **endp, int base);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
