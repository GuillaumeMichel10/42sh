/*
** EPITECH PROJECT, 2023
** src
** File description:
** setup
*/

#include "../includes/mysh.h"

mysh_t *setup(char **env)
{
    mysh_t *mysh = malloc(sizeof(*mysh));

    mysh->error = 0;
    mysh->env_list = new_env(env);
    mysh->exit = false;
    update_env(mysh);
    return (mysh);
}
