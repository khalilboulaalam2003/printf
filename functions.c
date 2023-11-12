#include "main.h"

typedef struct print_specifier
{
    char specifier;
    int (*printer)(va_list, char[], int, int, int, int);
} print_specifier_t;

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);

print_specifier_t specifiers[] = {
    {'c', print_char},
    {'s', print_string},
    {'%', print_percent},
    {'d', print_int},
    {'i', print_int},
    {'b', print_binary},
    /* Add more specifiers as needed */
    {'\0', NULL} // Null terminator to mark the end of the array
};

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

            int i = 0;
            char specifier = *(format + (++i));

            while (specifiers[i].specifier != '\0')
            {
                if (specifiers[i].specifier == specifier)
                {
                    printed_chars += specifiers[i].printer(list, buffer, 0, 0, 0, 0);
                    break;
                }
                i++;
            }

            format += i;
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(list);

    return printed_chars;
}

