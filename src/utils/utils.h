/*
** EPITECH PROJECT, 2023
** src
** File description:
** builtin
*/

#pragma once

#include "../../includes/include.h"

typedef enum error_e error_m;

/*
**  check access
*/

error_m is_file_accessible(char *path);
error_m is_directory_accessible(char *path);

/*
**  display error
*/

void display_error(char *str, error_m error);
