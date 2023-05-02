/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCY-2-1-minishell1-guillaume.michel
** File description:
** my_concat
*/

#include "libmy.h"

int concat_len(int count, va_list ap)
{
    int len = 0;
    char *str = 0;

    for (int i = 0; i < count; i++){
        str = va_arg(ap, char *);
        if (str){
            len += my_strlen(str);
        }
    }

    return (len);
}

char *my_concat(int count, ...)
{
    va_list ap;
    int len = 0;
    char *result = 0;
    char *c = 0;
    char *str = 0;

    va_start(ap, count);
    len = concat_len(count, ap);
    va_end(ap);
    c = result = malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    va_start(ap, count);
    for (int i = 0; i < count; i++){
        if (!(str = va_arg(ap, char *)))
        continue;
        while (*str)
            *c++ = *str++;
    }
    va_end(ap);
    return (result);
}
