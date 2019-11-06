/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** myftp
*/

#include "myftp.h"
#include "cmd_list.h"

char    *split_my_cmd(char *buffer)
{
    size_t length = strlen(buffer);
    size_t  length_1 = buffer[length - 1];

    if (length > 0 && length_1 == '\n' ) {
        length_1 = '\0';
    }
    if (length > 0 && length_1 == '\r' ) {
        length_1 = '\0';
    }
    return (buffer);
}

void    verifi(bool ok, char *write_in_cmd)
{
    if (ok == false) {
        dprintf(fd_client, "500\n");
    }
    free(write_in_cmd);
}

void    loop(size_t index, char *write_in_cmd)
{
    if (cmd_list[index].connect == 1 && login != 2)
        dprintf(fd_client, "530\n");
    else
        cmd_list[index].ptr(write_in_cmd);
}

void    check_cmd(char *buffer)
{
    char *string_split;
    char *write_in_cmd;
    size_t index = 0;
    bool ok = false;

    buffer = split_my_cmd(buffer);
    string_split = buffer;
    write_in_cmd = strdup (buffer);

    while (index < 9) {
            if (string_split != NULL && strncmp(string_split,
            cmd_list[index].cmd_name, strlen(cmd_list[index].cmd_name)) == 0) {
                loop(index, write_in_cmd);
                ok = true;
                break;
            }
            index++;
    }
    verifi(ok, write_in_cmd);
}

int		myftp(void)
{
    char *buffer = NULL;
    size_t index = 0;
    size_t inf = 42;
    FILE *_file;

    dprintf(fd_client, "220\n");
    _file = fdopen(dup(fd_client), "r");

    while (inf) {
        if ((getline(&buffer, &index, _file)) == -1) {
            fclose(_file);
            free(buffer);
        }
        check_cmd(buffer);
        if (strncmp(buffer, "QUIT", 4) == 0)
            break;
    }
    free(buffer);
    fclose(_file);
    exit (0);
}