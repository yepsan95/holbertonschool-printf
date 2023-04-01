#include "main.h"

/**
 * clean_buffer - cleans a buffer for a new use
 * @buffer: buffer to be cleaned
 * @i: number of bytes in the buffer to be cleaned
 *
 * Return: void
 */
void clean_buffer(unsigned char *buffer, unsigned int i)
{
	unsigned int j;

	for (j = 0; j <= i; j++)
		buffer[j] = '\0';
}
