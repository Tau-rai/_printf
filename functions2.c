#include "main.h"

/**
 * print_s - prints out a string of characters
 * @s: pointer to a string
 * Return: Nothing.
 */
void print_s(char *s)
{
	int k = 0;
	char hex[3];

	while (s[k])
	{
		if (s[k] < 32 || s[k] >= 127)
		{
			hex[0] = s[k] / 16;
			hex[1] = s[k] % 16;
			write(1, "\\x", 2);
			write(1, "0123456789ABCDEF" + hex[0], 1);
			write(1, "0123456789ABCDEF" + hex[1], 1);
		}
		else
		{
			write(1, &s[k], 1);
		}
		k++;
	}
}
/**
 * print_address - prints the address of a pointer in hex format
 * @p: pointer to a string
 * Return: Always 0.
 */
int print_address(void *p)
{
	char buff[20];
	unsigned long int address;
	int buff_ind;
	int k, j;
	char tmp;

	if (!p)
	{
		write(1, "(null)", 5);
	}

	address = (unsigned long int)p;
	buff_ind = 2;
	
	buff[0] = '0';
	buff[1] = 'x';

	while (address > 0)
	{
		int remainder = address % 16;

		char hex_dig = (remainder < 10) ? ('0' + remainder) : ('a' + remainder - 10);

		buff[buff_ind++] = hex_dig;
		address /= 16;
	}
	for (k = 2; (j = buff_ind - 1) && (k < j); k++, j--)
	{
		tmp = buff[k];
		buff[k] = buff[j];
		buff[j] = tmp;
	}

	buff[buff_ind] = '\0';

	write(1, buff, buff_ind);

	return (0);
}

