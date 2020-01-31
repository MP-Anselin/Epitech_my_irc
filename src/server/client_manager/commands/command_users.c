/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void catch_nickname_in_server (t_machine *tmp, t_machine *client)
{
	char *save;

	if (tmp->type == CLIENT) {
		if (!client->text)
			client->text = xstrdup(tmp->nick);
		else {
			save = client->text;
			client->text = xstrcat(client->text, "393 RPL_USERS :");
			free(save);
			save = client->text;
			client->text = xstrcat(client->text, tmp->nick);
			free(save);
			save = client->text;
			client->text = xstrcat(client->text, "\r\n");
			free(save);
		}
	}
}

void command_users (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	char *save;

	if (tablen(cmd->arg) > 1)
		client->text = xstrdup("461 ERR_TOOMUCHPARAMS\r\n");
	else {
		if (client->text)
			free(client->text);
		client->text = xstrdup("392 RPL_USERSSTART\r\n");
		for (t_machine *tmp = machine; tmp; tmp = tmp->next)
			catch_nickname_in_server(tmp, client);
		save = client->text;
		client->text = xstrcat(client->text, "394 RPL_ENDOFUSERS\r\n");
		free(save);
	}
}
