#include "sh.h"

/**
 * sig_handle - function that handles signal for ^c
 * @signal: signal to be handled
 */
void sig_handle(int signal)
{
	if (signal == SIGINT)
	{
	write(1, "\n$ ", 4);
	}
}
/**
 * check_delim - Check for delimiter in the character.
 * @delim: The delimiter string.
 * @c: The character to check.
 *
 * Return: 1 if it's a delimiter, 0 otherwise.
 */
bool check_delim(const char *delim, char c)
{
	unsigned int i;

	for (i = 0; delim[i] != '\0'; i++)
	{
	if (c == delim[i])
	return (true);
	}
	return (false);
}
