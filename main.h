#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int print_int(int n);
int print_bin(unsigned int n);
int print_unsigned(unsigned int n);
int print_oct(unsigned int n);
int print_hex(unsigned int n, bool uppercase);


#endif /* MAIN_H */
