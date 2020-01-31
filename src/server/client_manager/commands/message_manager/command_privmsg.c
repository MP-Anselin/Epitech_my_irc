/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int command_privmsg_user (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	t_machine *sender = find_right_user(machine, cmd->arg[0]);
	(void) client;

	if (sender) {
		sender->text = msg_answer(client->nick, cmd->arg[0], cmd->arg,
					  "PRIVMSG");
		return (0);
	}
	return (1);
}