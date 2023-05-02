/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_echo
*/

#include "../../includes/mysh.h"

int expand_error_variable(mysh_t *mysh, cmd_node_t *node, int index)
{
    char *str = NULL;
    char *replace = NULL;

    if (my_strstr(node->text[index], "$?")) {
        replace = my_itoa(mysh->error);
        str = my_str_replace(node->text[index], replace, "$?");
        free(node->text[index]);
        node->text[index] = str;
        free(replace);
        return (SUCCESS);
    }

    return (FAILURE);
}

int expand_environment_variables(mysh_t *mysh, cmd_node_t *node, int index)
{
    char *str = NULL;
    char *to_find = NULL;
    env_node_t *env = mysh->env_list->first;

    while (env) {
        to_find = my_concat(2, "$", env->text[0]);
        if (my_strstr(node->text[index], to_find)) {
            str = my_str_replace(node->text[index], env->text[1], to_find);
            free(node->text[index]);
            node->text[index] = str;
            free(to_find);
            return (SUCCESS);
        }
        free(to_find);
        env = env->next;
    }
    return (FAILURE);
}

int expand_dollar(mysh_t *mysh, cmd_node_t *node, int index)
{
    if (expand_error_variable(mysh, node, index) == SUCCESS)
        return (SUCCESS);
    if (expand_environment_variables(mysh, node, index) == SUCCESS)
        return (SUCCESS);

    display_error(node->text[index], ERR_UNDEFINED_VARIABLE);
    return (FAILURE);
}

int my_echo(mysh_t *mysh, cmd_node_t *node)
{
    char *str = NULL;

    for (int i = 0; node->text[i]; ++i) {
        str = my_str_replace(node->text[i], "", "'");
        free(node->text[i]);
        node->text[i] = str;
        str = my_str_replace(node->text[i], "", "\"");
        free(node->text[i]);
        node->text[i] = str;
        str = my_strchr('$', node->text[i]);
        if (str && *(++str) && expand_dollar(mysh, node, i) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}
