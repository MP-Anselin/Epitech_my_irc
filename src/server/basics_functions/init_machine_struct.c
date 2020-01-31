/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "server.h"

t_machine *init_machine ()
{
	t_machine *machine = xmalloc(sizeof(t_machine));

	machine->id = 0;
	machine->type = NONE;
	machine->port = 0;
	machine->isco = 0;
	machine->use_co = 0;
	machine->nick_co = 0;
	machine->nick = NULL;
	machine->mode = NULL;
	machine->real_name = NULL;
	machine->unused = NULL;
	machine->text = NULL;
	machine->user = NULL;
	machine->host = NULL;
	machine->channels = NULL;
	machine->next = NULL;
	return (machine);
}