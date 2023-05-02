/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_strccpy
*/

#include "libmy.h"

char *my_strccpy(const char *str, const char *delimiters)
{
    int len = my_strclen(str, delimiters);
    char *cpy = malloc(sizeof(char) * len + 1);

    cpy[len] = '\0';
    for (int i = 0; i < len; ++i)
        cpy[i] = str[i];

    return (cpy);
}
