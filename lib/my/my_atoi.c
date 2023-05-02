/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_atoi
*/

#include "libmy.h"

int my_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    int digit = 0;

    while (str[i] && str[i] == ' ')
        ++i;
    if (str[i] == '-' || str[i] == '+')
        sign = (str[i++] == '-') ? -1 : 1;
    while (str[i] && my_isdigit(str[i])) {
        digit = str[i++] - '0';
        if (result > INT_MAX / 10 ||
        (result == INT_MAX / 10 && digit > INT_MAX % 10)){
            return (sign == -1) ? INT_MIN : INT_MAX;
        }
        result = result * 10 + digit;
    }
    result *= sign;
    return (result);
}
