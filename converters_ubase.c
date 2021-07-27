#include "holberton.h"

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

unsigned int convert_b(va_list args, buffer_t *output)
{
	unsigned int num;

	num = va_arg(args, int);

	return (convert_ubase(output, num, "01"));
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
