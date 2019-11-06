/*
** EPITECH PROJECT, 2019
** init
** File description:
** init
*/

#include "myftp.h"

void    init_socket(void)
{
    struct protoent *_protoent = getprotobyname("TCP");
    size_t option = 0;

    if (_protoent == NULL) {
        printf("error");
        exit(84);
    }
    fd_server = socket(AF_INET, SOCK_STREAM, _protoent->p_proto);
    if (fd_server == -1) {
        printf("error");
        exit(84);
    }
    option = 1;
    if (setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR,
        (char *)&option, sizeof(option)) == -1) {
            printf("error");
            exit(84);
    }
}

void    init_port(int nb_ports)
{
    struct sockaddr_in  _sock_in;

    _sock_in.sin_family = AF_INET;
    _sock_in.sin_port = htons(nb_ports);
    _sock_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(fd_server, (const struct sockaddr *)&_sock_in,
        sizeof(_sock_in)) == -1) {
        if (close(fd_server) == -1) {
            printf("error");
            exit (84);
        }
        printf("error");
        exit(84);
    }
}

void listen_port(void)
{
    if (listen(fd_server, 10) == -1) {
        if (close(fd_server) == -1) {
            printf("error");
            exit(84);
        }
        printf("error");
        exit (84);
    }
}

void    check_error(void)
{
    if (close(fd_server) == -1) {
        printf("error");
        exit (84);
    }
    printf("error");
    exit (84);
}

void    do_client(void)
{
    struct sockaddr_in length_addr_client;
    socklen_t length_addr_sock = sizeof(length_addr_client);
    size_t inf = 42;

    while (inf) {
        fd_client = accept(fd_server, (struct sockaddr *)&length_addr_client,
        &length_addr_sock);
        if (fd_client == -1)
                check_error();
        else
            check_error_cl();
    }
}