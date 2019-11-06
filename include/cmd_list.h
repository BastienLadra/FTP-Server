/*
** EPITECH PROJECT, 2019
** cmd_list
** File description:
** cmd_list
*/

#include "myftp.h"

#ifndef CMD_LIST_H_
    #define CMD_LIST_H_


t_cmd cmd_list[9] = {{"USER", &user, 0}, {"PASS", &pass, 0},
                    {"CWD", &cwd, 1}, {"CDUP", &cdup, 1},
                    {"QUIT", &quit, 0}, {"PWD", &pwd, 1},
                    {"HELP", &help, 0}, {"NOOP", &noop, 0},
                    {"DELE", &dele, 1}};

#endif /* !CMD_LIST_H_ */
