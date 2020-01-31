/*
** EPITECH PROJECT, 2018
** commands
** File description:
** commands
*/

#include "client.h"

void join_command(t_client *client, char **commands)
{
	if (tab_len(commands) >= 1){
		if (strcmp(commands[0], "/join") == 0){
			join_command_bis(client, commands);
		}
	}
}

void nick_command(t_client *client, char **commands)
{
	if (tab_len(commands) >= 1){
		if (strcmp(commands[0], "/nick") == 0){
			if (tab_len(commands) >= 2){
				client->nickname = xstrdup(commands[1]);
			}
		}
	}
}


void handle_command_bis(t_client *client, char *command)
{	
	translate(g_tradco, &command);
	if (command){
		command = xstrcat(command, "\r\n");
		if (strlen(client->nickname)){
			command = xstrcat(" ", command);
			command = xstrcat(client->nickname,command);
			command = xstrcat(":", command);
		}
		write(client->sock, command, strlen(command) + 1);
	}
}

void handle_command(t_client *client, char *command)
{
	char **commands;

	commands = str_to_tab(command, " ");
	server_command(client, commands);
	if (client->connected == 0)
		return ;
	join_command(client, commands);
	nick_command(client, commands);
	if (client->connected){
		only_message(client, &command);
		if (command){
			handle_command_bis(client, command);
		}
	}
}

void handle_commands(t_client *client)
{
	char **commands = str_to_tab(client->msg_client, "\n");
	int i = 0;

	while (i < tab_len(commands)){
		handle_command(client, commands[i]);
		i++;
	}
	client->msg_client = NULL;
}
