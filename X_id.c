#include "main.h"

/**
 * X_id - stores an unsigned int variable converted to hexadecimal in a buffer
 *        (ABCDEF in upper case)
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void X_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	unsigned int x, k, j;
	char *buf;
	int len;

	x = va_arg(*(p), unsigned int);
	k = x;
	len = 0;
	if (k == 0)
	{
		buffer[(*i)++] = '0';
		return;
	}
	for (j = 0; flags[j] != '\0'; j++)
	{
		if (flags[j] == '#')
		{
			buffer[(*i)++] = '0';
			buffer[(*i)++] = 'X';
			break;
		}
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
	while (x != 0)
	{
		len--;
		buf[len] = ((x % 16) + 48);
		x = x / 16;
	}
	for (k = 0; buf[k] != '\0'; k++)
	{
		if (buf[k] <= '9')
			buffer[(*i)++] = buf[k];
		else if (buf[k] > '9')
			buffer[(*i)++] = buf[k] + 7;
	}
	free(buf);
}
