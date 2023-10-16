#include "sh.h"

/**
 * execute_builtin - Execute a built-in command.
 * @args: An array of command arguments.
 * @sh_name: shell name
 * @count: number of lines
 *
 * Return: 0 on success, 1, or sh_executecmd() return value.
 */
int execute_builtin(char **args, char *sh_name, int count)
{
	if (args == NULL || args[0] == NULL)
	{
	return (1);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
	return (execute_exit(args));
	}
	else if (strcmp(args[0], "env") == 0)
	{
	return (execute_env(args));
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
	return (execute_setenv(args));
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
	return (execute_unsetenv(args));
	}
	else if (strcmp(args[0], "cd") == 0)
	{
	return (execute_cd(args));
	}
	else
	{
	return (sh_executecmd(args, sh_name, count));
	}
}
