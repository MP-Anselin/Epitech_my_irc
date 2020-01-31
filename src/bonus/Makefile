##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Basic Makefile
##

DIRCOMMON	=	../common
DIRCLIENT	=	../client

SRC		= 	main.cpp \
			MyircTimer.cpp \
			Tools.cpp \
			QWidget/Myirc.cpp \
			QWidget/Myirc/Chatpage.cpp \
			QWidget/Myirc/Chatpage/Buttonirc.cpp \
			QWidget/Myirc/Chatpage/Config.cpp

OBJ		=	 $(SRC:.cpp=.o)

SRCSCOMMON      =       $(DIRCOMMON)/xfunctions/xmalloc.c       \
                        $(DIRCOMMON)/xfunctions/xwrite.c        \
                        $(DIRCOMMON)/xfunctions/xstrdup.c       \
			$(DIRCOMMON)/getsocket.c                \
                        $(DIRCOMMON)/exit_error.c               \
			$(DIRCOMMON)/read_message.c             \
                        $(DIRCOMMON)/strtowordtab.c             \
			$(DIRCOMMON)/select.c			\
			$(DIRCOMMON)/xfunctions/xstrcat.c

OBJCOMMON	=	 $(SRCSCOMMON:.c=.o)

SRCSCLIENT      =	$(DIRCLIENT)/commands.c                              \
			$(DIRCLIENT)/client.c                                \
                        $(DIRCLIENT)/global.c                                \
                        $(DIRCLIENT)/getfile.c                               \
                        $(DIRCLIENT)/basics_functions/init_struct_client.c   \
			$(DIRCLIENT)/basics_functions/str_to_tab.c           \
                        $(DIRCLIENT)/basics_functions/str_replace.c          \
			$(DIRCLIENT)/set_fds.c                               \
			$(DIRCLIENT)/client_actions/client_reads_info.c      \
                        $(DIRCLIENT)/client_actions/client_writes_info.c

OBJSCLIENT      =       $(SRCSCLIENT:.c=.o)

NAME            =       ../../interface_client

CFLAGS          +=      -W -Wall -Werror -Wextra
CFLAGS          +=      -I ../../include -g

CXXFLAGS  	= 	-W -Wall -Werror -Wextra -lqt -lQtCore
CXXFLAGS  	+=      -I ../../include -g

all:	$(NAME)

save_git:
	cp $(SRC_ON_GIT) $(GIT_DIR)

$(NAME):	$(OBJ) $(OBJCOMMON) $(OBJSCLIENT)
	g++ -o $(NAME) $(OBJ) $(OBJCOMMON) $(OBJSCLIENT) -lQtGui -lQtCore
clean:
	rm -f $(OBJ) $(OBJCOMMON) $(OBJSCLIENT)
fclean:		clean
	rm -f $(NAME)
re:	fclean all
author:
	echo $(USER) > author
