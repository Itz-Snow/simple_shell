#include "sh.h"
/**
 * handle_read_error - Handle errors that occur during reading.
 *
 * @line: The line buffer that may need to be freed.
 */
void handle_read_error(char *line)
{
	perror("read");
	free(line);
}
/**
 * handle_no_input - Handle the case where no input is received.
 *
 * @total_bytes_read: The total number of bytes read.
 * @line: The line buffer that may need to be freed.
 */
void handle_no_input(size_t total_bytes_read, char *line)
{
	if (total_bytes_read == 0)
	free(line);
}
/**
 * reallocate_buffer - Reallocate memory for a buffer with increased capacity.
 *
 * @line: Pointer to the existing buffer.
 * @line_capacity: Current capacity of the buffer.
 *
 * Return: Pointer to the reallocated buffer, or NULL on failure.
 */
char *reallocate_buffer(char *line, size_t line_capacity)
{
	char *new_line;

	line_capacity += CHUNK_SIZE;
	new_line = realloc(line, line_capacity);

	if (new_line == NULL)
	{
	perror("realloc");
	free(line); /* Free previously allocated memory. */
	return (NULL);
	}
	return (new_line);
}

