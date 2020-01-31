/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

t_channel *init_struct_channel ()
{
	t_channel *chan = xmalloc(sizeof(t_channel));

	chan->name = NULL;
	chan->topic = NULL;
	chan->pass = NULL;
	chan->next = NULL;
	return (chan);
}