#include "main.h"

int _printf(const char *format, ...);
void print_buff(char *buff, int buff_ind);
/**
 * _printf - a custom function that prints output according to a format
 * @format: a character string
 * Return: the number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int chars_printed = 0;
	char buff[BUFFER_SIZE];
	int buff_ind = 0;
	char c;
	char *s;
	void *p;

	if (format == NULL)
		return (-1);
	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(ap, int);
					buff[buff_ind++] = c;
					chars_printed++;
					break;
				case 's':
					s = (va_arg(ap, char *));
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						buff[buff_ind++] = *s;
						s++;
						chars_printed++;

						if (buff_ind == BUFFER_SIZE - 1)
						{
							print_buff(buff, buff_ind);
							buff_ind = 0;
						}
					}
					break;
				case '%':
					buff[buff_ind++] = '%';
					chars_printed++;
					if (buff_ind == BUFFER_SIZE - 1)
					{
						print_buff(buff, buff_ind);
						buff_ind = 0;
					}
					break;
				case 'd':
				case 'i':
					chars_printed += print_int(va_arg(ap, int));
					break;
				case 'b':
					chars_printed += print_bin(va_arg(ap, unsigned int));
					break;
				case 'u':
					chars_printed += print_unsignedInt(va_arg(ap, unsigned int));
					break;
				case 'o':
					chars_printed += print_oct(va_arg(ap, unsigned int));
					break;
				case'x':
					chars_printed += print_hex(va_arg(ap, unsigned int), false);
					break;
				case 'X':
					chars_printed += print_hex(va_arg(ap, unsigned int), true);
					break;
				case 'S':
					chars_printed += print_non_printable(ap, buff + chars_printed);
					break;
				case 'p':
					p = va_arg(ap, void *);
					chars_printed += print_address(p);
					break;

				default:
					break;
			}
		}
		else
		{
			buff[buff_ind++] = *format;
			chars_printed++;
			if (buff_ind == BUFFER_SIZE - 1)
			{
				print_buff(buff, buff_ind);
				buff_ind = 0;
			}
		}
		format++;

		if (buff_ind > 0)
		{
			print_buff(buff, buff_ind);
			buff_ind = 0;

		}
	}

	va_end(ap);
	return (chars_printed);
}
/**
 * print_buff - prints the contents of buffer to stdout
 * @buff: pointer to a string
 * @buff_ind: buffer index
 * Return: Nothing
 */
void print_buff(char *buff, int buff_ind)
{
	if (buff_ind > 0)
	{
		write(1, buff, buff_ind);
	}
}
