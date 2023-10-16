#include "sh.h"

/**
 * readline - Read a line of input from the user.
 *
 * Return: A pointer to the input line as a string,
 * or NULL on error or end of input.
 */
char *readline(void)
{
	char *line = NULL;
	/* A buffer size of 0 lets getline allocate memory as needed */
	size_t bufsize = 0;
	ssize_t chars_read;

	chars_read = getline(&line, &bufsize, stdin);

	if (chars_read == -1)
	{
	if (feof(stdin))
	{
		write(1, "\n$: ", 5);
	}
	else
	{
		perror("Error reading input");
	}
	free(line); /* Free memory allocated for the input line */
	return (NULL);
	}

	if (line[chars_read - 1] == '\n')
	{
	/* Remove the trailing newline character */
	line[chars_read - 1] = '\0';
	}

	return (line);
}
