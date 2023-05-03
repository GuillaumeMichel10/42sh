/*
** EPITECH PROJECT, 2023
** src
** File description:
** mysh
*/

#pragma once

#include "../../includes/include.h"

typedef struct mysh_s mysh_t;

typedef struct environment_node_s {
    struct environment_node_s *next;
    struct environment_node_s *prev;
    char *text[2];
    char *str;
    int len;
}environment_node_t;

typedef struct environment_list_s {
    int size;
    environment_node_t *first;
    environment_node_t *last;
    environment_node_t *(*new)(void);
    void (*add)(struct environment_list_s *, environment_node_t *);
}environment_list_t;

environment_list_t *new_environment_list(void);

environment_list_t *new_environment(char **environment);

void update_environment(mysh_t *mysh);
