/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int check_nickname_char (char *str)
{
	if (xstrlen(str) > 9)
		return (1);
	if ((str[0] < 'A' || str[0] > 'Z') && (str[0] < 'a' || str[0] > 'z'))
		return (1);
	for (int x = 0; str[x]; x++)
		if ((str[x] < 'A' || str[x] > '}') &&
		    (str[x] < '0' || str[x] > '9') && str[x] != '-')
			return (1);
	return (0);
}

int check_channel_char (char *str)
{
	int len = xstrlen(str);

	if ((len > 50 || len == 1) || (str[0] != '!' &&
				       str[0] != '#' && str[0] != '&' &&
				       str[0] != '+'))
		return (1);
	for (int x = 1; str[x]; x++) {
		if (str[x] == ',' || str[x] == ':' ||
		    str[x] == '\a' || str[x] == '\r' ||
		    str[x] == '\n')
			return (1);
	}
	return (0);
}