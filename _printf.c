#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format specifier
 *
 * Return: number of characters printed excluding the NULL byte
 */

int _printf(const char *format, ...)
{
	int count_char = 0;
	char ch;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				ch = va_arg(args, int);
				write(1, &ch, 1);
				count_char++
				break;
			}
		}
		
	}
	return (count_char);

}

