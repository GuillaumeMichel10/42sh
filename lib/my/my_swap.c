/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_swap
*/

void my_swap(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
}
