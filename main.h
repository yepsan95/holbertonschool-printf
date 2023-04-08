#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * struct Types - structure for each specifier of the _printf function
 * @type: specifier character
 * @func: function that will be called when the specifier matches
 *
 * Description: this structure will be used to create an array of structures
 *              on which each element will correspond to a specifier character
 *              and the function that should be called when that character
 *              is found in the format string of the _printf function
 */
typedef struct Types
{
	char type;
	void (*func)(va_list *, unsigned char *, unsigned int *, char *);
} types;

int _putchar(char c);
int _printf(const char *format, ...);
void call_function(const char *format, va_list *p, unsigned int *j,
		unsigned int *i, unsigned char *buffer, char *flags_id);
void store_flags(const char *format, char *flags_id, unsigned int *j);
int special_cases(const char *format, unsigned int *j);
void check_flags_d(int n, char *flags, unsigned char *buffer, unsigned int *i);
int check_flags_p(unsigned long int x, unsigned char *buffer,
		unsigned int *i, char *flags);
int check_flags_x(unsigned int x, char *flags, unsigned char *buffer, unsigned int *i);
void clean_buffer(unsigned char *buffer, unsigned int i);

void c_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void s_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void S_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void d_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void b_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void u_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void o_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void x_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void X_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);
void p_id(va_list *p, unsigned char *buffer, unsigned int *i, char *flags);

#endif
