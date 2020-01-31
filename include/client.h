/*
** EPITECH PROJECT, 2018
** PSU
** File description:
* Created by MP,
*/

#ifndef CLIENT_H
# define CLIENT_H

#include <string.h>
#include "common.h"

//int get_socket();
void client ();

typedef struct s_client
{
	int sock;
	struct sockaddr_in server;
	char *nickname;
	char *last_chanel;
	char *msg_client;
	char *msg_server;
	int target;
	int connected;
} t_client;

void handle_client(t_client *client, t_fds *fds);

typedef struct s_trad
{
	char *command;
	char *message;
} t_trad;

int connect_server(t_client *client, char *host, int port);

typedef struct s_fd_list
{
	int _fd_write;
	int _fd_read;
	struct s_fd_list *_next;
	char *_buff_read;
} t_fd_list;

/*
** commands.c
*/

void server_command(t_client *client, char **commands);
void handle_commands(t_client *client);
void translate(t_trad *trad, char **str_ptr);
void translate_commands(t_client *trad, char **str_ptr);

/*
** str_to_tab.c
*/

char **str_to_tab(char *str, char *op);
void print_tab(char **tab);
int tab_len(char **tab);
void free_tab(char **tab);


void init_struct_client(t_client *thi);

void set_fds(t_fds *fds, int socket);
void client_reads_info(t_fds *fds, t_client *client);
void client_writes_info(t_fds *fds, t_client *client);

/*
** str_replace
*/

char *str_replace(char *str, char *replace, char *subject);

/*
** getfile.c
*/

char *get_file(const char *name);


void connection_sucess(t_client *client);
void server_command_bis(t_client *client, char **commands);
void server_command(t_client *client, char **commands);
void only_message(t_client *client, char **str_ptr);
void translate(t_trad *trad, char **str_ptr);
void join_command_bis(t_client *client, char **commands);
void join_command(t_client *client, char **commands);
void nick_command(t_client *client, char **commands);
void handle_command_bis(t_client *client, char *command);
void handle_command(t_client *client, char *command);
void handle_commands(t_client *client);

extern t_trad g_tradco[20];
extern t_trad g_error_msgs[40];

#endif /* !PSU_CLIENT_H */

