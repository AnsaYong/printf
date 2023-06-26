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
	int is_neg = 0, numb_digits = 0, start, end;

	if (number == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (0);
	}
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
	start = 0;
	end = numb_digits - 1;
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
