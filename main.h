#ifndef MAIN_H
#define MAIN_H

typedef struct Types {

        char type;
        void (*func)(va_list *);
} types;
int _putchar(char c);
int _printf(const char *format, ...);
void c_id(char c);
void s_id(char *s);
void d_id(int n);

#endif
