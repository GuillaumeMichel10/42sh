/*
** EPITECH PROJECT, 2023
** src
** File description:
** my_cd
*/

#include "../../includes/mysh.h"

char *get_current_working_directory(void)
{
    char *cwd = NULL;
    size_t size = 256;

    while (1) {
        cwd = malloc(sizeof(char) * size);
        if (getcwd(cwd, 256) != NULL)
            break;
        free(cwd);
        size *= 2;
    }
    return (cwd);
}

int my_cd_home(mysh_t *mysh, char *cwd)
{
    int return_value = SUCCESS;

    if (chdir(mysh->home) == -1) {
        display_error("cd", ERR_NO_HOME_DIRECTORY);
        free (cwd);
        return_value = FAILURE;
    }

    return (return_value);
}

int my_cd_with_args(mysh_t *mysh, char *path, char *cwd)
{
    int return_value = SUCCESS;
    error_m error = is_directory_accessible(path);

    if (error == ERR_OK) {
        if (chdir(path) == -1) {
            free (cwd);
            return_value = FAILURE;
        } else{
            free(mysh->oldpwd);
            mysh->oldpwd = cwd;
        }
    } else {
        display_error(path, error);
        free (cwd);
        return_value = FAILURE;
    }
    return (return_value);
}

int my_cd(mysh_t *mysh, command_node_t *node)
{
    int return_value = SUCCESS;
    char *cwd = get_current_working_directory();

    switch (node->size) {
        case 1 :
            return_value = my_cd_home(mysh, cwd);
            break;
        case 2 :
            if (my_strcmp(node->text[1], "-") == 0) {
                return_value = my_cd_with_args(mysh, mysh->oldpwd, cwd);
            } else {
                return_value = my_cd_with_args(mysh, node->text[1], cwd);
            }
            break;
        default:
            display_error("cd", ERR_TOO_MANY_ARGUMENTS);
            free(cwd);
            return_value = FAILURE;
    }
    return (return_value);
}
