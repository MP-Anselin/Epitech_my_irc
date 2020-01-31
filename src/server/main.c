/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int is_tap_help (int nbr, char **av)
{
	for (int i = 1; i < nbr; ++i) {
		if (strcmp(av[i], "-help") == 0)
			return (1);
	}
	return (0);
}

int invalid ()
{
	fprintf(stderr, "Server : invalid command \n");
	fprintf(stderr, "Run : \"Sever -help \" for more information\n");
	return (84);
}

int help ()
{
	printf("USAGE: ./sever port\n");
	return (0);
}

int main (int ac, char **av)
{
	if (is_tap_help(ac, av) == 1)
		return (help());
	if (ac != 2)
		return (invalid());
	server(atoi(av[1]));
	return (0);
}