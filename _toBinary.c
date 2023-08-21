#include <unistd.h>
#include "main.h"

/**
 * _binary - converts to binary
 * @arguments: lists to pass
 *
 * Return: binary number
 */
int _binary(va_list arguments)
{
	int binary = va_arg(arguments, int);
	int bin[32];
	int i = 0;

	while (binary > 0)
	{
		bin[i] = (binary % 2) + '0';
		binary /= 2;
	}
	while (i > 0)
	{
		i--;
		return (write(1, &bin[i], 1));
	}
}

/**
* _printf - outputs texts
* @format: modulo
*
* Return: size
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
			if (*format == '\0')
				return (-1);
			if (*format == 'b')
			{
				count += _binary(arguments);
			}
			else if (*format == '%')
			{
				count += write(1, format, 1);
			}
			else
			{
				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(arguments);
	return (count);
}
