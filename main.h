#ifndef MAIN_H
#define MAIN_H

typedef struct Types {

        char type;
        void (*func)(va_list *);
} types;
int _printf(const char *format, ...);

#endif
