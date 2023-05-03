/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_unsetenv
*/

#include "../../includes/mysh.h"

int my_unsetenv(mysh_t *mysh, command_node_t *command)
{
    env_node_t *node = mysh->env_list->first;

    (void)node;
    if (command->size == 1) {
        display_error("unsetenv", ERR_TOO_FEW_ARGUMENTS);
        return (FAILURE);
    }
    mysh->home = NULL;
    mysh->oldpwd = NULL;
//    for (int i = 1; node && command->text[i];) {
//        if (my_strcmp(node->text[0], command->text[i]) == 0) {
//            mysh->env_list->pop(mysh->list_env, node);
//            update_env(mysh);
//            node = mysh->env_list->first;
//            ++i;
//            continue;
//        }
//        if (!(node = node->next) && command->text[++i])
//            node = mysh->env_list->first;
//    }
    return (SUCCESS);
}
