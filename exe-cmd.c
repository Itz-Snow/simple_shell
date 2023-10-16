#include "sh.h"

/**
 * execute_command - Execute a command in a child process.
 * @args: An array of command arguments.
 * @command: the command passed
 * @sh_name: shell name
 * @count: number of comand lines
 *
 * Return: 0 on success, 1 on failure.
 */
int execute_command(char *command, char **args, char *sh_name, int count)
{
	pid_t pid;
	int status;
	char *environ[] = { NULL };

	pid = fork();
	if (pid == 0)
	{
	/* Child process */
	if (execve(command, args, environ) == -1)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", sh_name, count, args[0]);
		exit(127);
	}
	}
	else if (pid < 0)
	{
	perror(sh_name);
	}
	else
	{
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
	return (127);
	else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	return (0);
	}
	return (127); /* Success */
}

