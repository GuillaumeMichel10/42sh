/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_strcmp
*/

int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;
    int x = 0;

    while (str1[i] && str2[x]){
        if (str1[i] == str2[x]){
            ++i;
            ++x;
            continue;
        }
        if (str1[i] > str2[x])
            return (1);
        return (-1);
    }
    if (str1[i])
        return 1;
    if (str2[x])
        return -1;
    return 0;
}
