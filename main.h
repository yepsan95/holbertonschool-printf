#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

typedef struct Types
{
	char type;
	void (*func)(va_list *, unsigned char *, unsigned int *);
} types;
int _putchar(char c);
int _printf(const char *format, ...);
void clean_buffer(unsigned char *buffer, unsigned int i);

void c_id(va_list *p, unsigned char *buffer, unsigned int *i);
void s_id(va_list *p, unsigned char *buffer, unsigned int *i);
void S_id(va_list *p, unsigned char *buffer, unsigned int *i);
void d_id(va_list *p, unsigned char *buffer, unsigned int *i);
void b_id(va_list *p, unsigned char *buffer, unsigned int *i);
void u_id(va_list *p, unsigned char *buffer, unsigned int *i);
void o_id(va_list *p, unsigned char *buffer, unsigned int *i);
void x_id(va_list *p, unsigned char *buffer, unsigned int *i);
void X_id(va_list *p, unsigned char *buffer, unsigned int *i);
void p_id(va_list *p, unsigned char *buffer, unsigned int *i);

#endif
