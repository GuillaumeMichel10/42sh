/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_strchr
*/

#include "libmy.h"

char *my_strchr(const char c, const char *delimiters)
{
    char *p = (char *)delimiters;

    while (*p) {
        if (*p == (char)c) {
            return p;
        }
        ++p;
    }
    return (NULL);
}
