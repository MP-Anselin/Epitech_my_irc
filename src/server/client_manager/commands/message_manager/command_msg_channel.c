/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void send_to_the_channel (t_machine *tmp, t_cmd *cmd, t_machine *client)
{
	if (tmp->type == CLIENT && check_use_channel(tmp, cmd->arg[0]) &&
		strcmp(client->nick, tmp->nick)) {
		if (!tmp->text)
			free(tmp->text);
		tmp->text = msg_answer(client->nick, cmd->arg[0], cmd->arg,
				       "PRIVMSG");
	}
}

void command_msg_channel (t_machine *machine, t_cmd *cmd, t_machine *client)
{
	for (t_machine *tmp = machine; tmp; tmp = tmp->next)
		send_to_the_channel(tmp, cmd, client);
}