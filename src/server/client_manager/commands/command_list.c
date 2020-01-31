/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

int catch_spc_channel (t_machine *client_bis, t_machine *client, char *chan,
		       t_channel **stock_name)
{

	for (t_channel *tmp = client_bis->channels; tmp; tmp = tmp->next) {
		if (strstr(tmp->name, chan) && !check_double(stock_name,
							     tmp->name)) {
			client->text = xstrcat(client->text, "322 RPL_LIST ");
			client->text = xstrcat(client->text, tmp->name);
			client->text = xstrcat(client->text, "\r\n");
		}
	}
	return (1);
}

int catch_all_channel (t_machine *client_bis, t_machine *client,
		       t_channel **stock_name)
{
	char *save;

	for (t_channel *tmp = client_bis->channels; tmp; tmp = tmp->next) {
		if (!check_double(stock_name, tmp->name)) {
			save = client->text;
			client->text = xstrcat(client->text, "322 RPL_LIST ");
			free(save);
			save = client->text;
			client->text = xstrcat(client->text, tmp->name);
			free(save);
			save = client->text;
			client->text = xstrcat(client->text, "\r\n");
			free(save);
		}
	}
	return (0);
}

void
run_list_command (t_machine *machine, t_machine *client, t_cmd *cmd, int var)
{
	t_channel *names = NULL;
	char *save;

	if (client->text != NULL)
		free(client->text);
	client->text = xstrdup("321 RPL_LISTSTART\r\n");
	for (t_machine *tmp = machine; tmp; tmp = tmp->next) {
		var = var == 0 ? catch_all_channel(tmp, client, &names)
			       : var;
		var = var == 1 ? catch_spc_channel
			(tmp, client, cmd->arg[0], &names) : var;
	}
	save = client->text;
	client->text = xstrcat(client->text,
			       "323 RPL_LISTEND :End of /LIST\r\n");
	free(save);
	destroy_list(&names);
}

void command_list (t_machine *machine, t_machine *client, t_cmd *cmd)
{
	int var = tablen(cmd->arg);

	if (var > 1) {
		client->text = xstrdup("461 ERR_TOOMUCHPARAMS\r\n");
		return;
	}
	else if (var == 0 || var == 1)
		run_list_command(machine, client, cmd, var);
}
