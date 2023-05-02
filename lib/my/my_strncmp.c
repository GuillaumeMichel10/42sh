/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_strcmp
*/

int my_strncmp(const char *str1, const char *str2, const int n)
{
    int i = 0;
    int x = 0;

    while (str1[i] && str2[x] && i < n){
        if (str1[i] == str2[x]){
            ++i;
            ++x;
            continue;
        }
        if (str1[i] > str2[x])
            return (1);
        return (-1);
    }
    return 0;
}
