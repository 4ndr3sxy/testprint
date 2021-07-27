#include "holberton.h"

void cleaner(va_list arg_list, buffer_t *output);
unsigned int execute_printf(const char *format, va_list arg_list, buffer_t *output);

void cleaner(va_list arg_list, buffer_t *output)
{
	va_end(arg_list);
	write(1, output->start, output->len);
	free_buffer(output);
}


unsigned int execute_printf(const char *format, va_list arg_list, buffer_t *output)
{
	unsigned int i, ret = 0;
	unsigned int (*f)(va_list, buffer_t *);

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			f = character_handler(format + i + 1);
			if (f != NULL)
			{
				i ++;
				ret += f(arg_list, output);
				continue;
			}
			else if (*(format + i + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _copy(output, (format + i), 1);
	}
	cleaner(arg_list, output);
	return (ret);
}


unsigned int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list arg_list;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(arg_list, format);

	ret = execute_printf(format, arg_list, output);

	return (ret);
}