/*
** EPITECH PROJECT, 2023
** src
** File description:
** erase_row
*/

#include "utils.h"

void erase_row(char **text, size_t n)
{
    for (size_t j = 0; j < n; ++j) {
        for (int i = 0; text[i]; ++i) {
            text[i] = text[i + 1];
        }
    }
}
