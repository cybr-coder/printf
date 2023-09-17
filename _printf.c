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
			format++; //Proceed to the character immediately following '%'
			if (*format == 'c')
			{
				ch = va_arg(args, int);
				write(1, &ch, 1);
				count_char++
				break;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char);
				write(1, &str, 1);
				str++;
				count_char++;
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count_char++;	
			}	
		}
		else 
		{
			write(1, format, 1); //print characters that are regular
			count_char++;
		}
		format++;	
	}
	va_end(args);
	return (count_char);

}

