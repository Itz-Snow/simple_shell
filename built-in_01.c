#include "sh.h"

/**
 * execute_exit - Handle the "exit" built-in command.
 * @args: An array of command arguments.
 *
 * Return: The exit status code.
 */
int execute_exit(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
	{
	exit_status = atoi(args[1]);
	}

	exit(exit_status);
}

/**
 * execute_env - Handle the "env" built-in command.
 *
 *
 * Return: 0 on success, 1 on failure.
 */
int execute_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
	printf("%s\n", *env);
	env++;
	}

	return (0);
}

