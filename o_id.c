#include "main.h"

/**
 * o_id - stores an unsigned int variable converted to octal in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void o_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	unsigned int b, k;
	int j;
	char *buf;
	int len;


	b = va_arg(*(p), unsigned int);
	k = b;
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
			break;
		}
	}
	while (k != 0)
	{
		k = k / 8;
		len++;
	}
	buf = (char *)malloc((len + 1) * sizeof(char));
	if (buf == NULL)
		return;
	buf[len] = '\0';
	while (b != 0)
	{
		len--;
		buf[len] = ((b % 8) + 48);
		b = b / 8;
	}
	for (k = 0; buf[k] != '\0'; k++)
		buffer[(*i)++] = buf[k];
	free(buf);
}

