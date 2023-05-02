/*
** EPITECH PROJECT, 2023
** src
** File description:
** list_env
*/

#include "env.h"

static env_node_t *new (char **text, int len)
{
    env_node_t *node = malloc(sizeof(*node));

    if (!node)
        return (NULL);

    node->text = text;
    node->len = len;
    node->prev = NULL;
    node->next = NULL;
    node->str = NULL;

    return (node);
}

static void add (env_list_t *list, env_node_t *node)
{
    if (!list || !node)
        return;

    if (list->size == 0) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
    ++list->size;
}

env_list_t *new_env_list(void)
{
    env_list_t *list = malloc(sizeof(*list));

    list->last = NULL;
    list->first = NULL;
    list->size = 0;
    list->add = add;
    list->new = new;

    return (list);
}
