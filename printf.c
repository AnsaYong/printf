#include "main.h"

/**
 * _printf - Prints the format string replacing the conversion speficiers
 * @format: string
 *
 * Return: integer, number of bytes written
 */
int _printf(const char *format, ...)
{
	int num_chars_written = 0, write_check;
	char next_char;
	int (*mod_ptr)(va_list);
	va_list all_args;

	if (format == NULL)
		return (-1);

	va_start(all_args, format);

	while ((format != NULL) && (*format != '\0'))
	{
		if (*format == '%')
		{
			next_char = *(format + 1); /* get the next char */
			mod_ptr = get_mod_func(next_char);
			if (mod_ptr != NULL)
			{
				write_check = (*mod_ptr)(all_args);
				/* code to check if write was successful before adding */
				if (next_char == 's' && write_check != -1)
					num_chars_written += write_check;
				else if ((next_char == 'd' && write_check != -1) ||
						(next_char == 'i' && write_check != -1))
						num_chars_written += write_check;
				else if (write_check != -1)
					num_chars_written++;
				format++;
			}
		}
		else
		{
			if (write(1, format, 1) == 1)	/* already takes care of \<chars> */
				num_chars_written++;
		}
		format++;
	}

	va_end(all_args);

	return (num_chars_written);
}
