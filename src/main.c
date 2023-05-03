/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include "../includes/mysh.h"

//void signal_handler(int signal)
//{
//    (void)signal;
//}

int main(int ac, char **av, char **environment)
{
    (void)av;
//    signal(SIGINT, signal_handler);

    if (ac != 1)
        return (84);
    mysh_t *mysh = setup(environment);
    loop(mysh);
    return (mysh->error);
}
