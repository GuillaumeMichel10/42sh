/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_str_isnum
*/

#include "libmy.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; ++i) {
        if (!my_isdigit(str[i]) && str[i] != '-')
            return (0);
    }
    return (1);
}
