#ifndef MAIN_H
#define MAIN_H

typedef struct Types {

        char type;
        void (*func)(va_list *, unsigned int *);
} types;
int _putchar(char c);
int _printf(const char *format, ...);
void c_id(va_list *p, unsigned int *count);
void s_id(va_list *p, unsigned int *count);
void d_id(va_list *p, unsigned int *count);

#endif
