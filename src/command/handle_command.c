/*
** EPITECH PROJECT, 2023
** src
** File description:
** handle_command
*/

#include "../../includes/mysh.h"

void handle_command(mysh_t *mysh, char *input)
{
    size_t k = 0;
    char **commands = my_str_to_word_array(input, ";", &k);
    command_heap_t heap = new_command_heap(k);
    error_m error = get_command(&heap, commands);

    if (error != ERR_OK) {
        display_error(NULL, error);
        mysh->error = FAILURE;
        return;
    }
    for (int i = 0; i < heap.size; ++i) {
        error = test_command(mysh, heap.tab[i]);
        if (error == FAILURE) {
            mysh->error = FAILURE;
            break;
        }
        exec_command_list(mysh, heap.tab[i]);
    }
}
