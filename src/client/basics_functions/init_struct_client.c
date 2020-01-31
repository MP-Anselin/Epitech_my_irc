/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "client.h"

void init_struct_client(t_client *machine)
{
	machine->nickname = xstrdup("");
	machine->msg_client = NULL;
	machine->msg_server = NULL;
	machine->target = 0;
	machine->sock = getsocket();
	machine->connected = 0;
	machine->last_chanel = NULL;
}
