#include "holberton.h"
#include <limits.h>


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
