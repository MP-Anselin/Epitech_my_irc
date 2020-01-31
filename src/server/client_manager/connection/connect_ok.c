/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void connect_ok (t_machine *client)
{
	if (client->isco != CONNECT && client->nick_co == 1) {
		if (client->text == NULL)
			client->text = xstrdup("001 RPL_WELCOME\r\n");
		else
			client->text = xstrcat(client->text,
					       "001 RPL_WELCOME\r\n");
		client->isco = CONNECT;
	}
}
