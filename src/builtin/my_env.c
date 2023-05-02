/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_env
*/

#include "../../includes/mysh.h"

int my_env(mysh_t *mysh, cmd_node_t *command)
{
    (void)command;

    for (int i = 0; mysh->env[i]; ++i) {
        my_putstr(mysh->env[i]);
        my_putchar('\n');
    }

    return (SUCCESS);
}
