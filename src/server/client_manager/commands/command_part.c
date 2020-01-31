/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int channel_exists (t_machine *client, char *channel)
{
	for (t_channel *tmp = client->channels; tmp; tmp = tmp->next) {
		if (strcmp(tmp->name, channel) == 0) {
			return (1);
		}
	}
	return (0);
}

void delete_channel(t_machine *client, t_channel *tmp, char *channel)
{
	if (strcmp(tmp->name, channel) == 0) {
		free(tmp->name);
		client->channels = tmp->next;
		free(tmp);
	}
}

void leave_channel (t_machine *client, char *channel)
{
	for (t_channel *tmp = client->channels; tmp; tmp = tmp->next)
		delete_channel(client, tmp, channel);

}

void run_part_command (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	char *save = NULL;

	save = xmalloc(15 + strlen(client->nick) + strlen(cmd->command)
		       + strlen(cmd->arg[0]) + 1);
	sprintf(save, ":%s %s %s\r\n", client->nick, cmd->command, cmd->arg[0]);
	welcome_other(machine, cmd->arg[0], save, client->nick);
	leave_channel(client, cmd->arg[0]);
	printf("Client %s left channel %s\n", client->nick,
	       cmd->arg[0]);
	client->text = xstrdup(save);
	if (save)
		free(save);
}

void command_part (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	char **tab_error = msg_answer_error("461 ERR_TOOMUCHPARAMS\r\n",
					    "461 ERR_NEEDMOREPARAMS\r\n");

	if (check_nbr_arg(cmd->arg, client, tab_error, 1) == 1)
		return;
	else if (channel_exists(client, cmd->arg[0]) == 0) {
		client->text = xstrdup("403 ERR_NOSUCHCHANNEL\r\n");
		return;
	}
	(void) machine;
	if (check_use_channel(client, cmd->arg[0]) != 1)
		client->text = xstrdup("442 ERR_NOTONCHANNEL\r\n");
	else
		run_part_command(machine, client, cmd);
}
