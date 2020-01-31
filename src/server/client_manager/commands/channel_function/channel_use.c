/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int check_use_channel (t_machine *client, char *channel)
{
	for (t_channel *tmp = client->channels; tmp; tmp = tmp->next)
		if (strcmp(tmp->name, channel) == 0)
			return (1);
	return (0);
}

int check_machine_channel (t_machine *machine, char *channel)
{
	for (t_machine *tmp = machine; tmp; tmp = tmp->next)
		if (tmp->type == CLIENT && check_use_channel(tmp, channel))
			return (1);
	return (0);
}