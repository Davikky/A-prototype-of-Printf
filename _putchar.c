#include "main.h"
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1, on error -1
 */

int _putchar(char c)
{
	return (buffer(c));
}

/**
 * buffer - Save the character in a buffer
 * @c: Character
 *
 * Return: 1 on success, -1 on failure
 **/

int buffer(char c)
{
	static char *buffering = NULL;
	static int i = 0;

	if (buffering == NULL)
	{
		buffering = malloc(sizeof(char) * BUFFER_SIZE);
		if (buffering == NULL)
			return (-1);
	}

	if (c == -1 || i == BUFFER_SIZE)
	{
		write(1, buffering, i);
		i = 0;
	}

	if (c != -1)
		buffering[i++] = c;

	return (1);
}

/**
 * free_buffer - Frees the memory allocated for the buffer
 **/
void free_buffer(void)
{
	if (buffering != NULL)
	{
		free(buffering);
		buffering = NULL;
	}
}
