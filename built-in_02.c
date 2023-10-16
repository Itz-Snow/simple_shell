#include "sh.h"
/**
 * execute_setenv - Handle the "setenv" built-in command.
 * @args: An array of command arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int execute_setenv(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
	if (setenv(args[1], args[2], 1) != 0)
	{
		fprintf(stderr, "Error setting environment variable\n");
		return (1);
	}
	}
	else
	{
	fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	return (1);
	}

	return (0);
}
/**
 * execute_unsetenv - Handle the "unsetenv" built-in command.
 * @args: An array of command arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int execute_unsetenv(char **args)
{
	if (args[1] != NULL)
	{
	if (unsetenv(args[1]) != 0)
	{
		fprintf(stderr, "Error unsetting environment variable\n");
		return (1);
	}
	}
	else
	{
	fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	return (1);
	}

	return (0);
}

