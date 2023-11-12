#include "main.h"

/**
 * _putchar - Writes the character 'c' to stdout
 * @c: The character to print
 *
 * Return: On success, returns 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (buffer(c));
}

/**
 * buffer - Saves the character 'c' in a buffer
 * @c: The character to be buffered
 *
 * Return: Always returns 1.
 **/
int buffer(char c)
{
    static char buffering[1024];
    static int buffer_index;

    if (c == -1 || buffer_index == 1024)
    {
        write(1, buffering, buffer_index);
        buffer_index = 0;
    }

    if (c != -1)
        buffering[buffer_index++] = c;

    return (1);
}

