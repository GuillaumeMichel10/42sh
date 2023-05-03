/*
** EPITECH PROJECT, 2023
** src
** File description:
** setup
*/

#include "environment.h"

environment_list_t *new_environment(char **environment)
{
    environment_list_t *list =  new_environment_list();
    environment_node_t *node = NULL;

    for (int i = 0; environment[i]; ++i) {
        node = list->new();
        node->text[0] = my_strccpy(environment[i], "=");
        node->text[1] = my_strcpy(environment[i] + my_strlen(node->text[0]) + 1);
        node->str = my_concat(3, node->text[0], "=",  node->text[1]);
        node->len = 2;
        list->add(list, node);
    }
    return (list);
}
