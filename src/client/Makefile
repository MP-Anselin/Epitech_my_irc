##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	../../client

DIRCOMMON	=	../common

SRCSCLIENT	=	main.c					\
			commands.c				\
			client.c				\
			global.c				\
			getfile.c				\
			basics_functions/init_struct_client.c	\
			basics_functions/str_to_tab.c		\
			basics_functions/str_replace.c		\
			set_fds.c				\
			client_actions/client_reads_info.c	\
			client_actions/client_writes_info.c

SRCSCOMMON	=	$(DIRCOMMON)/xfunctions/xmalloc.c	\
			$(DIRCOMMON)/xfunctions/xwrite.c	\
			$(DIRCOMMON)/xfunctions/xstrdup.c	\
			$(DIRCOMMON)/getsocket.c		\
			$(DIRCOMMON)/exit_error.c		\
			$(DIRCOMMON)/read_message.c		\
			$(DIRCOMMON)/strtowordtab.c		\
			$(DIRCOMMON)/select.c			\
			$(DIRCOMMON)/xfunctions/xstrcat.c

OBJSCLIENT	=	$(SRCSCLIENT:.c=.o)

OBJSCOMMON	=	$(SRCSCOMMON:.c=.o)

CC		=	gcc
CFLAGS		+=	-W -Wall -Werror -Wextra
CFLAGS		+=	-I ../../include -g

RM		=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJSCLIENT) $(OBJSCOMMON)
			$(CC) $(OBJSCLIENT) $(OBJSCOMMON) -o $(NAME)

clean:
			$(RM) $(OBJSCLIENT)
			$(RM) $(OBJSCOMMON)

fclean:			clean
			$(RM) $(NAME)

re: fclean all
