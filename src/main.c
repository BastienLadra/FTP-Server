/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** myftp
*/

#include "myftp.h"

void    init_necessary_to_ftp(int nb_ports)
{
    init_socket();
    init_port(nb_ports);
    listen_port();
    do_client();
}

int main(int ac, char **av)
{
    int nb_ports;

    if ((atoi(av[1])) == -1)
        return (84);
    nb_ports = atoi(av[1]);
    if (ac > 3 || ac < 2)
        return (84);
    if ((strcmp(av[1], "-help")) == 0) {
        help_av();
        return (0);
    }
    if (ac == 3)
        init_necessary_to_ftp(nb_ports);
}