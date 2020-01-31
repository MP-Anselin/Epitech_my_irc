/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#ifndef SERVER_H
# define SERVER_H

# define NONE 0
# define SERVER 1
# define CLIENT 2
# define CONNECT 2

#include "common.h"

typedef struct s_cmd t_cmd;

typedef struct s_channel
{
	char *name;
	char *topic;
	char *pass;
	struct s_channel *next;
} t_channel;

typedef struct s_machine
{
	int id;
	int isco;
	int use_co;
	int nick_co;
	int port;
	int type;
	char *text;
	char *host;
	char *nick;
	char *user;
	char *mode;
	char *real_name;
	char *unused;
	t_channel *channels;
	struct s_machine *next;
} t_machine;

typedef struct s_action
{
	char *command;
	void (*action) (t_machine *, t_machine *, t_cmd *);
	struct s_action *next;
} t_action;

typedef struct s_cmd
{
	char *message;
	char *command;
	char **arg;
	t_action *act;
	struct s_cmd *next;
} t_cmd;

t_machine *init_machine ();
t_machine *find_client (t_machine *machine, int id);
void server (int port);
void reset_fd (t_fds *fds);
void fd_set_machine (t_machine *machine, t_fds *fds);
void fd_read (t_machine *machine, t_fds *fds);
void fd_write (t_machine *machine, t_fds *fds);
void add_client (t_machine *machine, int socket);
void client_read_message (t_machine *machine, t_machine *client);
void client_send_message (t_machine *client);
void fd_set_machine (t_machine *machine, t_fds *fds);
int select_client (t_fds *fds);
void command_manager (t_machine *machine, t_machine *client, char *msg);
void command_nickname (t_machine *machine, t_machine *client, t_cmd *cmd);
void command_join (t_machine *machine, t_machine *client, t_cmd *cmd);
int check_nbr_arg (char **arg, t_machine *client, char **tab, size_t nbr);
void command_part (t_machine *machine, t_machine *client, t_cmd *cmd);
void command_users (t_machine *machine, t_machine *client, t_cmd *cmd);
void command_user (t_machine *machine, t_machine *client, t_cmd *cmd);
void command_names (t_machine *machine, t_machine *client, t_cmd *cmd);
int check_use_channel (t_machine *client, char *channel);
int command_privmsg_user (t_machine *machine, t_machine *client, t_cmd *cmd);
int check_machine_channel (t_machine *client, char *channel);
void command_msg_channel (t_machine *machine, t_cmd *cmd, t_machine *client);
void command_list (t_machine *machine, t_machine *client, t_cmd *cmd);
char *fill_message (char **arg, int start);
void message_manager (t_machine *machine, t_machine *client, t_cmd *cmd);
char *msg_answer (char *sender, char *dest, char **arg, char *cmd);
int check_use_nickname (t_machine *machine, char *nickname);
void command_file_accept (t_machine *machine, t_machine *client, t_cmd *cmd);
t_machine *find_right_user (t_machine *machine, char *user);
void command_invite (t_machine *machine, t_machine *client, t_cmd *cmd);
char **msg_answer_error (char *first, char *second);
int check_nickname_char (char *str);
int check_channel_char (char *str);
int is_connect (t_machine *machine, t_machine *client, t_cmd *cmd);
void connect_ok ();
void catch_user_from_channel (t_machine *tmp, t_machine *client, char *channel,
			      char *code);
void destroy_list (t_channel **list_ptr);
t_channel *init_struct_channel ();
int check_double (t_channel **info, char *channel);
void free_tab (char **tab);
void welcome_other (t_machine *machine, char *channel, char *save, char *name);

#endif /* !SERVER_H */
