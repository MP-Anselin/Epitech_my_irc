/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void invite_answer (t_machine *client, char **arg)
{
	client->text = xstrdup("341 RPL_INVITING\r\n");
	client->text = xstrcat(client->text, " ");
	client->text = xstrcat(client->text, arg[1]);
	client->text = xstrcat(client->text, " ");
	client->text = xstrcat(client->text, arg[0]);
	client->text = xstrcat(client->text, "\r\n");
}

int error_invite (t_machine *client, t_machine *sender, char *user)
{
	if (check_use_channel(sender, user) != 1)
		client->text = xstrdup("443 ERR_USERONCHANNEL\r\n");
	else if (check_use_channel(client, user) != 1)
		client->text = xstrdup("442 ERR_NOTONCHANNEL\r\n");
	else
		return (0);
	return (1);
}

void command_invite (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	t_machine *sender;
	char **tab_error = msg_answer_error("461 ERR_TOOMUCHPARAMS\r\n",
					    "461 ERR_NEEDMOREPARAMS\r\n");

	if (check_nbr_arg(cmd->arg, client, tab_error, 2) == 1)
		return;
	sender = find_right_user(machine, cmd->arg[0]);
	if (sender) {
		if (error_invite(client, sender, cmd->arg[0]) == 1)
			return;
		sender->text = msg_answer(client->nick, cmd->arg[0], cmd->arg,
					  "INVITE");
		invite_answer(client, cmd->arg);
	}
	else
		client->text = xstrdup("401 ERR_NOSUCHNICK\r\n");
	(void) client;
}