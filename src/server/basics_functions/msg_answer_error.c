/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

char **msg_answer_error (char *first, char *second)
{
	char **tab_error = xmalloc(sizeof(char *) * 3);

	tab_error[0] = xstrdup(first);
	tab_error[1] = xstrdup(second);
	tab_error[2] = NULL;
	return (tab_error);
}