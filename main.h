#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct mod - Struct mod
 * @specifier: char specifying modifier
 * @func_ptr: pointer to the appropriate function
 */
typedef struct mod
{
	char specifier;
	int (*func_ptr)(va_list);
} mod_t;

int _printf(const char *format, ...);
int (*get_mod_func(char c))(va_list);
int percent_print(va_list arg_list);
int char_print(va_list arg_list);
int string_print(va_list arg_list);

#endif /* MAIN_H */
