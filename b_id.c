#include "main.h"

/**
 * b_id - stores an unsigned int variable converted to binary in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void b_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	unsigned int b, j, k;
	char *buf;
	int len;

	b = va_arg(*(p), unsigned int);
	j = b;
	len = 0;

	if (b == 0)
	{
		buffer[(*i)++] = '0';
		return;
	}
	for (k = 0; flags[k] != '\0'; k++)
	{
		continue;
	}
	while (j != 0)
	{
		j = j / 2;
		len++;
	}
	buf = (char *)malloc((len + 1) * sizeof(char));
	if (buf == NULL)
		return;
	buf[len] = '\0';
	while (b != 0)
	{
		len--;
		buf[len] = ((b % 2) + 48);
		b = b / 2;
	}
	for (j = 0; buf[j] != '\0'; j++)
	{
		buffer[(*i)++] = buf[j];
	}
	free(buf);
}
