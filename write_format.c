#include "main.h"

/**
 * percent_print - writes % to stdout
 * @arg_list: list of arguments provided
 *
 * Return: numb of bytes written or -1
 */
int percent_print(va_list arg_list)
{
	char perc;

	(void)arg_list;
	perc = '%';

	if (write(1, &perc, 1) == 1)
		return (1); /* write was successful */
	else
		return (-1); /* write failed */
}

/**
 * char_print - writes char to stdout
 * @arg_list: list of arguments provided
 *
 * Return: numb of bytes written or -1
 */
int char_print(va_list arg_list)
{
	char c_arg = va_arg(arg_list, int);

	/* check if char is within the printable ASCII range */
	if (c_arg < 32 && c_arg > 126)
		return (-1);

	if (write(1, &c_arg, 1) == 1)
		return (1);
	else
		return (-1);
}

/**
 * string_print - writes string to stdout
 * @arg_list: list of arguments provided
 *
 * Return: number of bytes written or -1
 */
int string_print(va_list arg_list)
{
	int len = 0;
	char *s_arg = va_arg(arg_list, char *);

	if (s_arg == NULL)
		s_arg = "(null)";

	while (*s_arg != '\0')
	{
		if (*s_arg < 32 && *s_arg > 126)
			return (-1);
		else if (write(1, s_arg, 1) == 1)
		{
			len++;
			s_arg++;
		}
		else
			return (-1);
	}

	return (len);
}

/**
 * int_print - writes integer to stdout
 * @arg_list: list of arguments provided
 *
 * Return: number of bytes written or -1
 */
int int_print(va_list arg_list)
{
	int n_arg, size;
	char buffer[1024];	/* assuming a max of 31 digits for int */

	n_arg = va_arg(arg_list, int);

	/* convert the int to a string using a helper function */
	size = int_to_string(n_arg, buffer);

	if (size == -1)
		return (-1);

	/* write the int to stdout */
	if (write(1, buffer, size) != size)
		/* write failed, return -1 to indicate an error */
		return (-1);

	/* write int to stdout */
	return (size);
}

/**
 * binary_print - handles the binary conversion of an unsigned int
 * @arg_list: list of arguments / variable
 *
 * Return: number of bytes written or -1
 */
int binary_print(va_list arg_list)
{
	unsigned int b_arg;
	int len = 0; /* to store number of written elements */
	char buffer[1024]; /* buffer to store bin bits (32 bits for unsigned int) */
	int k = 0, l;

	b_arg = va_arg(arg_list, unsigned int);

	if (b_arg == 0)
	{
		if (write(1, "0", 1) == 1)
			return (1);
		else
			return (-1);
	}

	/* if (b_arg < 0) return (-1); */

	/* convert number to binary by coninuously dividing by 2 */
	while (b_arg > 0)
	{
		buffer[k++] = '0' + (b_arg % 2);
		b_arg /= 2;
	}

	/* write the binary representation in reverse order */
	l = k - 1;
	while (l >= 0)
	{
		if (write(1, &buffer[l], 1) == 1)
			len++;
		else
			return (-1);
		l--;
	}

	return (len);
}
