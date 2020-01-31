/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "client.h"

void client_writes_info (t_fds *fds, t_client *client)
{
	if (FD_ISSET(1, &fds->write)) {
		if (client->msg_server != NULL) {
			write(1, client->msg_server,
			      strlen(client->msg_server) + 1);
			write(1, "\n", 1);
			free(client->msg_server);
			client->msg_server = NULL;
		}
	}
	if (FD_ISSET(client->sock, &fds->write)) {
		if (client->msg_client != NULL) {
			write(client->sock, client->msg_client,
			      strlen(client->msg_client) + 1);
			free(client->msg_client);
			client->msg_client = NULL;
		}
	}
}

void only_message(t_client *client, char **str_ptr)
{
        int size = 0;
        char *new_str = NULL;

        if ((*str_ptr)[0] != '/'){
                if (client->last_chanel){
                        size = strlen("PRIVMSG  ") + 1 +
                                strlen(client->last_chanel) +
                                strlen(*str_ptr);
                        new_str = xmalloc(sizeof(char) * size);
                        sprintf(new_str, "PRIVMSG %s %s",
                                client->last_chanel, (*str_ptr));
                        free(*str_ptr);
                        *str_ptr = new_str;
                } else {
                        client->msg_server = xstrcat(client->msg_server,
                                      "You're not connected to any channel yet\n");
                }
        }
}

void translate(t_trad *trad, char **str_ptr)
{
        int i = 0;
        char *new = str_replace(*str_ptr, " ", " ");
        char *tmp;

        while (trad[i].command){
                tmp = new;
                new = str_replace(new, trad[i].command, trad[i].message);
                free(tmp);
                i++;
        }
        *str_ptr = new;
}

void join_command_bis(t_client *client, char **commands)
{
        if (tab_len(commands) >= 2){
                if (client->last_chanel &&
                    strcmp(client->last_chanel, commands[1]) == 0)
                        return ;
                client->last_chanel = strdup(commands[1]);
                client->msg_server = xstrcat(client->msg_server,
                                        "[green]You have joined the channel ");
                client->msg_server = xstrcat(client->msg_server,
                                             client->last_chanel);
                client->msg_server = xstrcat(client->msg_server, "[end]\n");

                client->msg_server = xstrcat(client->msg_server, "[info]");
                client->msg_server = xstrcat(client->msg_server,
                                             "enter_channel:");
                client->msg_server = xstrcat(client->msg_server,
                                             client->last_chanel);
		client->msg_server = xstrcat(client->msg_server, "\n");
	}
}
