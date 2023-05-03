/*
** EPITECH PROJECT, 2023
** src
** File description:
** command_list
*/

#include "command.h"

static command_node_t *new (char **text, int size)
{
    command_node_t *node = malloc(sizeof(*node));

    if (!node)
        return (NULL);

    node->text = text;
    node->str = NULL;
    node->size = size;
    node->prev = NULL;
    node->next = NULL;

    return (node);
}

static void add (command_list_t *list, command_node_t *node)
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

command_list_t *new_command_list(void)
{
    command_list_t *list = malloc(sizeof(*list));

    list->last = NULL;
    list->first = NULL;
    list->size = 0;
    list->add = add;
    list->new = new;

    return (list);
}
