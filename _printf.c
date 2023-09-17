#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(ap, int);
					if (buff_ind < BUFFER_SIZE - 1)
					{
						out_buff[buff_ind++] = c;
					}
					else
					{
						flush_buff();
						out_buff[buff_ind++] = c;
					}
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
				case 'b':
					chars_printed += print_bin(va_arg(ap, unsigned int));
					break;
				case 'u':
					chars_printed += print_unsigned(va_arg(ap, unsigned int));
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
				default:
					break;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
