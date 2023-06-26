#include "main.h"

/**
 * get_mod_func - selects the correct function to perform
 * the modification asked by the user
 * @c: modifier provided by the user
 *
 * Return: pointer to function corresponding to the modifier
 * given as parameter or NULL if non is matched
 */
int (*get_mod_func(char c))(va_list)
{
	mod_t mods[] = {
		{'%', percent_print},
		{'c', char_print},
		{'s', string_print},
		{'d', int_print},
		{'i', int_print},
		{'\0', NULL}
	};
	size_t k;

	/* iterate through all elements of the mods[] array of structs */
	k = 0;
	while (mods[k].specifier != '\0')
	{
		if (c == mods[k].specifier)
			return (mods[k].func_ptr);
		k++;
	};

	return (NULL);
}
