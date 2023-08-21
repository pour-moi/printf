#include <unistd.h>
#include "main.h"

/**
 * _binary - converts to binary
 * @arguments: lists to pass
 *
 * Return: binary number
 */
int* _binary(va_list arguments)
{
	int binary = va_arg(arguments, int);
	static int bin[32];
	int i = 0;

	while (binary > 0)
	{
		bin[i] = (binary % 2) + '0';
		binary /= 2;
	}
	while (i > 0)
	{
		i--;
		(write(1, &bin[i], 1));
	}
	return (bin);
}
