#include <unistd.h>
#include <string.h>
#include "main.h"

/**
* _printf - printf c and s format speciefiers
* @format: modulo
*
* Return: count Success
*/


int _printf(const char *format, ...)
{
	va_list arguments;
	int count = 0;

	va_start(arguments, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char arg = va_arg(arguments, int);

				count += write(1, &arg, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(arguments, char *);

				if (str == NULL)
					str = "(null)";

				count += write(1, str, strlen(str));
			}
			else if (*format == '%')
			{
				count += write(1, format, 1);
			}
			else
				count += write(1, "%", 1);
				count += write(1, format, 1);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(arguments);
	return (count);
}
