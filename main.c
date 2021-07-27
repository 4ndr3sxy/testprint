#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n"); //check
	len2 = printf("Let's try to | printf a simple sentence.\n");
	len = _printf("Let's try to printf a simple sentence.\n"); //check
	_printf("Character:[%c]\n", 'H');
	printf("\nCharacter |:[%c]\n", 'H');
	return (0);
}
