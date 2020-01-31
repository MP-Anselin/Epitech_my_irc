/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

int select_client (t_fds *fds)
{
	struct timeval tv;
	int select_val = 0;

	tv.tv_sec = 10;
	tv.tv_usec = 0;
	select_val = select(fds->nbr + 1, &fds->read, &fds->write, NULL, &tv);
	if (select_val == -1) {
		fprintf(stderr, "Error :  Select failed");
		return (1);
	}
	return (0);
}
