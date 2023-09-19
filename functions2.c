#include "main.h"

/**
 * print_non_printable - prints out a string of characters
 * @ap: pointer to a format string
 * @s: pointer to a string
 * Return: Nothing.
 */
int print_non_printable(va_list ap, char *s)
{
	int chars_printed = 0;
	int k = 0;

	s = va_arg(ap, char *);

	if (s == NULL)
		s = "(null)";

	while (s[k] != '\0')
	{
		if (s[k] < 32 || s[k] >= 127)
		{
			chars_printed += write(1, "\\x", 2);
			chars_printed += write(1, &"0123456789ABCDEF"[(unsigned char)s[k] / 16], 1);
			chars_printed += write(1, &"0123456789ABCDEF"[(unsigned char)s[k] % 16], 1);
		}
		else
		{
			chars_printed += write(1, &s[k], 1);
		}
		k++;
	}
	return (chars_printed);
}
/**
 * print_address - prints the address of a pointer in hex format
 * @p: pointer to a string
 * Return: Always 0.
 */
int print_address(void *p)
{
	unsigned long int address;
	char buff[32];
	int chars_printed = 0;
	int buff_ind = 0;
	int k = 0;
	char hex[] = "0123456789abcdef";

	address = (unsigned long int)p;

	if (address == 0)
	{
		buff[buff_ind++] = '0';
	}
	else
	{
		while (address > 0)
		{
			buff[buff_ind++] = hex[address % 16];
			address /= 16;
		}
	}

	buff[buff_ind++] = 'x';
	buff[buff_ind++] = '0';

	for (k = buff_ind - 1; k >= 0; k--)
	{
		write(1, &buff[k], 1);
		chars_printed++;
	}

	return (chars_printed);
}
