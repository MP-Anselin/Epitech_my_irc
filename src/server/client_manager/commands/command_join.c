/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void add_rpl_name (t_machine *machine, t_machine *client, t_cmd *cmd,
		   char **save)
{
	char *save_bis = NULL;
	char *stock = xmalloc(xstrlen(cmd->arg[0]) + 27);

	save_bis = client->text;
	client->text = cmd->arg[1] ? xstrcat(client->text, cmd->arg[1])
				   : xstrcat(client->text, "No topic is "
			"set\r\n");
	free(save_bis);
	save_bis = client->text;
	client->text = xstrcat(client->text, *save);
	free(save_bis);
	sprintf(stock, "353 %s :", cmd->arg[0]);
	for (t_machine *tmp = machine; tmp; tmp = tmp->next)
		catch_user_from_channel(tmp, client, cmd->arg[0], stock);
	sprintf(stock, "366 %s :End of NAMES list\r\n", cmd->arg[0]);
	save_bis = client->text;
	client->text = xstrcat(client->text, stock);
	free(stock);
	free(save_bis);
}

void create_join_answer (t_machine *machine, t_machine *client, t_cmd *cmd,
			 char **save)
{
	char *save_bis = NULL;

	if (client->text)
		free(client->text);
	client->text = cmd->arg[1] ? xstrdup("332 ") : NULL;
	save_bis = client->text;
	client->text = !cmd->arg[1] ? xstrdup("331 ") : xstrdup(
		client->text);
	free(save_bis);
	*save = xmalloc(15 + strlen(client->nick) + strlen(cmd->command) +
			strlen(cmd->arg[0]) + 1);
	sprintf(*save, ":%s %s %s\r\n", client->nick, cmd->command,
		cmd->arg[0]);
	save_bis = client->text;
	client->text = xstrcat(client->text, cmd->arg[0]);
	free(save_bis);
	save_bis = client->text;
	client->text = xstrcat(client->text, " :");
	free(save_bis);
	add_rpl_name(machine, client, cmd, save);
}

void go_to_channel (t_machine *client, char **arg)
{
	t_channel *tmp;
	t_channel *add = xmalloc(sizeof(t_channel));

	add->name = xstrdup(arg[0]);
	add->topic = arg[1] ? xstrdup(arg[1]) : NULL;
	add->next = NULL;
	tmp = client->channels;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = add;
	else
		client->channels = add;

}

void command_join (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	char *save = NULL;
	char **tab_error = msg_answer_error("461 ERR_TOOMUCHPARAMS\r\n",
					    "461 ERR_NEEDMOREPARAMS\r\n");

	if (check_nbr_arg(cmd->arg, client, tab_error, 1) == 1)
		return;
	(void) machine;
	if (check_channel_char(cmd->arg[0]) == 1)
		client->text = xstrdup("403 ERR_NOSUCHCHANNEL\r\n");
	else if (check_use_channel(client, cmd->arg[0]) == 0) {
		go_to_channel(client, cmd->arg);
		create_join_answer(machine, client, cmd, &save);
		welcome_other(machine, cmd->arg[0], save, client->nick);
		printf("Client %s entered in channel %s\n", client->nick,
		       cmd->arg[0]);
		if (save)
			free(save);
	}
}
