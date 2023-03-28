#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * c_id - prints a char variable
 * @p: pointer to variable
 * @count: counts the number of characters printed
 *
 * Return: void
 */
void c_id(va_list *p, unsigned int *count)
{
	char c;

	c = va_arg(*(p), int);
	_putchar(c);
	*(count) = *(count) + 1;
}

/**
 * s_id - prints a string variable
 * @s: string variable
 * @count: counts the number of characters printed
 *
 * Return: void
 */
void s_id(va_list *p, unsigned int *count)
{
	int i;
	char *s;

	s = va_arg(*(p), char *);

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		*(count) = *(count) + 1;
	}
}

/**
 * d_id - prints an int variable
 * @n: int variable
 * @count: counts the number of characters printed
 *
 * Return: void
 */
void d_id(va_list *p, unsigned int *count)
{
	int n, i, j, size, digit;

	n = va_arg(*(p), int);

	if (n == 0)
	{
		_putchar(48);
		*(count) = *(count) +1;
	}
	else if (n < 0)
	{
		_putchar('-');
		*(count) = *(count) + 1;
	}

	size = 0;
	i = n;
	while (i != 0)
	{
		i = i / 10;
		size++;
	}
	for (i = size; i > 0; i--)
	{
		digit = n;
		for (j = i; j > 1; j--)
		{
			digit = digit / 10;
		}
		digit = digit % 10;
		if (digit < 0)
			digit = digit * -1;
		_putchar(digit + 48);
		*(count) = *(count) + 1;
	}
}
