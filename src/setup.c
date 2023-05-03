/*
** EPITECH PROJECT, 2023
** src
** File description:
** setup
*/

#include "../includes/mysh.h"

mysh_t *setup(char **environment)
{
    mysh_t *mysh = malloc(sizeof(*mysh));

    *mysh = (mysh_t){0};
    mysh->environment_list = new_environment(environment);
    update_environment(mysh);
    return (mysh);
}
