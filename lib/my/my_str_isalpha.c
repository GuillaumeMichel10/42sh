/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_str_isalpha
*/

#include "libmy.h"

int my_str_isalpha(const char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (!my_isalpha(str[i]) && !my_isdigit(str[i]) && str[i] != '_')
            return (0);
    }
    return (1);
}
