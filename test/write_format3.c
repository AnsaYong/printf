#include "main.h"

/**
 * write_ptr - writes a memory address in hexadecimal format to stdout.
 * @arg_list: list of arguments provided.
 *
 * Return: number of bytes written or -1.
 */

int write_ptr(va_list arg_list)
{
	intptr_t ptr_arg;
	int len = 0;
	char buffer[SIZE];
	int i = 0, j;
	char hex_code[] = "0123456789abcdef";

	ptr_arg = (intptr_t)va_arg(arg_list, void*);

	if (ptr_arg == 0)
	{
		if (write(1, "(nil)", 5) == 5)
			return (5);
		else
			return (-1);
	}

    /* Convert pointer value to hexadecimal digits */
	while (ptr_arg > 0)
	{
		buffer[i++] = hex_code[ptr_arg & 0xF];
		ptr_arg >>= 4;
	}

    /* Add "0x" prefix */
	buffer[i++] = 'x';
	buffer[i++] = '0';

    /* Write in reverse */
	j = i - 1;
	while (j >= 0)
	{
		if (write(1, &buffer[j], 1) == 1)
			len++;
		else
			return (-1);
		j--;
	}

	return (len);
}
