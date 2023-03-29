#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "main.h"
/**
 * _printf - prints and formats strings and specifiers
 * @format: the format of the string containing (or not) the variables
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list p;
	unsigned int j, k, count = 0;
	types type[] = {
		{'c', c_id},
		{'s', s_id},
		{'d', d_id},
		{'i', d_id},
		{'\0', NULL}
		};

	if (format == NULL)
		return (-1);
	va_start(p, format);
	for (j = 0; format[j]; j++)
	{
		if (format[j] == '%')
		{
			if (format[j + 1] == '%')
			{
				_putchar('%');
				count++;
				j++;
				continue;
			}
			for (k = 0; type[k].type != '\0'; k++)
			{
				if (format[j + 1] == type[k].type)
				{
					(*type[k].func)(&p, &count);
					j++;
					break;
				}
			}
		}
		else
		{
			_putchar(format[j]);
			count++;
		}
	}
	va_end(p);
	return (count);
}
