#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints and formats strings and variables
 * @format: the format of the variables
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
 	va_list p;
        unsigned int j, k, count;
        types type[] = {
                {'c', c_id},
                {'s', s_id},
                {'\0', NULL}
                };

        va_start(p, format);

	count = 0;
        for (j = 0; format[j]; j++)
        {
                for (k = 0; type[k].type != '\0'; k++)
                {
                        if (format[j] == '%' && format[j + 1] == type[k].type)
                        {
                                (*type[k].func)(&p, &count);
                                if (format[j + 2] != '\0')
				{
                                        _putchar(',');
					count++;
					_putchar(32);
					count++;
				}
                                break;
                        }
                }
        }
        va_end(p);
	return (count);
}
