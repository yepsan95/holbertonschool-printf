#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * c_id - prints a char variable
 * @c: character variable
 *
 * Return: void
 */
void c_id(char c)
{
	_putchar(c);
}

/**
 * s_id - prints a string variable
 * @s: string variable
 *
 * Return: void
 */
void s_id(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
}

/**
 * d_id - prints an int variable
 * @n: int variable
 *
 * Return: void
 */
void d_id(int n)
{
	int i, j, size, digit;

	if (n == 0)
	{
		_putchar(48);
	}
	else if (n < 0)
	{
		_putchar('-');
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
	}
}
