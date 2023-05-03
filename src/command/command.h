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
**  command_list
*/

typedef struct command_node_s {
    struct command_node_s *next;
    struct command_node_s *prev;
    char **text;
    char *str;
    int size;
}command_node_t;

typedef struct command_list_s {
    command_node_t *first;
    command_node_t *last;
    command_node_t *(*new)(char **, int);
    void (*add)(struct command_list_s *, command_node_t *);
    int size;
}command_list_t;

command_list_t *new_command_list(void);

/*
**  command_heap
*/

typedef struct command_heap_s {
    command_list_t **tab;
    int size;
    int capacity;
    void (*free)(struct command_heap_s *);
    void (*add)(struct command_heap_s *, command_list_t *);
}command_heap_t;

command_heap_t new_command_heap(int capacity);

/*
** command_validation
*/

error_m test_redirections(command_list_t *list);
int test_command(mysh_t *mysh, command_list_t *list);



void handle_command(mysh_t *mysh, char *input);

error_m get_command(command_heap_t *heap, char **command);

void exec_command_list(mysh_t *mysh, command_list_t *list);


/*
**  pipe
*/
void swap_pipe(int **pipes);
void connect_pipe(int pipes[2][2], const int nb_pipes, const int n);
void close_pipe(int pipes[2][2], const int nb_pipes, const int n);
