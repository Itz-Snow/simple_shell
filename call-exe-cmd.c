#include "sh.h"

/**
 * sh_executecmd - Execute a command.
 * @args: An array of command arguments.
 * @sh_name: shell name
 * @count: number of line
 *
 * Return: 0 on success, 1 on failure.
 */
int sh_executecmd(char **args, char *sh_name, int count)
{
	char *cmd, *act_cmd;

	cmd = args[0];

	/* Check if the command contains a '/' character */
	if (strchr(cmd, '/') != NULL)
	{
	/* Call the function to execute the command */
	execute_command(cmd, args, sh_name, count);
	}
	else
	{
	act_cmd = add_path(args[0]);
	execute_command(act_cmd, args, sh_name, count);
	free(act_cmd);
	}
	return (1);
}
