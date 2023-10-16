#include "sh.h"

/**
 * non_interactive - function for non-interactive mode.
 * @sh_name: shell name
 */

void non_interactive(char *sh_name)
{
	char *line = NULL;
	char **tokens;
	size_t length = 0;
	ssize_t nline;
	int count = 1;

	while ((nline = getline(&line, &length, stdin)) != -1)
	{
	tokens = parsing(line, nline);
	if (tokens != NULL)
	{
		execute_builtin(tokens, sh_name, count);
		free(tokens);
	}
	}
	free(line); /* Free memory allocated for the input line */
}
