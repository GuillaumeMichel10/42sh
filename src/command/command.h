/*
** EPITECH PROJECT, 2023
** src
** File description:
** command
*/

#pragma once

#include "../../includes/include.h"

typedef struct mysh_s mysh_t;
typedef enum error_e error_m;

/*
**  cmd_list
*/

typedef struct cmd_node_s {
    struct cmd_node_s *next;
    struct cmd_node_s *prev;
    char **text;
    char *str;
    int size;
}cmd_node_t;

typedef struct cmd_list_s {
    cmd_node_t *first;
    cmd_node_t *last;
    cmd_node_t *(*new)(char **, int);
    void (*add)(struct cmd_list_s *, cmd_node_t *);
    int size;
}cmd_list_t;

cmd_list_t *new_cmd_list(void);

void get_cmd(mysh_t *mysh, char *input);

int is_valid_input(mysh_t *mysh, cmd_list_t *list);

void exec_cmd_list(mysh_t *mysh, cmd_list_t *list);


/*
**  pipe
*/
void swap_pipe(int **pipes);
void connect_pipe(int pipes[2][2], const int nb_pipes, const int n);
void close_pipe(int pipes[2][2], const int nb_pipes, const int n);
