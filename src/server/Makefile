##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	../../server

DIRCOMMON	=	../common

SRCSSERVER	=	main.c								\
			server.c							\
			fd_gestion/fd_set_machine.c					\
			fd_gestion/fd_read.c						\
			fd_gestion/fd_write.c						\
			fd_gestion/reset_fd.c						\
			client_manager/add_client.c					\
			client_manager/client_read_message.c				\
			client_manager/client_send_message.c				\
			client_manager/connection/is_connect.c				\
			client_manager/connection/connect_ok.c				\
			client_manager/commands/command_manager.c			\
			client_manager/commands/command_nickname.c			\
			client_manager/commands/command_join.c				\
			client_manager/commands/command_part.c				\
			client_manager/commands/command_users.c				\
			client_manager/commands/command_user.c				\
			client_manager/commands/command_names.c				\
			client_manager/commands/command_list.c				\
			client_manager/commands/command_invite.c			\
			client_manager/commands/error_arg.c				\
			client_manager/commands/message_manager/command_privmsg.c	\
			client_manager/commands/message_manager/command_msg_channel.c	\
			client_manager/commands/message_manager/fill_message.c		\
			client_manager/commands/message_manager/message_manager.c	\
			client_manager/commands/message_manager/msg_answer.c		\
			client_manager/commands/channel_function/channel_use.c		\
			client_manager/commands/channel_function/user_from_channel.c	\
			client_manager/commands/channel_function/init_struct_channel.c	\
			client_manager/commands/channel_function/check_double_name.c	\
			client_manager/commands/channel_function/delete_list.c		\
			client_manager/commands/channel_function/send_info_other.c		\
			basics_functions/find_client.c					\
			basics_functions/msg_answer_error.c				\
			basics_functions/init_machine_struct.c				\
			basics_functions/check_char.c


SRCSCOMMON	=	$(DIRCOMMON)/xfunctions/xmalloc.c	\
			$(DIRCOMMON)/xfunctions/xwrite.c	\
			$(DIRCOMMON)/xfunctions/xstrdup.c	\
			$(DIRCOMMON)/xfunctions/xstrcat.c	\
			$(DIRCOMMON)/xfunctions/xstrlen.c	\
			$(DIRCOMMON)/getsocket.c		\
			$(DIRCOMMON)/exit_error.c		\
			$(DIRCOMMON)/read_message.c		\
			$(DIRCOMMON)/strtowordtab.c		\
			$(DIRCOMMON)/select.c			\
			$(DIRCOMMON)/tablen.c			\
			$(DIRCOMMON)/free_tab.c

OBJSSERVER	=	$(SRCSSERVER:.c=.o)

OBJSCOMMON	=	$(SRCSCOMMON:.c=.o)

CC		=	gcc
CFLAGS		+=	-W -Wall -Werror -Wextra
CFLAGS		+=	-I ../../include -g

RM		=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJSSERVER) $(OBJSCOMMON)
			$(CC) $(OBJSSERVER) $(OBJSCOMMON) -o $(NAME)

clean:
			$(RM) $(OBJSSERVER)
			$(RM) $(OBJSCOMMON)

fclean:			clean
			$(RM) $(NAME)

re: fclean all
