/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_strstr
*/

#include "libmy.h"


char *my_strstr(char *str, const char *to_find)
{
    int str_len = my_strlen(str);
    int to_find_len = my_strlen(to_find);

    if (to_find_len > str_len)
        return (NULL);

    for (int i = 0; i <= str_len - to_find_len; i++) {
        if (my_strncmp(str + i, to_find, to_find_len) == 0) {
            return (str + i);
        }
    }

    return (NULL);
}
