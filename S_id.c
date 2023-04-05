#include "main.h"

/**
 * S_id - stores a string variable in a buffer.
 *        Non printable characters (0 < ASCII value < 32 or >= 127)
 *        are printed this way: \x, followed by the ASCII code value
 *        in hexadecimal (upper case - always 2 characters)
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 * @flags: array containing the _printf flags
 *
 * Return: void
 */
void S_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags)
{
	int j, n, k, digit;
	unsigned char *s;
	unsigned char buf[5];

	buf[0] = 92;
	buf[1] = 'x';
	buf[2] = '0';
	buf[3] = '0';
	buf[4] = '\0';

	s = va_arg(*(p), unsigned char *);

	for (j = 0; flags[j] != '\0'; j++)
	{
		continue;
	}
	for (j = 0; s[j] != '\0'; j++)
	{
		if (s[j] < 32 || s[j] >= 127)
		{
			k = s[j];
			digit = k % 16;
			if (digit > 9)
				buf[3] = digit + 55;
			else
				buf[3] = digit + 48;
			k = k / 16;
			digit = k % 16;
			if (digit > 9)
				buf[2] = digit + 55;
			else
				buf[2] = digit + 48;
			for (n = 0; n <= 3; n++)
				buffer[(*i)++] = buf[n];
		}
		else
		{
			buffer[(*i)++] = s[j];
		}
	}
}
