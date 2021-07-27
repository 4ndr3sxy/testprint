#include "holberton.h"

int buffer_save_char(va_list list, char *buffer, int positionBuffer)
{
	int sizeVal;
	int i = 0;
	char *valueList = va_arg(list, char *);
	int sizeBuffer = _strlen(buffer);

	buffer = _realloc(buffer, sizeof(char) * sizeBuffer, (sizeof(char) * sizeBuffer) - 1);

	if (!buffer)
		exit(1);
	sizeVal = _strlen(valueList);
	if (sizeVal > 1)
	{
		write(2, "%c expects only one character", 29);
		free(buffer);
		exit(1);
	}
	buffer[positionBuffer] = *valueList;
	buffer[positionBuffer + 1] = '\0';
	i++;
	write(2, "hola", 4);
	return (i);
}

int buffer_save_string(va_list list, char *buffer, int positionBuffer)
{
	int i = 0;
	char *valueList = va_arg(list, char *);
	int sizeBuffer = _strlen(buffer);
	int sizeVal = _strlen(valueList);
	if (sizeVal == 1)
		buffer = _realloc(buffer, sizeof(char) * sizeBuffer, (sizeof(char) * sizeBuffer) + sizeVal - 1);
	else if (sizeVal == 2)
		buffer = _realloc(buffer, sizeof(char) * sizeBuffer, (sizeof(char) * sizeBuffer) + sizeVal);
	else
		buffer = _realloc(buffer, sizeof(char) * sizeBuffer, (sizeof(char) * sizeBuffer) + sizeVal - 2);

	if (!buffer)
		exit(1);

	while (valueList[i])
	{
		buffer[positionBuffer] = valueList[i];
		positionBuffer++;
		i++;
	}
	buffer[positionBuffer] = '\0';
	return (i);
}

int buffer_save_int(va_list list, char *buffer, int positionBuffer)
{
	int n, i;
	char *numberString;
	int sizeBuffer, sizeVal;

	n = va_arg(list, int);
	numberString = _itoa(n);
	sizeBuffer = _strlen(buffer);
	sizeVal = _strlen(numberString);
	if (sizeVal == 1)
		buffer = _realloc(buffer, sizeof(char) * sizeBuffer, (sizeof(char) * sizeBuffer) + sizeVal - 1);
	else if (sizeVal == 2)
		buffer = _realloc(buffer, sizeof(char) * sizeBuffer, (sizeof(char) * sizeBuffer) + sizeVal);
	else
		buffer = _realloc(buffer, sizeof(char) * sizeBuffer, (sizeof(char) * sizeBuffer) + sizeVal - 2);
	if (!buffer)
		exit(1);
	i = 0;
	while (numberString[i])
	{
		buffer[positionBuffer] = numberString[i];
		positionBuffer++;
		i++;
	}
	buffer[positionBuffer] = '\0';
	return (i);
}
