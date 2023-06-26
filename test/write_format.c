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
		return (-1);

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
