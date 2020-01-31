/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int my_fd_set (int *id, t_fds *fds)
{
	FD_SET(*id, &fds->read);
	FD_SET(*id, &fds->write);
	return (*id);
}

void fd_set_machine (t_machine *machine, t_fds *fds)
{
	int count = 1;

	reset_fd(fds);
	for (t_machine *tmp = machine; tmp; tmp = tmp->next)
		count = tmp->type != NONE ? my_fd_set(&tmp->id, fds) : count;
	fds->nbr = count;
}
