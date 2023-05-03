/*
** EPITECH PROJECT, 2023
** src
** File description:
** setup
*/

#include "../../includes/mysh.h"

void my_reset_environment(mysh_t *mysh)
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

    if (mysh->environment) {
        for (int i = 0; mysh->environment[i]; ++i)
            free(mysh->environment[i]);
        free(mysh->environment);
        mysh->environment = NULL;
    }
}

void update_environment(mysh_t *mysh)
{
    environment_node_t *node = mysh->environment_list->first;
    size_t k = 0;

//    my_reset_environment(mysh);

    mysh->environment = malloc(sizeof(*node) * (mysh->environment_list->size + 1));
    mysh->environment[mysh->environment_list->size] = NULL;
    for (int i = 0; node; ++i) {
        if (my_strcmp(node->text[0], "HOME") == SUCCESS)
            mysh->home = my_strcpy(node->text[1]);
        if (my_strcmp(node->text[0], "OLDPWD") == SUCCESS)
            mysh->oldpwd = my_strcpy(node->text[1]);
        if (my_strcmp(node->text[0], "PATH") == SUCCESS)
            mysh->path = my_str_to_word_array(node->text[1], ":", &k);
        mysh->environment[i] = node->str;
        node = node->next;
    }
}