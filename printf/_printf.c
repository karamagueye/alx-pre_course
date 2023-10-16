#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int charCount = 0;

    while (*format) {
        if (*format != '%') {
            putchar(*format);
            charCount++;
        } else {
            format++;  // Move past the '%'
            if (*format == 'c') {
                char c = va_arg(args, int);
                putchar(c);
                charCount++;
            } else if (*format == 's') {
                char *str = va_arg(args, char*);
                if (str) {
                    while (*str) {
                        putchar(*str);
                        str++;
                        charCount++;
                    }
                }
            } else if (*format == '%') {
                putchar('%');
                charCount++;
            }
        }
        format++;
    }

    va_end(args);
    return charCount;
}

int main() {
    _printf("Hello, %s! This is a simple %c%c%c example.\n", "World", 'p', 'r', 'i');
    return 0;
}


