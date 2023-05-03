/*
** EPITECH PROJECT, 2023
** src
** File description:
** redirect_in
*/

#include "../../includes/mysh.h"

static void heredoc_loop(int *pipe_fd, const char *eof)
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t size = 0;

    while (1) {
        my_putstr("? ");
        size = getline(&lineptr, &n, stdin);
        lineptr[size - 1] = '\0';
        if (my_strcmp(eof, lineptr) == SUCCESS) {
            free(lineptr);
            break;
        }
        size = write(pipe_fd[1], lineptr, size);
        size = write(pipe_fd[1], "\n", 1);
        free(lineptr);
        lineptr = NULL;
    }
}

static int handle_heredoc(const char *eof)
{
    int pipe_fd[2];
    pid_t pid = 0;

    if (pipe(pipe_fd) == -1)
        return (0);
    pid = fork();
    if (pid == 0) {
        close(pipe_fd[0]);
        heredoc_loop(pipe_fd, eof);
        close(pipe_fd[1]);
        exit(SUCCESS);
    } else {
        wait(NULL);
    }
    close(pipe_fd[1]);
    return (pipe_fd[0]);
}

static int redirect_in_from(char *filename, int option)
{
    int input = 0;
    error_m error = is_file_accessible(filename);

    if (error != ERR_OK) {
            display_error(filename, error);
            return (FAILURE);
    }
    if (option == 1) {
        input = open(filename, O_RDONLY, 0777);
    } else {
        input = handle_heredoc(filename);
    }
    dup2(input, STDIN_FILENO);
    close(input);
    return (SUCCESS);
}

int redirect_in(char **arguments)
{
    int return_value = SUCCESS;

    for (int i = 0; arguments[i]; ++i) {
        if (my_strcmp(arguments[i], "<") == 0) {
            return_value = redirect_in_from(arguments[i + 1], 1);
            erase_row(&arguments[i], 2);
            break;
        }
        if (my_strcmp(arguments[i], "<<") == 0) {
            return_value = redirect_in_from(arguments[i + 1], 2);
            erase_row(&arguments[i], 2);
            break;
        }
    }
    return (return_value);
}
