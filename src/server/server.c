/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void run_server (t_machine *machine)
{
	t_fds *fds = xmalloc(sizeof(t_fds));

	while (1) {
		fd_set_machine(machine, fds);
		if (select_client(fds) == 0) {
			fd_read(machine, fds);
			fd_write(machine, fds);
		}
	}
}

void server (int port)
{
	struct sockaddr_in server;
	int socket = getsocket();
	t_machine *machine = init_machine();

	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = INADDR_ANY;
	if (bind(socket, (const struct sockaddr *) &server,
		 sizeof(server)) == -1)
		exit_error("Bind failed\n", -1);
	if (listen(socket, 69) == -1)
		exit_error("Listen failed", 1);
	machine->host = inet_ntoa(server.sin_addr);
	machine->id = socket;
	machine->port = port;
	machine->type = SERVER;
	run_server(machine);
}
