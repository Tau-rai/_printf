#include "main.h"

/*static void flush_buff(void);*/
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
	char out_buff[BUFFER_SIZE];
	static int buff_ind;

	static void flush_buff(void)
	{
		if (buff_ind > 0)
		{
			write(1, out_buff, buff_ind);
			buff_ind = 0;
		}
	}

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
						if (buff_ind < BUFFER_SIZE - 1)
						{
							out_buff[buff_ind++] = *s;
						}
						else
						{
							flush_buff();
							out_buff[buff_ind++] = *s;
						}
						s++;
						chars_printed++;
					}
					break;
				case '%':
					if (buff_ind < BUFFER_SIZE - 1)
					{
						out_buff[buff_ind++] = '%';
					}
					else
					{
						flush_buff();
						out_buff[buff_ind++] = '%';
					}
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
				default:
					break;
			}
		}
		else
		{
			if (buff_ind < BUFFER_SIZE - 1)
			{
				out_buff[buff_ind++] = *format;
			}
			else
			{
				flush_buff();
				out_buff[buff_ind++] = *format;
			}
			chars_printed++;
		}
		if (buff_ind == BUFFER_SIZE)
			flush_buff();

		format++;
	}
	flush_buff();

	va_end(ap);
	return (chars_printed);
}
/**
 * flush_buff - writes the contents of buffer to stdout
 * Return: Nothing
 */
/*static int buff_ind;*/

/*static void flush_buff(void)
{
	if (buff_ind > 0)
	{
		write(1, out_buff, buff_ind);
		buff_ind = 0;
	}
}*/
