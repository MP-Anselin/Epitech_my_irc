/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int is_connect (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	if (client->isco == CONNECT)
		return (client->isco);
	else if (strcmp(cmd->command, "NICK") && strcmp(cmd->command, "USER")) {
		client->text = xstrdup("451 ERR_NOTREGISTERED\r\n");
		return (-1);
	}
	(void) machine;
	return (client->isco);
}