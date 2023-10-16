#include "sh.h"
/**
 * add_path - Find the full path to a command in the PATH environment.
 * @command: The command to find the full path for.
 *
 * Return: The full path to the command if found, or NULL if not found.
 */
char *add_path(char *command)
{
	char *path, *path_copy, *path_token;
	char *full_path = NULL;
	size_t len;
	struct stat buffer;

	path = getenv("PATH");

	if (path == NULL)
	return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
	return (NULL);

	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
	len = strlen(path_token) + 1 + strlen(command) + 1;
	full_path = (char *)malloc(len);

	if (full_path == NULL)
	{
		free(path_copy);
		return (NULL);
	}
	strcpy(full_path, path_token);
	strcat(full_path, "/");
	strcat(full_path, command);
	if (stat(full_path, &buffer) == 0)
	{
		free(path_copy);
		return (full_path);
	}
	free(full_path);
	path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
