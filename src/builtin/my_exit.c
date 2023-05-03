/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_cd
*/

#include "../../includes/mysh.h"

//    while (mysh->list_environment->first)
//        mysh->list_environment->pop(mysh->list_environment, mysh->list_environment->last);
//    while (mysh->commands.size)
//        mysh->commands.pop(&mysh->commands);
//    free (mysh->commands.array);
//    for (int i = 0; mysh->environment[i]; ++i)
//        free(mysh->environment[i]);
//    free(mysh->environment);
//    if (mysh->oldpwd)
//        free(mysh->oldpwd);
//    if (mysh->home)
//        free(mysh->home);

void exit_shell(mysh_t *mysh)
{
    mysh->exit = true;
}

int handle_exit_args(mysh_t *mysh, const char *exit_arg)
{
    int return_value = SUCCESS;

    if (!my_str_isnum(exit_arg)) {
        if (my_isalpha(exit_arg[0])) {
            display_error("exit", ERR_EXPR_SYNTAX_ERROR);
        } else {
            display_error("exit", ERR_BADLY_FORMED_NUMBER);
        }
        return_value = FAILURE;
    } else if (exit_arg[0] == '-' && !exit_arg[1]) {
        display_error("exit", ERR_EXPR_SYNTAX_ERROR);
        return_value = FAILURE;
    } else {
        return_value = my_atoi(exit_arg) % 256;
        exit_shell(mysh);
    }

    return (return_value);
}

int my_exit(mysh_t *mysh, command_node_t *command)
{
    int return_value = SUCCESS;

    switch (command->size) {
        case 1:
            exit_shell(mysh);
            break;
        case 2:
            return_value = handle_exit_args(mysh, command->text[1]);
            break;
        default:
            display_error("exit", ERR_EXPR_SYNTAX_ERROR);
            return_value = FAILURE;
            break;
    }

    return (return_value);
}
