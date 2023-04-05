#include "main.h"

/**
 * c_id - stores a char variable in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void c_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	char c;
	int j;

	for (j = 0; flags[j] != '\0'; j++)
	{
		continue;
	}

	c = va_arg(*(p), int);
	buffer[(*i)++] = c;
}
