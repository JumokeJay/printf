#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define F-HASH 0x01

int write_unsgnd(int fd, int start, char buffer[], int flags, int width, int precision, int size)
{
	int count = 0;
	for (int i = start; buffer[i] != '\0'; i++)
	{
	putchar(buffer[i]);
	count++;
	}
	return (count);
}

unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{
	return (num);
}

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 10) + '0';
	num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

int write_unsgnd(int fd, int start, char buffer[], int flags, int width, int precision, int size) 
{
	return (write(fd, buffer + start, BUFF_SIZE - start));
}

unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{

	return (num);
}

int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 8) + '0';
	num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
	buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

int print_hexa(va_list types, const char *digits, char buffer[], int flags, char specifier, int width, int precision, int size)
{

	return (0);
}

int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}

int print_hexa(va_list types, const char *digits, char buffer[], int flags, char specifier, int width, int precision, int size)
{

	return (0);
}

int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}

unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{

	return (num);
}

int write_unsgnd(int fd, int start, char buffer[], int flags, int width, int precision, int size)
{

	return (write(fd, buffer + start, BUFF_SIZE - start));
}

int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = map_to[num % 16];
	num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
	buffer[i--] = flag_ch;
	buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
