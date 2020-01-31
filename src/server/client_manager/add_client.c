/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void add_client (t_machine *machine, int socket)
{
	t_machine *client = init_machine();
	t_machine *tmp = machine;
	static int count = 0;
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);
	int acpt = accept(socket, (struct sockaddr *) &client_addr, &len);

	if (acpt == -1)
		exit_error("Client cannot be accept", -1);
	client->id = acpt;
	client->type = CLIENT;
	client->port = ntohs(client_addr.sin_port);
	client->host = xstrdup(inet_ntoa(client_addr.sin_addr));
	client->nick = NULL;
	client->real_name = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = client;
	count++;
	printf("New client connect\n");
}