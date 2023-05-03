/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_echo
*/

#include "../../includes/mysh.h"

int expand_error_variable(mysh_t *mysh, command_node_t *node, int index)
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

int expand_environmentironment_variables(mysh_t *mysh, command_node_t *node, int index)
{
    char *str = NULL;
    char *to_find = NULL;
    environment_node_t *environment = mysh->environment_list->first;

    while (environment) {
        to_find = my_concat(2, "$", environment->text[0]);
        if (my_strstr(node->text[index], to_find)) {
            str = my_str_replace(node->text[index], environment->text[1], to_find);
            free(node->text[index]);
            node->text[index] = str;
            free(to_find);
            return (SUCCESS);
        }
        free(to_find);
        environment = environment->next;
    }
    return (FAILURE);
}

int expand_dollar(mysh_t *mysh, command_node_t *node, int index)
{
    if (expand_error_variable(mysh, node, index) == SUCCESS)
        return (SUCCESS);
    if (expand_environmentironment_variables(mysh, node, index) == SUCCESS)
        return (SUCCESS);

    display_error(node->text[index], ERR_UNDEFINED_VARIABLE);
    return (FAILURE);
}

int my_echo(mysh_t *mysh, command_node_t *node)
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
    return (-1);
}
