/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_itoa
*/

#include "libmy.h"

void reverse(char *str, int i, int j)
{
    while (i < j)
        my_swap(&str[i++], &str[j--]);
}

char *my_itoa(int nb)
{
    int neg = my_isneg(nb);
    int len = my_nbrlen(nb);
    char *str = malloc(sizeof(char) * (len + 1));

    str[len] = '\0';
    if (nb == 0)
        str[0] = '0';
    if (neg) {
        str[0] = '-';
        nb *= -1;
    }
    --len;
    while (nb > 0){
        str[len] = (nb % 10) + 48;
        nb /= 10;
        --len;
    }
    return (str);
}
