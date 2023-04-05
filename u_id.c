#include "main.h"

/**
 * u_id - stores an unsigned int variable converted to decimal in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void u_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	unsigned int n, k, j, size, digit;

	n = va_arg(*(p), int);

	if (n == 0)
		buffer[(*i)++] = '0';
	for (j = 0; flags[j] != '\0'; j++)
	{
		continue;
	}
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
		buffer[(*i)++] = digit + 48;
	}
}
