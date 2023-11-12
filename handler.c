#include "main.h"

/**
 * handler - Controls the formatting of the string
 * @str: The format string
 * @list: The list of arguments
 *
 * Return: The total size of arguments with the total size of the base string
 **/
int handler(const char *str, va_list list)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '%')
        {
            int aux = percent_handler(str, list, &i);
            if (aux == -1)
                return (-1);

            size += aux;
            continue;
        }

        _putchar(str[i]);
        size++;
    }

    return (size);
}

/**
 * percent_handler - Controls the formatting for percent format
 * @str: The format string
 * @list: The list of arguments
 * @i: Iterator
 *
 * Return: The size of the number of elements printed
 **/
int percent_handler(const char *str, va_list list, int *i)
{
    *i = *i + 1;

    if (str[*i] == '\0')
        return (-1);

    if (str[*i] == '%')
    {
        _putchar('%');
        return (1);
    }

    int size, number_formats;
    format formats[] = {
        {'s', print_string}, {'c', print_char},
        {'d', print_integer}, {'i', print_integer},
        {'b', print_binary}, {'u', print_unsigned},
        {'o', print_octal}, {'x', print_hexadecimal_low},
        {'X', print_hexadecimal_upp}, {'p', print_pointer},
        {'r', print_rev_string}, {'R', print_rot}
    };

    number_formats = sizeof(formats) / sizeof(formats[0]);
    for (size = 0; size < number_formats; size++)
    {
        if (str[*i] == formats[size].type)
        {
            size = formats[size].f(list);
            return (size);
        }
    }

    _putchar('%');
    _putchar(str[*i]);

    return (2);
}

