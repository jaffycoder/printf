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
	int char_printed = 0, str_len;
	va_list args;

		if (!format)
		return (-1);
	va_start(args, format);

	while (*format)
	{
	if (*format != '%')
	{
		write(1, format, 1);
		char_printed++;
	}
	else
	{
		format++;
		if (*format == '\0')
		break;
	if (*format == '%' || *format == 'c')
	{
		write(1, format, 1);
		char_printed++;
	}
	else if (*format == 's')
	{
		char *str = va_arg(args, char*);

		str_len = 0;
		while (str[str_len])
			str_len++;
		write(1, str, str_len);
		char_printed += str_len;
	}
	}
	format++;
	}

	va_end(args);
	return (char_printed);
}
