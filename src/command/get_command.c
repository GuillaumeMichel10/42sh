/*
** EPITECH PROJECT, 2023
** src
** File description:
** list_environment
*/

#include "../../includes/mysh.h"

static command_list_t *parse_pipe(char *input)
{
    size_t k = 0;
    command_list_t *list = new_command_list();
    char **command = NULL;
    char **text = my_str_to_word_array(input, "|", 0);

    for (int i = 0; text[i]; ++i) {
        command = my_str_to_word_array(text[i], " \t\n", &k);
        if (!command || !command[0])
            continue;
        list->add(list, list->new(command, (int)k));
    }
    return (list);
}

error_m get_command(command_heap_t *heap, char **commands)
{
    int nb_pipes = 0;
    error_m error = ERR_OK;

    for (int i = 0; commands[i] ; ++i) {
        nb_pipes = count_char(commands[i], '|');
        heap->add(heap, parse_pipe(commands[i]));
        error = test_redirections(heap->tab[heap->size - 1]);
        if (error != ERR_OK)
            break;
        if (heap->tab[heap->size - 1]->size == 0 && nb_pipes == 0)
            continue;
        if (nb_pipes + 1 != heap->tab[heap->size - 1]->size) {
            error = ERR_NULL_command;
            break;
        }
    }

    return (error);
}
