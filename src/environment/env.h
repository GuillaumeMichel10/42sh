/*
** EPITECH PROJECT, 2023
** src
** File description:
** mysh
*/

#pragma once

#include "../../includes/include.h"

typedef struct mysh_s mysh_t;

typedef struct env_node_s {
    struct env_node_s *next;
    struct env_node_s *prev;
    char **text;
    char *str;
    int len;
}env_node_t;

typedef struct env_list_s {
    int size;
    env_node_t *first;
    env_node_t *last;
    env_node_t *(*new)(char **, int);
    void (*add)(struct env_list_s *, env_node_t *);
}env_list_t;

env_list_t *new_env_list(void);

env_list_t *new_env(char **env);

void update_env(mysh_t *mysh);
