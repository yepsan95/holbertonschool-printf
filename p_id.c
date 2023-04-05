#include "main.h"

/**
 * p_id - stores a pointer variable converted to hexadecimal in a buffer
 *        (abcdef in lower case)
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void p_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	unsigned long int x, k, j;
	char *buf;
	char null[] = "(nil)";
	int len;

	x = va_arg(*(p), unsigned long int);
	k = x;
	len = 0;

	if (x == 0)
	{
		for (j = 0; null[j] != '\0'; j++)
			buffer[(*i)++] = null[j];
		return;
	}
	for (j = 0; flags[j] != '\0'; j++)
	{
		if (flags[j] == '#')
			continue;
	}
	while (k != 0)
	{
		k = k / 16;
		len++;
	}
	buf = (char *)malloc((len + 1) * sizeof(char));
	if (buf == NULL)
		return;
	buf[len] = '\0';
	buffer[(*i)++] = '0';
	buffer[(*i)++] = 'x';
	while (x != 0)
	{
		len--;
		buf[len] = ((x % 16) + 48);
		x = x / 16;
	}
	for (j = 0; buf[j] != '\0'; j++)
	{
		if (buf[j] <= '9')
			buffer[(*i)++] = buf[j];
		else if (buf[j] > '9')
			buffer[(*i)++] = buf[j] + 39;
	}
	free(buf);
}
