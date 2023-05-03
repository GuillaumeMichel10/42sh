/*
** EPITECH PROJECT, 2023
** src
** File description:
** builtin
*/

#pragma once

#include "../../includes/include.h"

typedef struct mysh_s mysh_t;

/*
**  built_in
*/

typedef struct built_in_t {
    char *name;
    int (*ptr)(mysh_t *, command_node_t *);
    bool exit_status;
}built_in_t;

int is_echo(char *str);
int is_builtin(char *str);
int builtin(mysh_t *mysh, command_node_t *node);

int my_echo(mysh_t *mysh, command_node_t *node);
int my_cd(mysh_t *mysh, command_node_t *node);
int my_setenv(mysh_t *mysh, command_node_t *node);
int my_unsetenv(mysh_t *mysh, command_node_t *command);
int my_environment(mysh_t *mysh, command_node_t *node);
int my_exit(mysh_t *mysh, command_node_t *command);
