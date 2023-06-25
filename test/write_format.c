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

	return (write(1, &perc, 1));
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

	return (write(1, &c_arg, 1));
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

	while (*s_arg != '\0')
	{
		write(1, s_arg, 1);
		len++;
		s_arg++;
	}

	return (len);
}
