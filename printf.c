#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int character_printed = 0;
	va_list args;
	char *temp_str;
	int str_len;

	if (!format)
	return (-1);
	va_start(args, format);

	while (*format)
	{
	if (*format != '%')
	{
		write(1, format, 1);
		character_printed++;
	}
	else
	{
		format++;
		if (*format == '\0')
		break;
	if (*format == '%')
		{
		write(1, format, 1);
		character_printed++;
		}
		else if (*format == 'c')
		{
		char c = (char) va_arg(args, int);

		write(1, &c, 1);
		character_printed++;
		}
		else if (*format == 's')
		{
		temp_str = va_arg(args, char*);
		str_len = 0;
		while (temp_str[str_len])
		str_len++;
		write(1, temp_str, str_len);
		character_printed += str_len;
		}
	}
	format++;
	}

	va_end(args);
	return (character_printed);
}
