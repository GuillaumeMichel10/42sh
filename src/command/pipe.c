/*
** EPITECH PROJECT, 2023
** src
** File description:
** list_env
*/

#include "command.h"

void close_pipe(int pipes[2][2], const int nb_pipes, const int n)
{
    if (nb_pipes) {
        if (n == nb_pipes || n != 0)
            close(pipes[1][0]);
        if (n == 0 || n != nb_pipes)
            close(pipes[0][1]);
    }
}

void connect_pipe(int pipes[2][2], const int nb_pipes, const int n)
{
    if (nb_pipes) {
        if (n == nb_pipes || n != 0)
            dup2(pipes[1][0], STDIN_FILENO);
        if (n == 0 || n != nb_pipes)
            dup2(pipes[0][1], STDOUT_FILENO);
    }
}

void swap_pipe(int **pipes)
{
    int *current_pipe = pipes[0];

    pipes[0] = pipes[1];
    pipes[1] = current_pipe;
}
