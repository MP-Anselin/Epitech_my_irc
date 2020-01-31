/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void client_send_message (t_machine *client)
{
	if (client->text == NULL)
		return;
	printf("\t\t MSG SEND ->> '%s'\n", client->text);
	write(client->id, client->text, strlen(client->text) + 1);
	free(client->text);
	client->text = NULL;
}