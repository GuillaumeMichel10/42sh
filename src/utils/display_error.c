/*
** EPITECH PROJECT, 2023
** src
** File description:
** display_error
*/

#include "../../includes/mysh.h"

static char *const errors[] = {
    "",
    ": Command not found.\n",
    ": Permission denied.\n",
    "Invalid null command.\n",
    "Ambiguous output redirect.\n",
    "Ambiguous input redirect.\n",
    "Missing name for redirect.\n",
    "Too many ('s",
    "Too many )'s",
    "Badly placed ()'s",
    "Command line too long",
    "Illegal variable name",
    "Command argument syntax error",
    "Alias loop detected",
    "Illegal variable reference",
    "History expansion error",
    ": Expression Syntax.\n",
    ": Badly formed number.\n",
    "Badly formed glob",
    "No match",
    "Syntax error: Unterminated quoted string",
    "Syntax error: Unexpected end of file",
    ": Undefined variable.\n",
    ": No home directory.\n",
    ": Not a directory.\n",
    ": No such file or directory.\n",
    ": Variable name must begin with a letter.\n",
    ": Variable name must contain alphanumeric characters.\n",
    ": Too many arguments.\n",
    ": Too few arguments.\n"
};

void display_error(char *str, error_m error)
{
    if (str)
        my_puterr(str);
    my_puterr(errors[(int)error]);
}
