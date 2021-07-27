#include "holberton.h"

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
