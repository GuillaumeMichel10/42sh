/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_strcpy
*/

#include "libmy.h"

char *my_strcpy(const char *str)
{
    int len = 0;
    char *cpy = NULL;

    if (!str)
        return (NULL);

    len = my_strlen(str);
    cpy = malloc(sizeof(char) * len + 1);

    cpy[len] = '\0';
    for (int i = 0; str[i]; ++i)
        cpy[i] = str[i];

    return (cpy);
}
