/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int k = 0;

    if (!str)
        return (0);

    while (str[k])
        ++k;

    return (k);
}
