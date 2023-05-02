/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_setenv
*/

#include "../../includes/mysh.h"

void my_setenv_with_args(mysh_t *mysh, cmd_node_t *command)
{
    char **env = NULL;
    env_node_t *node = mysh->env_list->first;

    while (node) {
        if (my_strcmp(node->text[0], command->text[1]) == 0){
            free(node->text[1]);
            node->text[1] = my_strcpy(command->text[2]);
            update_env(mysh);
            return;
        }
        node = node->next;
    }
    env = malloc(sizeof(char *) * 3);
    env[2] = NULL;
    env[0] = my_strcpy(command->text[1]);
    env[1] = my_strcpy(command->text[2]);
    mysh->env_list->add(mysh->env_list, mysh->env_list->new(env, 2));
    update_env(mysh);
}

int is_valid_setenv_argument(const char *var_name)
{
    int return_value = SUCCESS;

    if (!my_isalpha(var_name[0]) && var_name[0] != '_') {
        display_error("setenv", ERR_VARIABLE_NAME_BEGIN_WITH_LETTER);
        return_value = FAILURE;
    } else if (!my_str_isalpha(var_name)){
        display_error("setenv", ERR_VARIABLE_NAME_CONTAIN_ALPHANUMERIC_CHARS);
        return_value = FAILURE;
    } else {}

    return (return_value);
}

int my_setenv(mysh_t *mysh, cmd_node_t *node)
{
    int return_value = SUCCESS;

    switch (node->size) {
        case 1:
            my_env(mysh, node);
            break;
        case 2 ... 3:
            if (is_valid_setenv_argument(node->text[1]) == SUCCESS) {
                my_setenv_with_args(mysh, node);
            } else {
                return_value = FAILURE;
            }
            break;
        default:
            display_error("setenv", ERR_TOO_MANY_ARGUMENTS);
            return_value = FAILURE;
    }
    return (return_value);
}
