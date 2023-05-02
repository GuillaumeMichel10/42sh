/*
** EPITECH PROJECT, 2023
** string
** File description:
** my_isalpha
*/

int my_isalpha(char c)
{
    return ((c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z'));
}
