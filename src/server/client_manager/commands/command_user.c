/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void add_real_name (t_machine *client, char *real)
{
	int i = 0;

	if (real[0] == ':') {
		client->real_name = xmalloc(sizeof(real));
		for (int x = 1; real[x]; x++, i++)
			client->real_name[i] = real[x];
		client->real_name[i] = '\0';
	}
	else
		client->real_name = xstrdup(real);
	printf("client real name ->>> '%s'\n", client->real_name);
}

void command_user (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	(void) machine;
	if (tablen(cmd->arg) != 4)
		client->text = xstrdup("461 ERR_NEEDMOREPARAMS\r\n");
	else if (client->real_name != NULL && client->nick != NULL)
		client->text = xstrdup("462 ERR_ALREADYREGISTRED\r\n");
	else {
		client->user = xstrdup(cmd->arg[0]);
		client->mode = xstrdup(cmd->arg[1]);
		client->unused = xstrdup(cmd->arg[2]);
		add_real_name(client, cmd->arg[3]);
		client->use_co = 1;
	}
}
