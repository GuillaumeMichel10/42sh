/*
** EPITECH PROJECT, 2023
** src
** File description:
** command_heap
*/

#include "command.h"

static void free_heap(command_heap_t *heap)
{
    for (int i = 0; i < heap->size; ++i) {
        free(heap->tab[i]);
    }
    free(heap->tab);
    heap->capacity = 0;
    heap->size = 0;
}

static void add(command_heap_t *heap, command_list_t *list)
{
    if (heap->size == heap->capacity)
        return;

    heap->tab[heap->size++] = list;
}

command_heap_t new_command_heap(int capacity)
{
    command_heap_t heap = {
            malloc(sizeof(command_list_t *) * capacity),
            0,
            capacity,
            free_heap,
            add,
    };

    return (heap);
}
