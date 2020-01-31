/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void analyse_type_msg (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	if (check_machine_channel(machine, cmd->arg[0]))
		command_msg_channel(machine, cmd, client);
	else if (command_privmsg_user(machine, client, cmd) != 0)
		command_msg_channel(machine, cmd, client);
}

void message_manager (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	if (tablen(cmd->arg) < 2)
		client->text = xstrdup("404 ERR_NEEDMOREPARAME\n");
	else
		analyse_type_msg(machine, client, cmd);
}
