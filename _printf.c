#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list list;
    va_start(list, format);

    int printed_chars = 0;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;

    for (; *format != '\0'; format++)
    {
        if (*format != '%')
        {
            buffer[buff_ind++] = *format;
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            printed_chars += handle_format(format + 1, list, buffer);
            while (*format && !is_valid_conversion(*format))
                format++;
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(list);

    return printed_chars;
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Buffer array
 * @buff_ind: Index at which to add the next character
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}

