/*
** EPITECH PROJECT, 2019
** cmd
** File description:
** cmd
*/

#include "myftp.h"

void	user(char *_cmd_)
{
    char *buffer_split = NULL;

    (void)buffer_split;
    buffer_split = strtok_r(_cmd_, " ", &_cmd_);
    login = 1;
    if ((strncmp(_cmd_, "Anonymous", 9)) == 0)
        login = 0;
    dprintf(fd_client, "331\n");
}

void	pass(char *_cmd_)
{
    (void)_cmd_;
    if (login == 0) {
        login = 2;
        dprintf(fd_client, "230\n");
    } else
        dprintf(fd_client, "530\n");
}

void	quit(char *_cmd_) {
    (void) _cmd_;
    dprintf(fd_client, "221\n");
    close(fd_client);
}

void help2(char *_cmd_)
{
    (void)_cmd_;
    dprintf(fd_client, "214 HELP [<SP> <string>] <CRLF>\t  :");
    dprintf(fd_client, " List available commands\r\n");
    dprintf(fd_client, "214 NOOP <CRLF>\t\t\t  : Do nothing\r\n");
    dprintf(fd_client, "214 RETR <SP> <pathname> <CRLF>\t  ");
    dprintf(fd_client, ": Download file from");
    dprintf(fd_client, " server to client\r\n");
    dprintf(fd_client, "214 STOR <SP> <pathname> <CRLF>\t  :");
    dprintf(fd_client, " Upload file from client");
    dprintf(fd_client, " to server\r\n");
    dprintf(fd_client, "214 LIST [<SP> <pathname>] <CRLF> : List files in");
    dprintf(fd_client, " the current working directory\r\n");
}

void	help(char *_cmd_)
{
    (void)_cmd_;
    dprintf(fd_client, "214 Help message. \r\n");
    dprintf(fd_client, "214 USER <SP> <username> <CRLF>\t  : Specify user for");
    dprintf(fd_client, " authentication\r\n");
    dprintf(fd_client, "214 PASS <SP> <password> <CRLF>\t  : Specify password");
    dprintf(fd_client, " authentication\r\n");
    dprintf(fd_client, "214 CWD  <SP> <pathname> <CRLF>\t  : Change working");
    dprintf(fd_client, " directory\r\n");
    dprintf(fd_client, "214 CDUP <CRLF>\t\t\t  : Change working directory");
    dprintf(fd_client, " to parent directory\r\n");
    dprintf(fd_client, "214 QUIT <CRLF>\t\t\t  : Disconnection\r\n");
    dprintf(fd_client, "214 DELE <SP> <pathname> <CRLF>\t  : Delete file");
    dprintf(fd_client, " on the server\r\n");
    dprintf(fd_client, "214 PWD  <CRLF>\t\t\t  : Print working directory\r\n");
    dprintf(fd_client, "214 PASV <CRLF>\t\t\t  : Enable \"passive\" mode for");
    dprintf(fd_client, " data transfer\r\n");
    dprintf(fd_client, "214 PORT <SP> <host-port> <CRLF>  : Enable \"active\"");
    dprintf(fd_client, " mode for data transfer\r\n");
    help2(_cmd_);
}
