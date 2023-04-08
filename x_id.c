#include "main.h"

/**
 * x_id - stores an unsigned int variable converted to hexadecimal in a buffer
 *        (abcdef in lower case)
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void x_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	unsigned int x, k;
	char *buf;
	int len = 0;

	x = va_arg(*(p), unsigned int);
	if (check_flags_x(x, flags, buffer, i) == -1)
		return;
	k = x;
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
			buffer[(*i)++] = buf[k] + 39;
	}
	free(buf);
}

/**
 * check_flags_x - checks the flags in a 'x' specifier and performs the
 *               corresponding actions for each case
 * @x: the number to be printed
 * @flags: string containing the flags in the specifier
 * @buffer: buffer that holds the characters to be printed
 * @i: index of the current position being printed in the buffer
 *
 * Return: -1 in case of error, 0 otherwise
 */
int check_flags_x(unsigned int x, char *flags,
		unsigned char *buffer, unsigned int *i)
{
	unsigned int j;

	if (x == 0)
	{
		buffer[(*i)++] = '0';
		return (-1);
	}
	for (j = 0; flags[j] != '\0'; j++)
	{
		if (flags[j] == '#')
		{
			buffer[(*i)++] = '0';
			buffer[(*i)++] = 'x';
			break;
		}
	}
	return (0);
}
