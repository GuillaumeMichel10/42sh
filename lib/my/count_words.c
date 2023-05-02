/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** count_sentences
*/

#include "libmy.h"

int count_words(const char *str, const char *delimiters)
{
    int k = 0;
    int in_word = 0;

    for (int i = 0; str[i]; ++i) {
        if (my_strchr(str[i], delimiters)) {
            in_word = 0;
            continue;
        }
        if (!in_word) {
            ++k;
            in_word = 1;
        }
    }
    return (k);
}
