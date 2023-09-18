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
	char ch, *str;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '\0')
			break;
		if (*format == '%')
		{
			format++; /*Proceed to the character immediately following '%'*/
			if (*format == 'c')
			{
				ch = va_arg(args, int);
				count_char += print_c(ch);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				count_char += print_s(str);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count_char++;
			}
		}
		else
		{
			write(1, format, 1); /*print characters that are regular*/
			count_char++;
		}
		format++;
	}
	va_end(args);
	return (count_char);
}

/**
 * print_c - prints a character
 * @c: argument
 * Return: character
 */

int print_c(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_s - prints string
 * @str: argument
 * Return: string
 */

int print_s(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (write(1, str, len));
}
