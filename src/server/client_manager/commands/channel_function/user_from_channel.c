/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void catch_user_from_channel (t_machine *tmp, t_machine *client, char *channel,
			      char *code)
{
	if (tmp->type == CLIENT && check_use_channel(tmp, channel) == 1) {
		client->text = xstrcat(client->text, code);
		client->text = xstrcat(client->text, tmp->nick);
		client->text = xstrcat(client->text, "\r\n");
	}
}
