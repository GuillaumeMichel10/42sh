/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_str_isnum
*/

#include "libmy.h"

int nb_replace(char *str, char *to_find, int to_findlen)
{
    int nb_replace = 0;

    for (char *ptr = str; (ptr = my_strstr(ptr, to_find)) != NULL; ) {
        ptr += to_findlen;
        ++nb_replace;
    }

    return (nb_replace);
}

char *my_str_replace(char *input, char *replace, char *to_find)
{
    int inputlen = my_strlen(input);
    int replacelen = my_strlen(replace);
    int to_findlen = my_strlen(to_find);
    int resultlen = inputlen + (replacelen - to_findlen)
        * nb_replace(input, to_find, to_findlen);;
    char *result = malloc(sizeof(char) * (resultlen + 1));
    int n = 0;

    result[resultlen] = '\0';
    for (int a = 0; n < inputlen; ) {
        if (my_strncmp(input + n, to_find, to_findlen)) {
            result[a++] = input[n++];
            continue;
        }
        for (int k = 0; replace[k]; ++k, ++a) {
            result[a] = replace[k];
        }
        n += to_findlen;
    }
    return (result);
}
