/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

char *msg_answer (char *sender, char *dest, char **arg, char *cmd)
{
	char *answer = NULL;
	char *msg = NULL;

	answer = xmalloc(xstrlen(sender) + xstrlen(dest) +
			 xstrlen(arg[0]) + 20);
	msg = fill_message(arg, 1);
	sprintf(answer, ":%s %s %s %s\r\n", sender, cmd,
		dest, msg);
	if (msg)
		free(msg);
	return (answer);
}