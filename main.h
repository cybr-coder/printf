#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
void print_c(va_list args, int *count_char);
void print_s(va_list args, int *count_char);

#endif
