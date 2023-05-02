/*
** EPITECH PROJECT, 2023
** src
** File description:
** setup
*/

#include "env.h"

env_list_t *new_env(char **env)
{
    env_list_t *list =  new_env_list();
    char **text = NULL;

    for (int i = 0; env[i]; ++i) {
        text = malloc(sizeof(char *) * 3);
        text[0] = my_strccpy(env[i], "=");
        text[1] = my_strcpy(env[i] + my_strlen(text[0]) + 1);
        text[2] = NULL;
        list->add(list, list->new(text, 2));
    }
    return (list);
}
