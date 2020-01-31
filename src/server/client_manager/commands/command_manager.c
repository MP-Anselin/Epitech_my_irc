/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

void add_action (char *name, void (*action) (t_machine *, t_machine *, t_cmd *),
		 t_action **act)
{
	t_action *save = xmalloc(sizeof(t_cmd));
	t_action *tmp = *act;

	if (*act != NULL)
		for (; tmp->next; tmp = tmp->next);
	save->command = strdup(name);
	save->action = action;
	save->next = NULL;
	if (*act)
		tmp->next = save;
	else
		*act = save;
}

void fill_action (t_cmd *cmd)
{
	add_action("NICK", command_nickname, &cmd->act);
	add_action("JOIN", command_join, &cmd->act);
	add_action("PART", command_part, &cmd->act);
	add_action("USERS", command_users, &cmd->act);
	add_action("PRIVMSG", message_manager, &cmd->act);
	add_action("NAMES", command_names, &cmd->act);
	add_action("LIST", command_list, &cmd->act);
	add_action("USER", command_user, &cmd->act);
	add_action("INVITE", command_invite, &cmd->act);
}

t_cmd *init_cmd (char **tab)
{
	t_cmd *cmd = xmalloc(sizeof(t_cmd));
	size_t size = tablen(tab);
	size_t i = 0;

	if (size == 0)
		return (NULL);
	cmd->arg = xmalloc(sizeof(char *) * (size + 1));
	cmd->command = xstrdup(tab[0]);
	if (tablen(tab) == 1)
		cmd->arg[0] = NULL;
	else {
		for (int x = 1; tab[x]; i++, x++)
			cmd->arg[i] = xstrdup(tab[x]);
		cmd->arg[i] = NULL;
	}
	cmd->message = NULL;
	cmd->act = NULL;
	fill_action(cmd);
	return (cmd);
}

int run_right_cmd (t_machine *machine, t_machine *client, t_cmd *cmd,
		   t_action *tmp)
{
	int is_co = 0;

	if (cmd->command != NULL && strcmp(tmp->command, cmd->command) == 0) {
		is_co = is_connect(machine, client, cmd);
		if (is_co != -1 && tmp->action != NULL)
			tmp->action(machine, client, cmd);
		connect_ok(client);
		return (1);
	}
	return (0);
}

void command_manager (t_machine *machine, t_machine *client, char *msg)
{
	char **tab = the_strtowordtab(msg, ' ');
	t_cmd *cmd = init_cmd(tab);

	for (t_action *tmp = cmd->act; tmp != NULL; tmp = tmp->next) {
		if (run_right_cmd(machine, client, cmd, tmp) == 1) {
			free_tab(tab);
			return;
		}
	}
	if (client->channels == NULL)
		client->text = xstrdup("421 ERR_UNKNOWNCOMMAND\r\n");
	free_tab(tab);
}
