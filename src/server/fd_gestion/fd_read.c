/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void reading_analyst (t_machine *machine, t_machine *tmp)
{
	t_machine *client = find_client(machine, tmp->id);

	if (client == NULL)
		return;
	switch (tmp->type) {
		case SERVER:
			add_client(machine, tmp->id);
			break;
		case CLIENT:
			client_read_message(machine, client);
			break;
		default:
			break;
	}
}

void fd_read (t_machine *machine, t_fds *fds)
{
	for (t_machine *tmp = machine, *add; tmp; tmp = add) {
		add = tmp->next;
		if (FD_ISSET(tmp->id, &fds->read))
			reading_analyst(machine, tmp);
	}
}