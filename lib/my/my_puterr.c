/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_puterr
*/

#include "libmy.h"

void my_puterr(const char *str)
{
    int backslash = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == '\\') {
            ++backslash;
        } else {
            backslash = 0;
        }
        if (backslash && backslash != 2)
            continue;
        my_putchar(str[i]);
    }
}
