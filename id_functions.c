#include "main.h"

/**
 * c_id - stores a char variable in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void c_id(va_list *p, unsigned char *buffer, unsigned int *i)
{
	char c;

	c = va_arg(*(p), int);
	buffer[(*i)++] = c;
}

/**
 * s_id - stores a string variable in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void s_id(va_list *p, unsigned char *buffer, unsigned int *i)
{
	int j;
	char *s;
	char null[7] = "(null)";

	s = va_arg(*(p), char *);

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

/**
 * S_id - stores a string variable in a buffer.
 *        Non printable characters (0 < ASCII value < 32 or >= 127)
 *        are printed this way: \x, followed by the ASCII code value
 *        in hexadecimal (upper case - always 2 characters)
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void S_id(va_list *p, unsigned char *buffer, unsigned int *i)
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

/**
 * d_id - stores an integer variable in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void d_id(va_list *p, unsigned char *buffer, unsigned int *i)
{
	int n, k, j, size, digit;

	n = va_arg(*(p), int);

	if (n == 0)
		buffer[(*i)++] = '0';
	else if (n < 0)
		buffer[(*i)++] = '-';

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
		{
			digit = digit / 10;
		}
		digit = digit % 10;
		if (digit < 0)
			digit = digit * -1;
		buffer[(*i)++] = digit + 48;
	}
}

/**
 * b_id - stores an unsigned int variable converted to binary in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void b_id(va_list *p, unsigned char *buffer, unsigned int *i)
{
	unsigned int b, j;
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

/**
 * u_id - stores an unsigned int variable converted to decimal in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void u_id(va_list *p, unsigned char *buffer, unsigned int *i)
{
	unsigned int n, k, j, size, digit;

	n = va_arg(*(p), int);

	if (n == 0)
		buffer[(*i)++] = '0';

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

/**
 * o_id - stores an unsigned int variable converted to octal in a buffer
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void o_id(va_list *p, unsigned char *buffer, unsigned int *i)
{
	unsigned int b, k;
	char *buf;
	int len;

	b = va_arg(*(p), unsigned int);
	k = b;
	len = 0;

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

/**
 * x_id - stores an unsigned int variable converted to hexadecimal in a buffer
 *        (abcdef in lower case)
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void x_id(va_list *p, unsigned char *buffer, unsigned int *i)
{
	unsigned int x, k;
	char *buf;
	int len;

	x = va_arg(*(p), unsigned int);
	k = x;
	len = 0;

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
 * X_id - stores an unsigned int variable converted to hexadecimal in a buffer
 *        (ABCDEF in upper case)
 * @p: pointer to variable
 * @buffer: buffer where the characters are stored
 * @i: current index of the buffer to where the characters should be written
 *
 * Return: void
 */
void X_id(va_list *p, unsigned char *buffer, unsigned int *i)
{
	unsigned int x, k;
	char *buf;
	int len;

	x = va_arg(*(p), unsigned int);
	k = x;
	len = 0;

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
