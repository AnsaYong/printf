#include "main.h"

/**
 * write_ud - converts unsigned int to unsigned decimal and writes to stdout
 * @arg_list: list of arguments provided
 *
 * Return: numb of bytes written or -1
 */
int write_ud(va_list arg_list)
{
	unsigned int ud_arg;
	int	len = 0;
	char buffer[1024];
	int i = 0, j;

	ud_arg = va_arg(arg_list, unsigned int);

	if (ud_arg == 0)
	{
		if (write(1, "0", 1) == 1)
			return (1);
		else
			return (-1);
	}

	/* convert unsigned int to unsigned dec by continuously dividing by 10 */
	while (ud_arg > 0)
	{
		buffer[i++] = '0' + (ud_arg % 10);
		ud_arg /= 10;
	}

	/* write the binary representation in reverse order */
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

/**
 * write_uo - converts unsigned int to unsigned octal and writes it to screen
 * @arg_list: list of arguments passed
 *
 * Return: number of written chars or -1
 */
int write_uo(va_list arg_list)
{
	unsigned int uo_arg;
	int len = 0;
	char buffer[1024];
	int i = 0, j;

	uo_arg = va_arg(arg_list, unsigned int);

	if (uo_arg == 0)
	{
		if (write(1, "0", 1) == 1)
			return (1);
		else
			return (-1);
	}

	while (uo_arg > 0)
	{
		buffer[i++] = '0' + (uo_arg % 8);
		uo_arg /= 8;
	}

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

/**
 * write_ux - converts unsigned int to lower hex and writes it to stdout
 * @arg_list: list of arguments provided
 *
 * Return: number of chars written or -1
 */
int write_ux(va_list arg_list)
{
	unsigned int uh_lower;
	int len = 0;
	char buffer[1024];
	int i = 0, j, rem;

	uh_lower = va_arg(arg_list, unsigned int);

	if (uh_lower == 0)
	{
		if (write(1, "0", 1) == 1)
			return (1);
		else
			return (-1);
	}

	while (uh_lower > 0)
	{
		rem = uh_lower % 16;
		/* if remainder is less than 10, convert to char and store in buffer */
		/* else convert to a char between 'a' and 'f' and store in buffer */
		buffer[i++] = (rem < 10) ? ('0' + rem) : ('a' + rem - 10);
		uh_lower /= 16;
	}

	/* write in reverse */
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

/**
 * write_uX - cpnverts unsigned int to upper hex and writes to stdout
 * @arg_list: list of arguments provided
 *
 * Return: number of written chars or -1
 */
int write_uX(va_list arg_list)
{
	unsigned int uh_upper;
	int len = 0;
	char buffer[1024];
	int i = 0, j, rem;

	uh_upper = va_arg(arg_list, unsigned int);

	if (uh_upper == 0)
	{
		if (write(1, "0", 1) == 1)
			return (1);
		else
			return (-1);
	}

	while (uh_upper > 0)
	{
		rem = uh_upper % 16;
		buffer[i++] = (rem < 10) ? ('0' + rem) : ('A' + rem - 10);
		uh_upper /= 16;
	}

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

/**
 * write_S - writes string with non-printable character to stdout
 * @arg_list: list of arguments provided
 *
 * Return: number of bytes written or -1
 */
int write_S(va_list arg_list)
{
	int len = 0;
	char *s_arg = va_arg(arg_list, char *);
	char array[4];
	char hex_code[] = "0123456789ABCDEF";

	if (s_arg == NULL)
		s_arg = "(null)";

	while (*s_arg != '\0')
	{
		if (*s_arg < 32 || *s_arg > 126)
		{
			array[0] = '\\';
			array[1] = 'x';
			array[2] = hex_code[*s_arg / 16];
			array[3] = hex_code[*s_arg % 16];

			len += write(1, array, 4);
		}
		else if (write(1, s_arg, 1) == 1)
		{
			len++;
		}
		else
			return (-1);
		s_arg++;

	}
	
	return (len);
}
