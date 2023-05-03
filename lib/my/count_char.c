/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** count_char
*/

int count_char(char *str, const char c)
{
    int k = 0;

    for (int i = 0; str[i]; ++i) {
        if (c == str[i])
            ++k;
    }

    return (k);
}
