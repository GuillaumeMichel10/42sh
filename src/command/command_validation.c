/*
** EPITECH PROJECT, 2023
** src
** File description:
** exec_cmd_list
*/

#include "../../includes/mysh.h"

error_m is_valid_redirect(char **commands)
{
    int redirect_in = 0;
    int redirect_out = 0;
    char *c = NULL;

    for (int i = 0; commands[i]; ++i) {
        c = my_strchr(commands[i][0], "><");
        if (c == NULL)
            continue;
        if (!commands[i + 1] || my_strchr(commands[i + 1][0], "><") != NULL)
            return (ERR_MISSING_NAME_FOR_REDIRECT);
        if (i == 0)
            return (ERR_NULL_CMD);
        if (*c == '<' && ++redirect_out == 2)
            return (ERR_AMBIG_IN_REDIRECT);
        if (*c == '>' && ++redirect_in == 2)
            return (ERR_AMBIG_OUT_REDIRECT);
    }
    return (ERR_OK);
}

error_m is_system_command(mysh_t *mysh, cmd_node_t *node)
{
    char *path = NULL;
    error_m error = ERR_OK;

    for (int i = 0; mysh->path[i]; ++i) {
        path = my_concat(3, mysh->path[i], "/", node->text[0]);
        error = is_file_accessible(path);
        if (error == ERR_OK) {
            node->str = path;
            return (ERR_OK);
        }
        free(path);
        path = NULL;
    }
    return (error);
}

error_m is_valid_command(mysh_t *mysh, cmd_node_t *node)
{
    error_m error = ERR_OK;

    if (my_strchr('/', node->text[0])) {
        node->str = my_strcpy(node->text[0]);
        error = is_file_accessible(node->str);
    } else {
        error = is_system_command(mysh, node);
    }
    return (error);
}

int is_valid_input(mysh_t *mysh, cmd_list_t *list)
{
    cmd_node_t *node = list->first;
    error_m error = ERR_OK;

    for (;node; node = node->next) {
        if ((error = is_valid_redirect(node->text)) != ERR_OK) {
            display_error(NULL, error);
            return (FAILURE);
        }
        if (is_builtin(node->text[0]) == SUCCESS)
            continue;
        if ((error = is_valid_command(mysh, node)) != ERR_OK) {
            display_error(node->text[0], error);
            return (FAILURE);
        }
    }
//    if (list->size == 0) {
//        display_error(NULL, ERR_NULL_CMD);
//        return (FAILURE);
//    }
    return (SUCCESS);
}
