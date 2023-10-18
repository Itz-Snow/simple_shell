# Simple Shell Project

## Overview
This project is a simple Unix-like shell implementation written in C. It provides a command-line interface for users to execute commands, both built-in and external. The shell supports basic features, including executing programs, managing environment variables, and handling input/output redirection.

## Project Structure
The project directory contains the following files:

- **AUTHORS:** This file lists the contributors to the project.
- **README.md:** The current file, providing an in-depth overview of the project.
- **addpath.c:** Contains the `add_path` function responsible for finding the full path to a command in the system's PATH environment variable.
- **built-in_01.c:** Implements a built-in function (details provided below).
- **built-in_02.c:** Contains another built-in function (details below).
- **built-in_03.c:** Defines an additional built-in function (details below).
- **call-exe-cmd.c:** Handles the execution of external commands.
- **exe-builtin.c:** Manages the execution of built-in shell commands.
- **exe-cmd.c:** Deals with the execution of external programs.
- **handlerror.c:** Provides error handling mechanisms.
- **helper.c:** Contains utility functions and helpers used throughout the shell.
- **main.c:** Serves as the entry point for the shell program.
- **non-interactive.c:** Includes code for the non-interactive mode of the shell.
- **parsing.c:** Responsible for parsing user input.
- **readline.c:** Implements functions for reading user input.
- **sh.h:** The header file that includes function prototypes and necessary includes.

## Usage
To compile the shell, use the provided Makefile or the following command:

```shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -o simple_shell *.c
```

After compilation, you can run the shell using:

```shell
./simple_shell
```

The shell will display a prompt, and you can enter commands as you would in a typical Unix shell. Basic commands, as well as built-in functions, are supported.

## Acknowledgments
We'd like to acknowledge the contributors to this project and the inspiration drawn from Unix-like shell environments.

## Contributing
If you wish to contribute to this project, please follow the guidelines outlined in the AUTHORS file.

Enjoy using the Simple Shell!
