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

	if (format == NULL)
		return (-1);
	va_start(ap, format);

	while (*format != '\0')
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
					chars_printed = _printf(va_arg(ap, char *));
					break;
				case '%':
					write(1, "%", 1);
					chars_printed++;
					break;
				default:
					break;
			}
		}
		else
		{
			char c = *format;

			write(1, &c, 1);
			chars_printed++;
		}
		format++;
	}
	va_end(ap);
	return (chars_printed);
}

