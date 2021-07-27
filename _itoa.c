#include "holberton.h"

int count_digits(int n, int count)
{
	if (n > 9)
		return (count_digits(n / 10, count + 1));
	return (count + 1);
}

char *allocate_memory(int n)
{
	char *str;
	int i;

	if (n < 0)
	{
		n = -n;
		str = malloc(count_digits(n, 0) + 2);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		i = 1;
		while (i <= count_digits(n, 0))
			str[i++] = 'X';
		str[i] = '\0';
	}
	else
	{
		str = malloc(count_digits(n, 0) + 1);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (i < count_digits(n, 0))
			str[i++] = 'X';
		str[i] = '\0';
	}
	return (str);
}

char *string_zero(void)
{
	char *str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	return (str);
}

char *_itoa(int num)
{
	char *num_s, *i;

	if (num == 0)
		return (string_zero());

	num_s = allocate_memory(num);

	if (num_s == NULL)
		return (NULL);

	i = num_s;
	while (*i)
		i++;
	i--;
	if (num < 0)
		num = -num;
	while (num)
	{
		*i = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (num_s);
}
