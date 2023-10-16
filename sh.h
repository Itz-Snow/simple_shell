#ifndef _SH_H_
#define _SH_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_TOKENS 64
#define MAX_TOKEN_LENGTH 256
#define PROGRAM_NAME "sh"
#define CHUNK_SIZE 1024
#define BUFFER_SIZE 128

extern char **environ;
int execute_exit(char **args);
int execute_env();
int execute_setenv(char **args);
int execute_unsetenv(char **args);
int execute_cd(char **args);
char *add_path(char *command);
int execute_command(char *command, char **args, char *sh_name, int count);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
char *custom_strtok(char *str, const char *delim);
bool check_delim(const char *delim, char c);
char **parsing(char *line, ssize_t nline);
char *readline(void);
void handle_read_error(char *line);
void handle_no_input(size_t total_bytes_read, char *line);
char *reallocate_buffer(char *line, size_t line_capacity);
void perror(const char *message);
int execute_builtin(char **args, char *sh_name, int count);
int sh_executecmd(char **args, char *sh_name, int count);
void non_interactive(char *sh_name);
void sig_handle(int signal);

#endif
