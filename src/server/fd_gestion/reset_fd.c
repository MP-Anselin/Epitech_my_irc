/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void reset_fd (t_fds *fds)
{
	FD_ZERO(&fds->read);
	FD_ZERO(&fds->write);
}