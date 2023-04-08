#include "main.h"

/**
 * d_id - stores an integer variable in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void d_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	int n, k, j, size, digit;

	n = va_arg(*(p), int);
	check_flags_d(n, flags, buffer, i);
	size = 0;
	k = n;
	while (k != 0)
	{
		k = k / 10;
		size++;
	}
	for (k = size; k > 0; k--)
	{
		digit = n;
		for (j = k; j > 1; j--)
			digit = digit / 10;
		digit = digit % 10;
		if (digit < 0)
			digit = digit * -1;
		buffer[(*i)++] = digit + 48;
	}
}

/**
 * check_flags_d - checks the flags in a specifier and performs the
 *               corresponding actions for each case
 * @n: the number to be printed
 * @flags: string containing the flags in the specifier
 * @buffer: buffer that holds the characters to be printed
 * @i: index of the current position being printed in the buffer
 */
void check_flags_d(int n, char *flags, unsigned char *buffer, unsigned int *i)
{
	int j, k;

	if (n >= 0)
	{
		for (j = 0; flags[j] != '\0'; j++)
		{
			if (flags[j] == '+')
			{
				k = 1;
				break;
			}
			else if (flags[j] == ' ')
			{
				k = -1;
			}
		}
		if (k == 1)
			buffer[(*i)++] = '+';
		else if (k == -1)
			buffer[(*i)++] = ' ';
		if (n == 0)
			buffer[(*i)++] = '0';
	}
	else if (n < 0)
	{
		buffer[(*i)++] = '-';
	}
}
