#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int character_printed = 0;
	va_list list_of_arguments;

	if (format == NULL)
		return (-1);

	va_start(list_of_arguments, format);

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
				char c = va_arg(list_of_arguments, int);

				write(1, &c, 1);
				character_printed++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_of_arguments, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				character_printed += str_len;
			}
		}

		format++;
	}

	va_end(list_of_arguments);

	return (character_printed);
}
