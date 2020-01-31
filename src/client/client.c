/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "client.h"

int connect_server (t_client *client, char *host, int port)
{
	int save_last_socket;

	client->server.sin_family = AF_INET;
	client->server.sin_port = htons(port);
	client->server.sin_addr.s_addr = inet_addr(host);
	save_last_socket = client->sock;
	client->sock = getsocket();
	if (connect(client->sock, (struct sockaddr *) &client->server,
		    sizeof(struct sockaddr_in)) == -1) {
		client->sock = save_last_socket;
		return (-1);
	}
	else {
		close(save_last_socket);
		return (1);
	}
}

void handle_client (t_client *client, t_fds *fds)
{
	set_fds(fds, client->sock);
	if (select_client(fds) == 0) {
		client_reads_info(fds, client);
		if (client->msg_client) {
			if (strcmp(client->msg_client, "/quit") == 0)
				return;
			handle_commands(client);
			client->msg_client = NULL;
		}
		else if (client->msg_server) {
			translate(g_error_msgs, &client->msg_server);
			client->msg_server = NULL;
		}
	}
	usleep(15000);
}

void client ()
{
	t_client client;
	t_fds fds;

	init_struct_client(&client);
	fds.nbr = 120;
	while (1) {
		handle_client(&client, &fds);
	}
}
