#include "main.h"

/**
 * _printf - Prints formatted output.
 * @format: A string containing format specifiers.
 *
 * Description:
 * This function produces output according to a format string, which may
 * include various directives. It returns the number of characters printed,
 * excluding the null byte used to end output to strings.
 *
 * Return: The number of characters printed.
 **/

int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    int size = _strlen(format);
    if (size <= 0)
        return (0);

    va_list args;
    va_start(args, format);

    size = handler(format, args);

    _putchar(-1);

    va_end(args);

    return (size);
}

