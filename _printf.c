#include "main.h"

/**
 * _printf - prints and formats strings and specifiers
 * @format: the format of the string containing (or not) the variables
 *
 * Return: the number of characters printed, -1 on error
 */
int _printf(const char *format, ...)
{
	va_list p;
	unsigned int j, f, k, i = 0;
	unsigned char buffer[2048];
	char flags[] = "#+0- ";
	char flags_id[6];
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
		{'p', p_id},
		{'\0', NULL}
		};

	f = 0;
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
			else if (format[j + 1] == '\0')
			{
				return (-1);
			}
			else if (format[j + 1] == ' ' && format[j + 2] == '\0')
			{
				buffer[i++] = '%';
				buffer[i++] = ' ';
				break;
			}
			while (format[j + 1] == '#' || format[j + 1] == '+' || 
					format[j + 1] == '0' || format[j + 1] == '-'
					|| format[j + 1] == ' ')
			{
				for (k = 0; flags[k] != '\0'; k++)
				{
					if (format[j + 1] == flags[k])
					{
						flags_id[f] = flags[k];
						f++;
						j++;
						break;
					}
				}
			}
			flags_id[f] = '\0';
			for (k = 0; type[k].type != '\0'; k++)
			{
				if (format[j + 1] == type[k].type)
				{
					(*type[k].func)(&p, buffer, &i, flags_id);
					j++;
					break;
				}
			}
			if (type[k].type == '\0')
			{
				if (format[j + 1] == '%')
				{
					buffer[i++] = '%';
					j++;
			}
				else
				{
				buffer[i++] = format[j];
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
