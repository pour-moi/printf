#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * _char - prints single character
 * @arguments: lists to pass
 *
 * Return: size
 */
int _char(va_list arguments)
{
	char arg = va_arg(arguments, int);

	return (write(1, &arg, 1));
}

/**
 * _string - prints more than single character
 * @arguments: lists to pass
 *
 * Return: size
 */
int _string(va_list arguments)
{
	char *str = va_arg(arguments, char *);

	if (str == NULL)
		str = "(null)";
	return (write(1, str, strlen(str)));
}

int _int(va_list arguments)
{
	int i = va_arg(arguments, int);
	char buffer[32];

	snprintf(buffer, 32, "%d", i);
	return (write(1, buffer, strlen(buffer)));
}

int *_binary(va_list arguments)
{
	unsigned int binary = va_arg(arguments, int);
	static int bin[32];
	int i = 0;

	if (binary < 0)
	{
		return (-1);
	}

	while (binary > 0)
	{
		bin[i] = (binary % 2) + '0';
		binary /= 2;
		i++;
	}
	while (i > 0)
	{
		i--;
		(write(1, &bin[i], 1));
	}
	return (bin);
}
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
			if (*format == '\0')
				return (-1);
			if (*format == 'c')
			{
				count += _char(arguments);
			}
			else if (*format == 'b')
			{
				_binary(arguments);
			}
			else if (*format == 's')
			{
				count += _string(arguments);
			}
			else if (*format == '%')
			{
				count += write(1, format, 1);
			}
			else if (*format == 'd' || *format == 'i')
			{
				count += _int(arguments);
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
