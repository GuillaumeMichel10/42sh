/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_str_to_word_array
*/

#include "libmy.h"

char *extract_word(char **str, const char *delimiters)
{
    int len = my_strclen(*str, delimiters);
    char *cpy = malloc(sizeof(char) * (len + 1));

    cpy[len] = '\0';
    for (int i = 0; **str && !my_strchr(**str, delimiters); ++i) {
        cpy[i] = **str;
        ++(*str);
    }
    return (cpy);
}

char **my_str_to_word_array(char *str, const char *delimiters, size_t *n)
{
    char *ptr = str;
    char **tab = NULL;
    int k = count_words(str, delimiters);

    tab = malloc(sizeof(char *) * (k + 1));
    tab[k] = NULL;
    for (int i = 0; i < k; ++i) {
        while (*ptr && my_strchr(*ptr, delimiters))
            ++ptr;
        tab[i] = extract_word(&ptr, delimiters);
    }
    if (n)
        *n = k;
    return (tab);
}
