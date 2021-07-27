#include "holberton.h"
#include <limits.h>

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

unsigned int convert_percent(__attribute__((unused)) va_list arg_list, buffer_t *output)
{
	char percent = '%';
	int ret = 0;

	ret += _copy(output, &percent, 1);

	return (ret);
}

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
	if (num == INT_MIN)
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

unsigned int convert_b(va_list args, buffer_t *output)
{
	unsigned int num;

	num = va_arg(args, int);

	return (convert_ubase(output, num, "01"));
}

unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base)
{
	unsigned int size, ret = 1;
	char digit;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		ret += convert_ubase(output, num / size, base);

	digit = base[(num % size)];
	_copy(output, &digit, 1);

	return (ret);
}

unsigned int convert_u(va_list arg_list, buffer_t *output)
{
	unsigned int num;
	unsigned int ret = 0;
	char zero = '0';

	num = va_arg(arg_list, unsigned int);

	if (!(num == 0))
		ret += convert_ubase(output, num, "0123456789");

	else
		ret += _copy(output, &zero, 1);

	return (ret);
}

unsigned int convert_o(va_list arg_list, buffer_t *output)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	num = va_arg(arg_list, unsigned int);
	if (!(num == 0))
		ret += convert_ubase(output, num, "01234567");

	else
		ret += _copy(output, &zero, 1);
	return (ret);
}

unsigned int convert_x(va_list arg_list, buffer_t *output)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	num = va_arg(arg_list, unsigned int);

	if (!(num == 0))
		ret += convert_ubase(output, num, "0123456789abcdef");

	else
		ret += _copy(output, &zero, 1);

	return (ret);
}

unsigned int convert_X(va_list arg_list, buffer_t *output)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	num = va_arg(arg_list, unsigned int);

	if (!(num == 0))
		ret += convert_ubase(output, num, "0123456789ABCDEF");

	else
		ret += _copy(output, &zero, 1);

	return (ret);
}

unsigned int convert_S(va_list args, buffer_t *output)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int size, i;
	unsigned int ret = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_copy(output, null, 6));

	for (size = 0; str[size];)
		size++;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) < 32 || *(str + i) >= 127)
		{
			ret += _copy(output, hex, 2);
			if (*(str + i) < 16)
				ret += _copy(output, &zero, 1);
			ret += convert_ubase(output, *(str + i),
					     "0123456789ABCDEF");
			continue;
		}
		ret += _copy(output, (str + i), 1);
	}

	return (ret);
}

unsigned int convert_p(va_list args, buffer_t *output)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int ret = 0;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_copy(output, null, 5));

	ret += convert_ubase(output, address, "0123456789abcdef");
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
