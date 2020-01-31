/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int check_nbr_arg (char **arg, t_machine *client, char **tab_error, size_t nbr)
{
	if (tablen(arg) > nbr)
		client->text = xstrdup(tab_error[0]);
	else if (arg[0] == NULL || (nbr > 1 && arg[1] == NULL))
		client->text = xstrdup(tab_error[1]);
	else {
		free_tab(tab_error);
		return (0);
	}
	free_tab(tab_error);
	return (1);
}