#include "holberton.h"

unsigned int (*character_handler(const char *character))(va_list, buffer_t *)
{
	unsigned int i;
	converter_t converters[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'%', convert_percent},
		{'d', convert_di},
		{'i', convert_di},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].character == *character)
			return (converters[i].func);
	}

	return (NULL);
}