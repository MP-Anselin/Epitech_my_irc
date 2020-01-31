/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int check_use_nickname (t_machine *machine, char *nickname)
{
	for (t_machine *tmp = machine; tmp; tmp = tmp->next) {
		if (tmp->type == CLIENT && tmp->nick != NULL)
			if (strcmp(tmp->nick, nickname) == 0)
				return (1);
	}
	return (0);
}

int check_arg_nickname (t_machine *client, char *name)
{
	if (check_nickname_char(name) == 1) {
		client->text = xstrdup("432 ERR_ERRONEUSNICKNAME\r\n");
		return (1);
	}
	return (0);
}

void nickname_answer (t_machine *client, char *nickname)
{
	printf("Client %s change name for '%s'\n", client->nick, nickname);
	if (client->text)
		free(client->text);
	client->text = xmalloc(xstrlen(nickname) + xstrlen(client->nick) + 17);
	if (client->nick)
		sprintf(client->text, ":%s NICK %s\r\n",
			client->nick, nickname);
	else
		sprintf(client->text, ":(null) NICK %s\r\n", nickname);
	if (client->nick)
		free(client->nick);
	client->nick = xstrdup(nickname);
	client->nick_co = 1;
}

void command_nickname (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	char **tab_error = msg_answer_error("432 ERR_ERRONEUSNICKNAME\r\n",
					    "431 ERR_NONICKNAMEGIVEN\r\n");

	if (check_nbr_arg(cmd->arg, client, tab_error, 1) == 1 ||
	    check_arg_nickname(client, cmd->arg[0]) == 1)
		return;
	else if (check_use_nickname(machine, cmd->arg[0]) == 1)
		client->text = xstrdup("433 ERR_NICKNAMEINUSE\r\n");
	else
		nickname_answer(client, cmd->arg[0]);
}
