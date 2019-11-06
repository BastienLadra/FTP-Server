/*
** EPITECH PROJECT, 2019
** check_error
** File description:
** check_error
*/

#include "myftp.h"

void    check_error_cl(void)
{
    if (fork() == 0)
        myftp();
    else
        if (close(fd_client) == -1) {
            printf("error");
            exit (84);
        }
}