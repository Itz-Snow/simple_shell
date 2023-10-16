#include "sh.h"
/**
 * main - Entry point for the simple shell program.
 * @argc: argument count
 * @argv: arguments
 *
 * Return: Always returns 0 to indicate successful execution.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line = NULL;
	char **tokens;
	int interactive_mode;
	size_t length = 0;
	ssize_t nline;
	int count = 0;

	interactive_mode = isatty(STDIN_FILENO);

	signal(SIGINT, sig_handle);
	if (interactive_mode)
	{
	while (1)
	{
		count++;
		printf("$ "); /* Print the shell prompt */
		nline = getline(&line, &length, stdin);
		if (nline != -1)
		{
		tokens = parsing(line, nline); /* Tokenize the input line */
		execute_builtin(tokens, argv[0], count);
		}
		else
		{
		printf("exiting shell...\n");
		exit(0);
		}
		free(tokens);
	}
	free(line); /* Free memory allocated for the input line */
	}
	else
	{
	non_interactive(argv[0]);
	}
	return (0);
}
