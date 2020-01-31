/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void answer_names_bis (t_machine *machine, t_machine *client, char *channel)
{
	char *save = xmalloc(xstrlen(channel) + 25);

	if (channel)
		sprintf(save, "353 RPL_NAMREPLY %s :", channel);
	for (t_machine *tmp = machine; tmp; tmp = tmp->next)
		catch_user_from_channel(tmp, client, channel, save);
}

void run_channels_names (t_machine *machine, t_machine *client)
{
	t_channel *names = init_struct_channel();

	for (t_machine *tmp = machine; tmp; tmp = tmp->next) {
		for (t_channel *tmp_bis = tmp->channels; tmp_bis;
		     tmp_bis = tmp_bis->next) {
			check_double(&names, tmp_bis->name);
		}
	}
	for (t_channel *tmp_bis = names; tmp_bis; tmp_bis = tmp_bis->next) {
		if (tmp_bis->name)
			answer_names_bis(machine, client, tmp_bis->name);
	}
	client->text = xstrcat(client->text, "366 RPL_ENDOFNAMES "
		":End of /NAMES list\r\n");
}

void answer_names (t_machine *machine, t_machine *client, char *channel)
{
	char *save = NULL;
	char *stock = xmalloc(xstrlen(channel) + 27);

	sprintf(stock, "353 %s :", channel);
	for (t_machine *tmp = machine; tmp; tmp = tmp->next)
		catch_user_from_channel(tmp, client, channel, stock);
	save = client->text;
	sprintf(stock, "366 %s :End of /NAMES list\r\n", channel);
	client->text = xstrcat(client->text, stock);
	free(save);
	free(stock);
}

void command_names_channel(t_machine *client, t_cmd *cmd)
{
	char *save = client->text;

	client->text = xstrcat(client->text,
			       "\r\n366 RPL_ENDOFNAMES\r\n");
	if (save)
		free(save);
	save = client->text;
	client->text = xstrcat(client->text, cmd->arg[0]);
	free(save);
	save = client->text;
	client->text = xstrcat(client->text,
			       " :End of /NAMES list\r\n");
	free(save);
}

void command_names (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	char **tab_error = msg_answer_error("\"432 ERR_ERRONEUSCHANNEL\r\n",
					    "431 ERR_NOCHANNELGIVE\r\n");

	if (tablen(cmd->arg) == 0)
		return (run_channels_names(machine, client));
	(void) machine;
	if (check_nbr_arg(cmd->arg, client, tab_error, 1) == 1)
		return;
	else if (check_machine_channel(machine, cmd->arg[0]) != 1)
		command_names_channel(client, cmd);
	else
		answer_names(machine, client, cmd->arg[0]);
}
