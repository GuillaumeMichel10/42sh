/*
** EPITECH PROJECT, 2023
** src
** File description:
** exec_command_list
*/

#include "../../includes/mysh.h"

error_m is_redirections_valid(char **commands)
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
            return (ERR_NULL_command);
        if (*c == '<' && ++redirect_out == 2)
            return (ERR_AMBIG_IN_REDIRECT);
        if (*c == '>' && ++redirect_in == 2)
            return (ERR_AMBIG_OUT_REDIRECT);
    }
    return (ERR_OK);
}

error_m test_redirections(command_list_t *list)
{
    error_m error = ERR_OK;
    command_node_t *node = list->first;

    while (node) {
        error = is_redirections_valid(node->text);
        if (error != ERR_OK)
            break;
        node = node->next;
    }

    return (error);
}

error_m is_system_command(mysh_t *mysh, command_node_t *node)
{
    char *path = NULL;
    error_m error = ERR_OK;

    if (mysh->path == NULL)
        return (error);
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

error_m is_valid_command(mysh_t *mysh, command_node_t *node)
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

int test_command(mysh_t *mysh, command_list_t *list)
{
    command_node_t *node = list->first;
    error_m error = ERR_OK;

    for (;node; node = node->next) {
        if (is_builtin(node->text[0]) == SUCCESS)
            continue;
        error = is_valid_command(mysh, node);
        if (error == ERR_NO_SUCH_FILE_OR_DIRECTORY)
            error = ERR_command_NOT_FOUND;
        if (error != ERR_OK) {
            display_error(node->text[0], error);
            return (FAILURE);
        }
    }
    return (SUCCESS);
}
