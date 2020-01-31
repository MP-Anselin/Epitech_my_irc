/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include <stdio.h>
#include <stdlib.h>

void exit_error (char *msg, int nbr)
{
	fprintf(stderr, "[Error] : %s", msg);
	exit(nbr);
}
