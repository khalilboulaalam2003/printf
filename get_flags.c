#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Current index in the format string
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
    int flags = 0;
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (int curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        const char *found_flag = strchr(FLAGS_CH, format[curr_i]);

        if (found_flag != NULL)
        {
            int flag_index = found_flag - FLAGS_CH;
            flags |= FLAGS_ARR[flag_index];
        }
        else
        {
            break;
        }
    }

    *i = *i + (curr_i - *i - 1);

    return flags;
}

