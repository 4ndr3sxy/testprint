#include "holberton.h"

unsigned int convert_c(va_list arg_list, buffer_t *output)
{
	char c;
	unsigned int ret = 0;

	c = va_arg(arg_list, int);

	ret += _copy(output, &c, 2);

	return (ret);
}

unsigned int convert_s(va_list arg_list, buffer_t *output)
{
	char *str, *null = "(null)";
	int size;
	unsigned int ret = 0;

	str = va_arg(arg_list, char *);
	if (str == NULL)
		return (_copy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;


	while (*str != '\0')
	{
		ret += _copy(output, str, 1);
		str++;
	}
	return (ret);
}

unsigned int convert_percent(__attribute__((unused)) va_list arg_list,
		buffer_t *output)
{
	char percent = '%';
	int ret = 0;

	ret += _copy(output, &percent, 1);

	return (ret);
}

unsigned int convert_r(va_list args, buffer_t *output)
{
	char *str, *null = "(null)";
	int size, lastchar, i;
	unsigned int ret = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		_copy(output, null, 6);

	for (size = 0; *(str + size);)
		size++;

	lastchar = size - 1;

	for (i = 0; lastchar >= 0; i++)
	{
		ret += _copy(output, (str + lastchar), 1);
		lastchar--;
	}

	return (ret);
}
