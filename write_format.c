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
	if (c_arg < 32 && c_arg >= 127)
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
		if (write(1, s_arg, 1) == 1)
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
	char buffer[24];	/* assuming a max of 31 digits for the int representation */

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
