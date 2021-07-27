#include "holberton.h"

int _printf(const char *format, ...)
{
	printf("HOla");
	int i = 0, j = 0, sizeFormat, sizeBuffer;
	int (*cp_get_func)(va_list,char *,int);
	char *buffer;
	printf("HOla 2");
	va_list listArgs;

	va_start(listArgs,format);

	sizeFormat = _strlen(format);
	buffer = malloc(sizeof(char) * sizeFormat + 1);
	printf("HOla 3");
	if (!buffer)
		exit(1);
	buffer[sizeFormat] = '\0';
	printf("HOla 4");
	for (i = 0; i < sizeFormat;)
	{
		if (format[i] == '%')
		{
			cp_get_func = (*get_func)(&format[i + 1]);
			if (!cp_get_func)
			{
				write(2,"Error\n",6);
				exit(1);
			}
			j += cp_get_func(listArgs, buffer, j);
			i += 2;
		}
		else
		{
			buffer[j] = format[i];
			i++;
			j++;
		}
	}
	sizeBuffer = _strlen(buffer);
	write(2,buffer,sizeBuffer);
	free(buffer);
	return(sizeBuffer);
}
