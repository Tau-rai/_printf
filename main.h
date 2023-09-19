#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

extern int buff_ind;
extern char buff[BUFFER_SIZE];

int _printf(const char *format, ...);
int print_int(int n);
int print_bin(unsigned int n);
int print_unsignedInt(unsigned int n);
int print_oct(unsigned int n);
int print_hex(unsigned int n, bool uppercase);
int print_non_printable(va_list ap, char buffer[]);
int print_address(void *p);


#endif /* MAIN_H */
