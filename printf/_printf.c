#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/* Define constants for flags */
#define FLAG_MINUS   (1 << 0)
#define FLAG_PLUS    (1 << 1)
#define FLAG_SPACE   (1 << 2)
#define FLAG_ZERO    (1 << 3)
#define FLAG_HASH    (1 << 4)

/**
 * get_flags - Extract flags from the format string.
 * @format: format string.
 * @i: current position in the format string.
 * Returns: A bitmask representing the flags.
 */
int get_flags(const char *format, int *i)
{
    int flags = 0;

    while (format[*i] == '-' || format[*i] == '+' || format[*i] == ' ' ||
           format[*i] == '0' || format[*i] == '#') {
        if (format[*i] == '-')
            flags |= FLAG_MINUS;
        else if (format[*i] == '+')
            flags |= FLAG_PLUS;
        else if (format[*i] == ' ')
            flags |= FLAG_SPACE;
        else if (format[*i] == '0')
            flags |= FLAG_ZERO;
        else if (format[*i] == '#')
            flags |= FLAG_HASH;

        (*i)++;
    }

    return flags;
}

/**
 * get_width - Extract width from the format string.
 * @format: format string.
 * @i: current position in the format string.
 * @list: va_list for variable arguments.
 * Returns: The width as an integer.
 */
int get_width(const char *format, int *i, va_list list)
{
    int width = 0;

    if (format[*i] == '*') {
        width = va_arg(list, int);
        (*i)++;
    } else {
        while (format[*i] >= '0' && format[*i] <= '9') {
            width = width * 10 + (format[*i] - '0');
            (*i)++;
        }
    }

    return width;
}

/**
 * get_precision - Extract precision from the format string.
 * @format: format string.
 * @i: current position in the format string.
 * @list: va_list for variable arguments.
 * Returns: The precision as an integer.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int precision = -1; /* Initialize to -1 to distinguish between no precision and precision of 0. */

    if (format[*i] == '.') {
        (*i)++;
        if (format[*i] == '*') {
            precision = va_arg(list, int);
            (*i)++;
        } else {
            precision = 0;
            while (format[*i] >= '0' && format[*i] <= '9') {
                precision = precision * 10 + (format[*i] - '0');
                (*i)++;
            }
        }
    }

    return precision;
}

/**
 * get_size - Extract size from the format string.
 * @format: format string.
 * @i: current position in the format string.
 * Returns: The size as an integer.
 */
int get_size(const char *format, int *i)
{
    int size = 0;

    while (format[*i] == 'h' || format[*i] == 'l') {
        if (format[*i] == 'h')
            size++;
        else if (format[*i] == 'l')
            size++;

        (*i)++;
    }

    return size;
}

/* Rest of your _printf code... */

