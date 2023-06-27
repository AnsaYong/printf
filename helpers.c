#include "main.h"

/**
 * int_to_string - converts an integer to a string
 * @number: the integer to be converted to string
 * @buffer: array to store the string representation
 * Return: size of the converted string
 */
int int_to_string(int number, char *buffer)
{
	char temp;
	int is_neg = 0, numb_digits = 0, start = 0, end = numb_digits - 1;

	if (number == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (1);
	}
	else if (number == -2147483648)
	{
		_strcpy(buffer, "-2147483648");
		return (11);
	}
	else
	{
		if (number < 0)
		{
			is_neg = 1;
			number = -number;
		}
		while (number > 0)
		{
			buffer[numb_digits++] = '0' + (number % 10);
			number /= 10;
		}
		if (is_neg)
			buffer[numb_digits++] = '-';
		buffer[numb_digits] = '\0';
		/* reverse the string */
		while (start < end)
		{
			temp = buffer[start];
			buffer[start] = buffer[end];
			buffer[end] = temp;
			start++;
			end--;
		}
		return (numb_digits);
	}
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: new array to fill
 * @src: array whose elements we are copying
 *
 * Return: pointer to new array
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i >= 0; i++)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break;
	}
	return (dest);
}
