#include "main.h"

int _printf(const char *format, ...);
/**
 * _printf - a function that produces output according to a format
 * @format: a character string
 * Return: the number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int chars_printed = 0;
	char c;
	char *s;

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
					write(1, &c, 1);
					chars_printed++;
					break;
				case 's':
					s = (va_arg(ap, char *));
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						write(1, s, 1);
						s++;
						chars_printed++;
					}
					break;
				case '%':
					write(1, "%", 1);
					chars_printed++;
					break;
				case 'd':
				case 'i':
					chars_printed += print_int(va_arg(ap, int));
					break;
				default:
					break;
			}
		}
		else
		{
			write(1, format, 1);
			chars_printed++;
		}
		format++;
	}
	va_end(ap);
	return (chars_printed);
}

