/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#ifndef PSU_COMMON_H
# define PSU_COMMON_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>

typedef struct		s_fds
{
	fd_set		read;
	fd_set		write;
	int		nbr;
}			t_fds;

int select_client(t_fds *fds);
size_t tablen(char **tab);
void exit_error(char *msg, int nbr);
void *xmalloc(int size);
int getsocket ();
char *read_message (int fd);
char *xstrdup(char *str);
void xwrite (char *text, int nbr);
char **the_strtowordtab (char *str, char c);
char *read_message (int fd);
char *xstrcat (char *dest, char *src);
int xstrlen(char *str);
void free_tab(char **tab);

#endif /* !PSU_COMMON_H */
