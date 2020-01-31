/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "client.h"

void set_fds(t_fds *fds, int socket)
{
	FD_ZERO(&fds->read);
	FD_ZERO(&fds->write);
	FD_SET(0, &fds->read);
	FD_SET(1, &fds->write);
	FD_SET(socket, &fds->read);
	FD_SET(socket, &fds->write);
}