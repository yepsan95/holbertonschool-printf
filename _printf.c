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
	unsigned int j, i = 0;
	unsigned char buffer[2048];
	char flags_id[6];

	if (format == NULL)
		return (-1);
	va_start(p, format);
	for (j = 0; format[j]; j++)
	{
		if (format[j] == '%')
		{
			if (special_cases(format, &j) == -1)
				return (-1);
			if (format[j + 1] == '%')
			{
				buffer[i++] = '%';
				j++;
				continue;
			}
			else if (format[j + 1] == ' ' && format[j + 2] == '\0')
			{
				buffer[i++] = '%';
				buffer[i++] = ' ';
				break;
			}
			store_flags(format, flags_id, &j);
			call_function(format, &p, &j, &i, buffer, flags_id);
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

/**
 * store_flags - stores the flags of a specifier in a buffer named flags_id
 * @format: string from where the flags will be taken
 * @flags_id: buffer where the flags contained in the specifier will be stored
 * @j: number of index of the format string that is currently being scanned
 *
 * Return: void
 */
void store_flags(const char *format, char *flags_id, unsigned int *j)
{
	int k, f = 0;
	char flags[] = "#+0- ";

	while (format[(*j) + 1] == '#' || format[(*j) + 1] == '+' ||
			format[(*j) + 1] == '0' || format[(*j) + 1] == '-'
			|| format[(*j) + 1] == ' ')
	{
		for (k = 0; flags[k] != '\0'; k++)
		{
			if (format[(*j) + 1] == flags[k])
			{
				flags_id[f] = flags[k];
				f++;
				(*j)++;
				break;
			}
		}
	}
	flags_id[f] = '\0';
}

/**
 * call_function - calls the corresponding function when
 *                 a conversion character is found
 * @format: string containing the specifiers
 * @p: pointer to va_list (variadic funtions)
 * @j: index of the format string element that is currently being scanned
 * @i: index of the buffer character that is currently being written
 * @buffer: buffer that holds all the characters to be printed
 * @flags_id: string containing the flags present in a specifier
 */
void call_function(const char *format, va_list *p, unsigned int *j,
		unsigned int *i, unsigned char *buffer, char *flags_id)
{
	unsigned int k;
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

	for (k = 0; type[k].type != '\0'; k++)
	{
		if (format[(*j) + 1] == type[k].type)
		{
			(*type[k].func)(p, buffer, i, flags_id);
			(*j)++;
			break;
		}
	}
	if (type[k].type == '\0')
	{
		if (format[(*j) + 1] == '%')
		{
			buffer[(*i)++] = '%';
			(*j)++;
		}
		else
			{
			buffer[(*i)++] = format[(*j)];
			}
		}
}

/**
 * special_cases - handle special cases for the '%' character that
 *                 are not specifiers
 * @format: string containing the specifiers
 * @j: index of the format string element that is currently being scanned
 *
 * Return: if special case is an error, return -1
 */
int special_cases(const char *format,
		unsigned int *j)
{
	if (format[(*j) + 1] == '\0')
		return (-1);
	else
		return (0);
	
}
