/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_env
*/

#include "../../includes/mysh.h"

int my_env(mysh_t *mysh, command_node_t *command)
{
    int return_value = SUCCESS;

    switch (command->size) {
        case 1:
            for (int i = 0; mysh->env[i]; ++i) {
                my_putstr(mysh->env[i]);
                my_putchar('\n');
            }
            break;
        default:
            display_error(NULL, ERR_NO_SUCH_FILE_OR_DIRECTORY);
            return_value = FAILURE;
            break;
    }



    return (return_value);
}
