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
	unsigned char buffer[1024];
	unsigned int j, k, i = 0;
	types type[] = {
		{'c', c_id},
		{'s', s_id},
		{'S', S_id},
		{'d', d_id},
		{'i', d_id},
		{'b', b_id},
		{'u', u_id},
		{'o', o_id},
		{'x', x_id},
		{'X', X_id},
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
				buffer[i++] = '%';
				j++;
				continue;
			}
			for (k = 0; type[k].type != '\0'; k++)
			{
				if (format[j + 1] == type[k].type)
				{
					(*type[k].func)(&p, buffer, &i);
					j++;
					break;
				}
			}
		}
		else
		{
			buffer[i++] = format[j];
		}
	}
	buffer[i] = '\0';
	write(1, buffer, i);
	clean_buffer(buffer, i);
	va_end(p);
	return (i);
}
