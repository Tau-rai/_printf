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

/**
 * print_bin - prints binary to stdout
 * @n: integer value
 * Return: chars_printed
 */
int print_bin(unsigned int n)
{
	int chars_printed = 0;
	char binary[32];
	int k, len = 0;

	while (n > 0)
	{
		binary[len++] = (char)((n & 1) + '0');
		n >>= 1;
	}
	if (len == 0)
		binary[len++] = '0';

	for (k = len - 1; k >= 0; k--)
	{
		write(1, &binary[k], 1);
		chars_printed++;
	}

	return (chars_printed);
}
/**
 * print_unsigned - prints an unsigned int to stdout
 * @n: an unsigned int
 * Return: Always 0.
 */
int print_unsigned(unsigned int n)
{
	char buff[32];
	int k, len = 0;

	do
	{
		buff[len++] = (char)((n % 10) + '0');
		n /= 10;
	}
	while (n > 0);

	for (k = len - 1; k >= 0; k--)
		write(i, &buff[i], 1);

	return (len);
}
/**
 * print_oct - prints an act to stdout
 * @n: an unsigned int
 * Return: Always 0.
 */
int print_oct(unsigned int n)
{
	char buff[32];
	int k, len = 0;

	do
	{
		buff[len++] = (char)((n & 7) + '0');
		n >> 3;
	}
	while (n > 0);

	for (k = len - 1; k >= 0; k--)
		write(1, buff[k], 1);

	return (len);
}
/**
 * print_hex - prints hexadecimal numbers
 * @n: an unsigned int
 * @uppercase: boolean upper
 * Return: char count
 */
int print_hex(unsigned int n, bool uppercase)
{
	char buff[32];
	int k, len = 0;
	int digit;

	do
	{
		digit = n & 15;
		if (digit < 10)
			buff[len++] = (char)(digit + '0');
		else if (uppercase)
			buff[len++] = (char)(digit - 10 + 'A');
		else
			buff[len++] = (char)(digit - 10 + 'a');
		n >>= 4;
	}
	while (n > 0);

	for (k = len - 1; k >= 0; k--)
		write(1, &buff[k], 1);

	return (len);
}
