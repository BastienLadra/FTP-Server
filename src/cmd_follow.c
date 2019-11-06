/*
** EPITECH PROJECT, 2019
** cmd_follow
** File description:
** cmd_follow
*/

#include "myftp.h"

void	noop(char *_cmd_)
{
    (void)_cmd_;
    dprintf(fd_client, "200\n");
}

void	cwd(char *_cmd_)
{
    char *directory = NULL;

    directory = strtok_r(_cmd_, " ", &_cmd_);
    (void)directory;
    if (open(_cmd_, O_RDONLY) == 0)
        dprintf(fd_client, "250\n");
    else
        dprintf(fd_client, "250\n");
}

void	cdup(char *_cmd_)
{
    (void)_cmd_;
    if (chdir("..") == -1)
        dprintf(fd_client, "xxx\n");
    else
        dprintf(fd_client, "200\n");
}

void	pwd(char *cmd)
{
    char *buffer = NULL;

    (void)cmd;
    buffer = getcwd(buffer, 4096);
    dprintf(fd_client, "%s%s\n", "257 " , buffer);
    free(buffer);
}

void    dele(char *_cmd_)
{
    char *buffer = NULL;
    int fd = 0;

    buffer = strtok_r(_cmd_, " ", &_cmd_);
    if (buffer) {
        fd = open(buffer, O_RDONLY);
        if (fd == -1) {
            close(fd);
            remove(buffer);
            dprintf(fd_client, "250\n");
            return;
        }
    }
    dprintf(fd_client, "xxx\n");
}