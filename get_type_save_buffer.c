#include "holberton.h"

/**
 * get_op_func - functi to select operations
 * @s: character to validate simbol
 * Return: int
 */
int (*get_func(const char *s))(va_list,char *,int)
{
	int i = 0;
	t_p functions[] = {
		{"c", buffer_save_char},
		{"s", buffer_save_string},
		{"i", buffer_save_int},
		{"d", buffer_save_int},
		{NULL, NULL}};
	while (i < 4)
	{
		if (*functions[i].character == s[0])
		{
			printf("%c",*functions[i].character);
			return (functions[i].f);
		}
		i++;
	}
	return (NULL);
}
