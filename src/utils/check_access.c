/*
** EPITECH PROJECT, 2023
** src
** File description:
** list_environment
*/

#include "../../includes/mysh.h"

error_m is_file_accessible(char *path)
{
    struct stat st;

    if (stat(path, &st) != 0)
        return (ERR_NO_SUCH_FILE_OR_DIRECTORY);
    if (!S_ISREG(st.st_mode) || access(path, F_OK | X_OK) == -1)
        return (ERR_PERM_DENIED);
    return (ERR_OK);
}

error_m is_directory_accessible(char *path)
{
    struct stat st;

    if (stat(path, &st) != 0)
        return (ERR_NO_SUCH_FILE_OR_DIRECTORY);
    if (!S_ISDIR(st.st_mode))
        return (ERR_NOT_A_DIRECTORY);
    return (ERR_OK);
}
