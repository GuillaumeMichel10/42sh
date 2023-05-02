/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_strclen
*/

#include "libmy.h"

int my_strclen(const char *str, const char *delimiters)
{
    int k = 0;

    while (str[k] && !my_strchr(str[k], delimiters))
        ++k;

    return (k);
}
