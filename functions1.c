#include "main.h"

/**
 * print_int - prints an int to stdout
 * @n: an integer value
 * Return: characters printed
 */
int print_int(int n)
{
	int chars_printed = 0;
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		chars_printed++;
		n = -n;
	}
	if (n / 10)
		chars_printed += print_int(n / 10);

	c = n % 10 + '0';

	write(1, &c, 1);
	chars_printed++;

	return (chars_printed);
}
