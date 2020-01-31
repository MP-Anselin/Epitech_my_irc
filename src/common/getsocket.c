/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

int getsocket ()
{
	struct protoent *proto;
	int sock;

	proto = getprotobyname("TCP");
	if (!proto)
		exit_error("Cannot have protocole\n", 1);
	sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
		exit_error("Cannot create socket\n", 1);
	return (sock);
}