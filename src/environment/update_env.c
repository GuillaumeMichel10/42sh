/*
** EPITECH PROJECT, 2023
** src
** File description:
** setup
*/

#include "../../includes/mysh.h"

void my_reset_env(mysh_t *mysh)
{
    if (mysh->oldpwd) {
        free(mysh->oldpwd);
        mysh->oldpwd = NULL;
    }
    if (mysh->home) {
        free(mysh->home);
        mysh->home = NULL;
    }
    if (mysh->path) {
        for (int i = 0; mysh->path[i]; ++i)
            free(mysh->path[i]);
        free(mysh->path);
        mysh->path = NULL;
    }

    if (mysh->env) {
        for (int i = 0; mysh->env[i]; ++i)
            free(mysh->env[i]);
        free(mysh->env);
        mysh->env = NULL;
    }
}

void update_env(mysh_t *mysh)
{
    env_node_t *node = mysh->env_list->first;
    size_t k = 0;

    my_reset_env(mysh);

    mysh->env = malloc(sizeof(*node) * (mysh->env_list->size + 1));
    mysh->env[mysh->env_list->size] = NULL;
    for (int i = 0; node; ++i) {
        if (my_strcmp(node->text[0], "HOME") == 0)
            mysh->home = my_strcpy(node->text[1]);
        if (my_strcmp(node->text[0], "OLDPWD") == 0)
            mysh->oldpwd = my_strcpy(node->text[1]);
        if (my_strcmp(node->text[0], "PATH") == 0)
            mysh->path = my_str_to_word_array(node->text[1], ":", &k);
        mysh->env[i] = my_concat(3, node->text[0], "=", node->text[1]);
        node = node->next;
    }
}