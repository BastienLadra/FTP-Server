/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_

#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <unistd.h>
#include <stdbool.h>

/*******************
        INIT
*******************/
void    help_av(void);
void    init_socket(void);
void    init_port(int);
void    listen_port(void);
void    do_client(void);

/********************
        MYFTP
********************/

int	myftp(void);
int     fd_server;
int     fd_client;
int     login;
void    check_error_cl(void);
void    check_error_getline(FILE *_file, char *);

/**********************
        CMD
**********************/
void	user(char *_cmd_);
void	pass(char *_cmd_);
void	quit(char *_cmd_);
void	help(char *_cmd_);
void	noop(char *_cmd_);
void	cwd(char *_cmd_);
void	cdup(char *_cmd_);
void	pwd(char *_cmd_);
void    dele(char *_cmd_);

typedef struct  s_cmd
{
    char *cmd_name;
    void  (*ptr)(char *_cmd_);
    int    connect;
} t_cmd;

#endif /* !MYFTP_H_ */