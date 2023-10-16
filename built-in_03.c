#include "sh.h"

/**
 * execute_cd - Handle the "cd" built-in command.
 * @args: An array of command arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int execute_cd(char **args)
{
	char *new_dir, *old_dir;

	if (args[1] == NULL)
	{
	new_dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
	new_dir = getenv("OLDPWD");
	}
	else
	{
	new_dir = args[1];
	}
	old_dir = getcwd(NULL, 0);
	if (old_dir == NULL)
	{
	perror("getcwd");
	return (1);
	}
	if (chdir(new_dir) != 0)
	{
	perror("chdir");
	free(old_dir);
	return (1);
	}
	setenv("OLDPWD", old_dir, 1);
	setenv("PWD", new_dir, 1);

	free(old_dir);

	return (0);
}

