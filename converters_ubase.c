#include "holberton.h"

/**
 * convert_ubase - Converts an unsigned long to a base and
 *                 copies the result to the output.
 * @output: A buffer_t struct containing a character array.
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * Return: The number of bytes stored to the buffer.
 */
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

/**
 * convert_b - Converts an unsigned int to binary and
 *                 copies the result to the output.
 * @output: A buffer_t struct containing a character array.
 * @arg_list: A va_list list containing the arguments.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_b(va_list arg_list, buffer_t *output)
{
	unsigned int num;

	num = va_arg(arg_list, int);

	return (convert_ubase(output, num, "01"));
}

/**
 * convert_u - Converts an unsigned int to unsigned decimal and
 *                 copies the result to the output.
 * @output: A buffer_t struct containing a character array.
 * @arg_list: A va_list list containing the arguments.
 * Return: The number of bytes stored to the buffer.
 */
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

/**
 * convert_x - Converts an unsigned int to hexadecimal (lowercase) and
 *                 copies the result to the output.
 * @output: A buffer_t struct containing a character array.
 * @arg_list: A va_list list containing the arguments.
 * Return: The number of bytes stored to the buffer.
 */
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

/**
 * convert_X - Converts an unsigned int to hexadecimal (uppercase) and
 *                 copies the result to the output.
 * @output: A buffer_t struct containing a character array.
 * @arg_list: A va_list list containing the arguments.
 * Return: The number of bytes stored to the buffer.
 */
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
