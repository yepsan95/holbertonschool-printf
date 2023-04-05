#include "main.h"

/**
 * s_id - stores a string variable in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void s_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	int j, k;
	char *s;
	char null[7] = "(null)";

	s = va_arg(*(p), char *);

	for (k = 0; flags[k] != '\0'; k++)
	{
		continue;
	}
	if (s == NULL)
	{
		for (j = 0; null[j] != '\0'; j++)
			buffer[(*i)++] = null[j];
	}
	else
	{
		for (j = 0; s[j] != '\0'; j++)
			buffer[(*i)++] = s[j];
	}
}

