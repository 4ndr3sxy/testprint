#include "holberton.h"
#include <limits.h>

/**
 * convert_di - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * Extra: this one works with %d and %i.
 * @arg_list: A va_list list containing the arguments..
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_di(va_list arg_list, buffer_t *output)
{
	int tens = 1;
	int num = va_arg(arg_list, int);
	int tensit = num;
	unsigned int ret = 0;
	char neg = '-';
	char temp;
	char *temp2;

	if (num < 0)
	{
		num *= -1;
		_copy(output, &neg, 1);
		tensit *= -1;
	}
	if (num == 0)
	{
		temp = '0';
		_copy(output, &temp, 1);
	}
	if (num == INT_MAX)
	{
		temp2 = "2147483647";
		_copy(output, temp2, 10);
		return (10);
	}
	while (num != 0)
	{
		num = num / 10;
		tens *= 10;
	}
	tens /= 10;
	while (tens != 0)
	{
		temp = (tensit / tens) + '0';
		_copy(output, &temp, 1);
		tensit = tensit % tens;
		tens /= 10;
		ret++;
	}
	return (ret);
}
