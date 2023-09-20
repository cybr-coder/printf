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
				print_i(args, &count_char);
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
 * @args: Argument
 * @count_char: pointer to character count char
 */

void print_i(va_list args, int *count_char)
{
	int num = va_arg(args, int);
	int temp = num;
	int digit_count = 0;
	int negative = 0;
	int i, divisor, digit;

	if (num < 0)
	{
		negative = 1;
		temp = -temp;
	}

	do {
		temp /= 10;
		digit_count++;
	} while (temp != 0);

	if (negative)
	{
		*count_char += _putchar('-');
		digit_count--;
	}

	temp = num;
	while (digit_count > 0)
	{
		divisor = 1;

		for (i = 0; i < digit_count - 1; i++)
		{
			divisor *= 10;
		}
		digit = temp / divisor;
		temp %= divisor;
		*count_char += _putchar(digit + '0');
		digit_count--;
	}
}
