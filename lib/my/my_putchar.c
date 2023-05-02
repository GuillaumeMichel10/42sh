/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_putchar
*/

#include "libmy.h"

void my_putchar(const char c)
{
    write(1, (char[1]){c}, 1);
}
