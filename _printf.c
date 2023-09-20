#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format specifier
 *
 * Return: number of characters printed excluding the NULL byte
 */

int _printf(const char *format, ...)
{
	int temp, count_char = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /*Proceed to the character immediately following '%'*/
			if (*format == '\0')
			{
				va_end(args);
				return (-1);
			}
			if (*format == 'c')
				print_c(args, &count_char);
			else if (*format == 's')
				print_s(args, &count_char);
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				print_i(num);
				count_char += num < 0 ? 1 : 0;
				temp = (num < 0) ? -num : num;
				while (temp != 0)
				{
					count_char++;
					temp /= 10;
				}
			}
			else if (*format == '%')
				count_char += _putchar('%');
			else
			{
				count_char += _putchar('%');
				count_char += _putchar(*format);
			}
		}
		else
			count_char += _putchar(*format);
		format++;
	}
	va_end(args);
	return (count_char);
}

/**
 * print_c - Handles the format specifier 'c'
 * @args: The va_list containing arguments
 * @count_char: pointer to character count_char
 */

void print_c(va_list args, int *count_char)
{
	char c = va_arg(args, int);

	*count_char += _putchar(c);
}

/**
 * print_s - Handles the format specifier 's'
 * @args: The va_list containing arguments
 * @count_char: pointer to character count_char
 */

void print_s(va_list args, int *count_char)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		*count_char += _putchar(*str);
		str++;
	}
}

/**
 * print_i - Handles the 'd' and 'i' format specifiers for integers
 * @num: Argument
 */

void print_i(int num)
{
	int digit, divisor = 1;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	while (divisor <= num / 10)
		divisor *= 10;

	while (divisor > 0)
	{
		digit = num / divisor;
		_putchar('0' + digit);
		num %= divisor;
		divisor /= 10;
	}
}

