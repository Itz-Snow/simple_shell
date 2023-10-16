#include "sh.h"

/**
 * parsing - Tokenize a line of input into an array of tokens.
 * @line: The input line to tokenize.
 * @nline: size of line read
 *
 * Return: An array of tokens (strings), or NULL on error.
 */
char **parsing(char *line, ssize_t nline)
{
	char *token;
	char **tokens;
	int i = 0;

	tokens = malloc(sizeof(char *) * (nline / 2 + 1));
	if (!tokens)
	return (NULL);

	token = strtok(line, "\t\n\r\a ");
	while (token != NULL)
	{
	tokens[i] = token;
	token = strtok(NULL, "\t\n\r\a ");
	i++;
	}

	tokens[i] = NULL; /*Null-terminate the token array*/

	return (tokens);
}
