/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

t_machine *find_client (t_machine *machine, int id)
{
	for (t_machine *tmp = machine; tmp; tmp = tmp->next)
		if (tmp->id == id)
			return (tmp);
	return (NULL);
}

t_machine *find_right_user (t_machine *machine, char *user)
{
	for (t_machine *tmp = machine; tmp; tmp = tmp->next)
		if (tmp->type == CLIENT && strcmp(tmp->nick, user) == 0)
			return (tmp);
	return (NULL);
}