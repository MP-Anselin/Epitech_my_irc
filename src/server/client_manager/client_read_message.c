/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

t_machine *kick_out_client(t_machine *machine, t_machine *client, char *message)
{
	int id = client->id;

	close(client->id);
	if (client->nick != NULL)
		free(client->nick);
	if (client->channels != NULL)
		free(client->channels);
	for (t_machine *tmp = machine; tmp; tmp = tmp->next){
		if (tmp->next != NULL && tmp->next == client) {
			tmp->next = client->next;
			free(client);
			printf("The client %d has left.\n", id);
			return (tmp->next);
		}
	}
	if (message != NULL)
		free(message);
	printf("The client %d has left\n", id);
	return (NULL);
}

char *cut_msg(int id)
{
	char *stock = read_message(id);
	char *message = NULL;
	int i = 0;
	int x = 0;

	if (!stock)
		return (NULL);
	if (stock[0] == ':')
		for (; stock[i] != ' ' && stock[i]; i++);
	else
		return (stock);
	i++;
	message = xmalloc(xstrlen(stock) - i);
	for (; stock[i]; i++, x++)
		message[x] = stock[i];
	message[x] = '\0';
	free(stock);
	return (message);
}

void client_read_message(t_machine *machine, t_machine *client)
{
	char *message = cut_msg(client->id);

	if (message == NULL)
		return;
	printf("\t\t\t MSG recu ->>> '%s'\n", message);
	if (message != NULL && strcmp(message, "QUIT :quit") == 0)
		kick_out_client(machine, client, message);
	else if (message != NULL)
		command_manager(machine, client, message);
}
