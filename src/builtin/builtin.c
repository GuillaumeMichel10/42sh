/*
** EPITECH PROJECT, 2023
** src
** File description:
** built_in
*/

#include "../../includes/mysh.h"

static const built_in_t call_fnct[] = {
    {"cd", my_cd, SUCCESS},
    {"exit", my_exit, SUCCESS},
    {"unsetenv", my_unsetenv, SUCCESS},
    {"echo", my_echo, FAILURE},
    {"setenv", my_setenv, SUCCESS},
    {"env", my_env, SUCCESS},
    {NULL, NULL, FAILURE}
};

int is_echo(char *str)
{
    return (my_strcmp(str, "echo"));
}

int is_builtin(char *str)
{
    for (int k = 0; call_fnct[k].ptr; ++k) {
        if (my_strcmp(call_fnct[k].name, str) == SUCCESS)
            return (call_fnct[k].exit_status);
    }
    return (FAILURE);
}

int builtin(mysh_t *mysh, command_node_t *node)
{
    for (int k = 0; call_fnct[k].ptr; ++k) {
        if (my_strcmp(call_fnct[k].name, node->text[0]) == SUCCESS)
            return (call_fnct[k].ptr(mysh, node));
    }
    return (-1);
}
