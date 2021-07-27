#ifndef HOLBERTON_T
#define HOLBERTON_T

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct type_print - type_print
 * @character: type of data
 * @f: The function associated
 */
typedef struct type_print
{
	char *character;
	int (*f)(va_list, char *, int);
} t_p;

int (*get_func(const char *s))(va_list, char *, int);

int count_modulars(char *);

int buffer_save_char(va_list, char *, int);
int buffer_save_string(va_list, char *, int);
int buffer_save_int(va_list, char *, int);

char *_itoa(int num);
int _strlen(const char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _printf(const char *format, ...);

#endif /* HOLBERTON_T */
