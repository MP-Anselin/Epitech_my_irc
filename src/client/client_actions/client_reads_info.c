/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "client.h"

void print_answer(t_client *client)
{
	if (client->msg_server)
		printf("%s\n", client->msg_server);
}

void client_reads_info(t_fds *fds, t_client *client)
{
	if (FD_ISSET(0, &fds->read))
		client->msg_client = read_message(0);
	if (client->connected)
	{
		if (FD_ISSET(client->sock, &fds->read)) {
			client->msg_server = read_message(client->sock);
			print_answer(client);
		}
	}
}

void connection_sucess(t_client *client)
{
        client->connected = 1;
        client->last_chanel = NULL;
	client->msg_server = xstrcat(client->msg_server,
                                     "[green]Conection done[end]\n");
	client->msg_server = xstrcat(client->msg_server,
 	                             "[info][connect_server]");
}

void server_command_bis(t_client *client, char **commands)
{
        char *host = NULL;
        int port = 4242;
        char **args;

        if (tab_len(commands) >= 2){
                args = str_to_tab(commands[1], ":");
                host = args[0];
                if (tab_len(args) >= 2){
                        port = atoi(args[1]);
                }
                if (connect_server(client, host, port) != -1){
                        connection_sucess(client);
                }
                else
                        client->msg_server = xstrcat(client->msg_server,
                                                     "[red]Conection  failed[end]\n");
        }  else
                client->msg_server = xstrcat(client->msg_server,
                                             "Usage host[:port]\n");
}

void server_command(t_client *client, char **commands)
{
        if (tab_len(commands) >= 1){
                if (strcmp(commands[0], "/server") == 0){
			server_command_bis(client, commands);
                }
        }
}
