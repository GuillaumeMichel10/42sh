/*
** EPITECH PROJECT, 2023
** src
** File description:
** list_env
*/

#include "../../includes/mysh.h"

static cmd_list_t *parse_pipe(char *input)
{
    size_t k = 0;
    cmd_list_t *list = new_cmd_list();
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

void get_cmd(mysh_t *mysh, char *input)
{
    size_t k = 0;
    cmd_list_t *list = NULL;
    char **commands = my_str_to_word_array(input, ";", &k);

    for (int i = 0; commands[i] ; ++i) {
        list = parse_pipe(commands[i]);
        mysh->error = is_valid_input(mysh, list);
        if (mysh->error == SUCCESS)
            exec_cmd_list(mysh, list);
    }

//    for (int i = 0; i < mysh->commands.size; ++i) {
//        cmd_node_t *test = mysh->commands.tab[i]->first;
//        while (test) {
//            for (int i = 0; test->text[i]; ++i)
//                printf("%s\t", test->text[i]);
//            printf("\n");
//            test = test->next;
//        }
//    }
}
