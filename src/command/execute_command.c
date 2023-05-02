/*
** EPITECH PROJECT, 2023
** src
** File description:
** exec_cmd_list
*/

#include "../../includes/mysh.h"

void exec_cmd(mysh_t *mysh, cmd_node_t *node, const int nb_pipes, const int n)
{
    static int pipe_fd[2][2];
    int exit_value = SUCCESS;

    if (nb_pipes && pipe(pipe_fd[0]) == -1)
        return;
    pid_t pid = fork();
    if (pid == 0) {
        connect_pipe(pipe_fd, nb_pipes, n);
        exit_value = builtin(mysh, node);
        if (exit_value != -1 && is_echo(node->text[0]) == FAILURE) {
            exit(exit_value);
        } else {
            execve(node->str, node->text, mysh->env);
        }
        exit(EXIT_FAILURE);
    }
    close_pipe(pipe_fd, nb_pipes, n);
    swap_pipe((int **)pipe_fd);
}

void exec_cmd_list(mysh_t *mysh, cmd_list_t *list)
{
    int status = 0;
    cmd_node_t *node = list->first;
    bool last_is_builtin = false;

    if (!node)
        return;
    if (is_builtin(list->last->text[0]) == SUCCESS) {
        last_is_builtin = true;
        --list->size;
    }
    for (int i = 0; i < list->size; ++i) {
        exec_cmd(mysh, node, list->size - 1, i);
        node = node->next;
    }
    for (int i = 0; i < list->size; ++i) {
        wait(&status);
        mysh->error = WEXITSTATUS(status);
    }
    if (last_is_builtin)
        mysh->error = builtin(mysh, list->last);
}
