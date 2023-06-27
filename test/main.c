#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;
	

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	len = _printf("Length:[%c, %s]\n", len, "\t");
	len2 = printf("Length:[%c, %s]\n", 39, "\t");
	_printf("len: %d / len2: %d\n", len, len2);
	printf("len: %d / len2: %d\n", len, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("large numb:[%d]\n", 6234762534);
	printf("large numb:[%d]\n", 6234762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	len = _printf("Character:[%c]\n", -1);
	len2 = printf("Character:[%c]\n", -1);
	printf("len: %d / len2: %d\n", len, len2);
	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	printf("len: %d / len2: %d\n", len, len2);
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	printf("Len:[%d]\n", len);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d] / len2: %d\n", len, len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	len = _printf("%c\n", '\0');
	len2 = printf("%c\n", '\0');
	printf("len: %d / len2: %d\n", len, len2);
	len = _printf("Our_char: %c\n", 256);
	len2 = printf("OG_char: %c\n", 256);
	printf("len: %d / len2: %d\n", len, len2);
	len = _printf("OUR Char: %c\n", 1000);
	len2 = printf("OG Char: %c\n", 1000);
	printf("len: %d / len2: %d\n", len, len2);
	return (0);
}
