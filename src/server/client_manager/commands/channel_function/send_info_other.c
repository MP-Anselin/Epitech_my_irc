/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void send_to_other (t_machine *tmp, char *channel, char *save)
{
	if (tmp->type == CLIENT && check_use_channel(tmp, channel)) {
		if (!tmp->text)
			free(tmp->text);
		tmp->text = xstrdup(save);
	}
}

void welcome_other (t_machine *machine, char *channel, char *save, char *name)
{
	for (t_machine *tmp = machine; tmp; tmp = tmp->next) {
		if (tmp->nick && strcmp(tmp->nick, name))
			send_to_other(tmp, channel, save);
	}
	(void) name;
}