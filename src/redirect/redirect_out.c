/*
** EPITECH PROJECT, 2023
** src
** File description:
** redirect_out
*/

#include "../../includes/mysh.h"

static void	redirect_out_to(const char *filename, int option)
{
    int output = 0;

    if (option == 1)
        output = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (option == 2)
        output = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
    dup2(output, STDOUT_FILENO);
    close(output);
}

int redirect_out(char **arguments)
{
    for (int i = 0; arguments[i]; ++i) {
        if (my_strcmp(arguments[i], ">") == SUCCESS) {
            redirect_out_to(arguments[i + 1], 1);
            erase_row(&arguments[i], 2);
            break;
        }
        if (my_strcmp(arguments[i], ">>") == SUCCESS) {
            redirect_out_to(arguments[i + 1], 2);
            erase_row(&arguments[i], 2);
            break;
        }
    }

    return (SUCCESS);
}
