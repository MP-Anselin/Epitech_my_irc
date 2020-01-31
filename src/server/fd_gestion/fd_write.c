/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void writing_analyst (t_machine *machine, t_machine *tmp)
{
	t_machine *client = find_client(machine, tmp->id);

	if (client == NULL)
		return;
	switch (tmp->type) {
		case CLIENT:
			client_send_message(client);
			break;
		default:
			break;
	}
}

void fd_write (t_machine *machine, t_fds *fds)
{
	for (t_machine *tmp = machine; tmp; tmp = tmp->next) {
		if (FD_ISSET(tmp->id, &fds->write))
			writing_analyst(machine, tmp);
	}
}