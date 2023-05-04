/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_unsetenv
*/

#include "../../includes/mysh.h"

int my_unsetenv(mysh_t *mysh, command_node_t *command)
{
    environment_node_t *node = mysh->environment_list->first;

    if (command->size == 1) {
        display_error("unsetenv", ERR_TOO_FEW_ARGUMENTS);
        return (FAILURE);
    }
    for (int i = 1; node && command->text[i];) {
        if (my_strcmp(node->text[0], command->text[i]) == SUCCESS) {
            mysh->environment_list->pop(mysh->environment_list, node);
            update_environment(mysh);
            node = mysh->environment_list->first;
            ++i;
            continue;
        }
        node = node->next;
        if (!node && command->text[++i])
            node = mysh->environment_list->first;
    }
    return (SUCCESS);
}
