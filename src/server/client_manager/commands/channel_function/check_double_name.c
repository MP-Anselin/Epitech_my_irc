/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int check_double (t_channel **info, char *channel)
{
	t_channel *tmp_bis = *info;
	t_channel *tmp = *info;
	t_channel *add;

	while (tmp_bis) {
		if (tmp_bis->name &&
		    strcmp(tmp_bis->name, channel) == 0)
			return (1);
		tmp_bis = tmp_bis->next;
	}
	add = init_struct_channel();
	add->name = xstrdup(channel);
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = add;
	else
		*info = add;
	return (0);
}