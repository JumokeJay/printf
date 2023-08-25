#include "main.h"
/*
 * _printf - the function to print
 * @format: the format type to print
 * Return: the result of the code
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
	if (*format == '%') {
	format++; // Move past the '%'
	if (*format == 'c') {
	char c = (char)va_arg(args, int);
	putchar(c);
	count++;
	}
	else if (*format == 's')
	{
	char *str = va_arg(args, char *);
	while (*str != '\0')
	{
	putchar(*str);
	str++;
	count++;
	}
	}
	else if (*format == 'd' || *format == 'i')
	{
	int num = va_arg(args, int);
	printf("%d", num);
	count++; // Counting digits of the number
	}
	else if (*format == '%')
	{
	putchar('%');
	count++;
	}
	}
	else
	{
	putchar(*format);
	count++;
	}
	format++;
	}

	va_end(args);
	return (count);
}
