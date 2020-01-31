/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

char *fill_message (char **arg, int start)
{
	char *save = NULL;
	char *msg = NULL;

	if ((int) tablen(arg) < start || arg[start] == NULL)
		return (NULL);
	for (int y = start; arg[y]; y++) {
		save = msg != NULL ? xstrdup(msg) : save;
		msg = xmalloc(xstrlen(save) + xstrlen(arg[y]) + 2);
		if (save == NULL)
			msg = xstrdup(arg[y]);
		else
			sprintf(msg, "%s %s", save, arg[y]);
	}
	if (save)
		free(save);
	return (msg);
}